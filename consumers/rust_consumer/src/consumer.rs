pub mod consumer {

    use rdkafka::consumer::{Consumer, StreamConsumer};
    use rdkafka::config::ClientConfig;
    use futures::stream::StreamExt;
    use rdkafka::Message;

    pub async fn consume_messages() {
        let consumer: StreamConsumer = ClientConfig::new()
            .set("bootstrap.servers", ":9092")
            .set("group.id", "my_consumer_group")
            .create()
            .expect("Consumer creation failed");

        consumer.subscribe(&["event"]).expect("Subscribe to topic failed");

        let mut message_stream = consumer.stream();

        while let Some(message) = message_stream.next().await {
            match message {
                Ok(msg) => {
                    let payload = msg.payload().unwrap();
                    println!("Received message: {:?}", std::str::from_utf8(payload).unwrap());
                }
                Err(e) => {
                    eprintln!("Error: {:?}", e);
                }
            }
        }
    }

}