pub mod consumer {

    extern crate chrono;

    use chrono::prelude::*;
    use std::time::{Duration, SystemTime};
    use rdkafka::consumer::{Consumer, StreamConsumer};
    use rdkafka::config::ClientConfig;
    use futures::stream::StreamExt;
    use rdkafka::Message;
    use crate::LogMessage::LogMessage;
    use chrono::LocalResult;

    fn unix_timestamp_to_datetime(unix_timestamp: i64) -> String {
        let duration = Duration::from_secs(unix_timestamp as u64);
        let system_time = SystemTime::UNIX_EPOCH + duration;
    
        match system_time.duration_since(SystemTime::UNIX_EPOCH) {
            Ok(time) => {
                let datetime = time.as_secs();
                let local_datetime = match Local.timestamp_opt(datetime as i64, 0) {
                    LocalResult::Single(datetime) => datetime,
                    LocalResult::Ambiguous(datetime, _) => datetime,
                    LocalResult::None => Local::now(),
                };
                local_datetime.format("%Y-%m-%d %H:%M:%S").to_string()
            }
            Err(_) => "Invalid Unix Timestamp".to_string(),
        }
    }

    pub async fn consume_messages() {
        let consumer: StreamConsumer = ClientConfig::new()
            .set("bootstrap.servers", "192.168.1.186:9094")
            .set("group.id", "my_consumer_group")
            .create()
            .expect("Consumer creation failed");
        
        consumer.subscribe(&["event"]).expect("Subscribe to topic failed");

        let mut message_stream = consumer.stream();

        while let Some(message) = message_stream.next().await {
            match message {
                Ok(msg) => {
                    let payload = match msg.payload() {
                        None => {
                            println!("No payload found");
                            continue
                        },
                        Some(payload) => payload
                    };
                    
                    let log_message: LogMessage = match protobuf::Message::parse_from_bytes(&payload) {
                        Ok(log_message) => log_message,
                        Err(e) => {
                            println!("Could not parse protobuf object: {:?}", e);
                            continue
                        }
                    };

                    let timestamp = unix_timestamp_to_datetime(log_message.get_timestamp().get_seconds());
                    println!("Received message: {:?}, {:?}, {:?}", timestamp, log_message.get_log_level(), log_message.get_message());
                }
                Err(e) => {
                    println!("Error: {:?}", e);
                }
            }
        }
    }

}