pub mod es_wrapper {

    use crate::LogMessage::LogMessage;
    use elasticsearch::{Elasticsearch, Error, http::transport::Transport, IndexParts};
    use serde_json::{Value, json};

    pub struct ESWrapper {
        client: Elasticsearch,
    }

    impl ESWrapper {
        pub fn new() -> ESWrapper {
            let transport = Transport::single_node("http://192.168.1.186:9200")
                .expect("Failed to create transport");
            let client = Elasticsearch::new(transport);
            ESWrapper { client }
        }

        pub async fn index_log_message(&self, log_message: LogMessage) -> Result<(), Error> {
            let log_data = serialize_log_message(log_message);
            let response = self.client.index(IndexParts::Index("log_message"))
                .body(log_data)
                .send()
                .await?;
            println!("Response: {:?}", response);
            Ok(())
        }
    }


    fn serialize_log_message(log_message: LogMessage) -> Value {
        let log_data: Value = json!({
            "timestamp": log_message.get_timestamp().get_seconds(),
            "log_level": log_message.log_level as i32,
            "message": log_message.message,
            "app_lang": log_message.app_lang as i32,
            "uid": log_message.uid,
        });
        log_data
    }

}