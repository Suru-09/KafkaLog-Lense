pub mod uitls {

    use rand::Rng;
    use protobuf::ProtobufEnum;
    use std::borrow::Borrow;
    use protobuf::well_known_types::Timestamp;

    use crate::LogMessage::{LogMessage, LogLevel, ApplicationLanguage};
    use crate::uid_generator::init_uid;
    use crate::producer::producer::KafkaProducer;

    fn random_number() -> i32 {
        rand::thread_rng().gen_range(0..5)
    }

    pub async fn produce_messages() {
        let uid = init_uid();
        if uid.is_err() {
            panic!("Failed to initialize UID");
        }

        let uid_str = uid.unwrap();
        let message: String = "This is a test message".to_string();
        let app_lang = ApplicationLanguage::RUST;

        let producer = KafkaProducer::new();
        loop {
            let log_level = LogLevel::from_i32(random_number()).unwrap();

            let mut timestamp = Timestamp::new();
            let epoch_time = std::time::SystemTime::now().duration_since(std::time::UNIX_EPOCH).unwrap().as_secs().try_into().unwrap();
            timestamp.set_seconds(epoch_time);
            timestamp.set_nanos(0);
            
            let mut log_message = LogMessage::new();
            log_message.set_uid(uid_str.clone());
            log_message.set_timestamp(timestamp);
            log_message.set_log_level(*log_level.borrow());
            log_message.set_message(message.clone());
            log_message.set_app_lang(app_lang.clone());

            producer.produce("event", &log_message).await;
            std::thread::sleep(std::time::Duration::from_secs(3));
        }
    }
}