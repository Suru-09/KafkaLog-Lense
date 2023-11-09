pub mod producer {

    extern crate chrono;
    use protobuf::Message;

    use rdkafka::producer::{BaseProducer, BaseRecord};
    use rdkafka::config::ClientConfig;
    use crate::LogMessage::LogMessage;

    pub struct KafkaProducer {
        producer: BaseProducer,
    }

    impl KafkaProducer {
        pub fn new() -> KafkaProducer {
            let producer_loco: BaseProducer = ClientConfig::new()
                .set("bootstrap.servers", "192.168.1.186:9094")
                .set("message.timeout.ms", "5000")
                .create()
                .expect("Producer creation error");

            Self {
                producer: producer_loco
            }
        }

        pub async fn produce(&self, topic: &str, log_message: &LogMessage) {
            let buf = log_message.write_to_bytes().unwrap();

            let record = BaseRecord::to(topic)
                .payload(&buf)
                .key("");

            match self.producer.send(record) {
                Ok(_) => println!("Sent message: {:?}", log_message),
                Err(e) => println!("Error while sending message: {:?}", e),
            }
        }
    }

}