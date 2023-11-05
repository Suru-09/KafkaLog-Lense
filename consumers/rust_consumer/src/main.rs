mod consumer;
mod uid_generator;
mod LogMessage;
mod es_wrapper;

use crate::consumer::consumer::consume_messages;
use crate::uid_generator::init_uid;

#[tokio::main]
async fn main() {
   match init_uid() {
       Ok(uid_str) => println!("{}", uid_str),
       Err(e) => println!("Error initializing UID: {}", e)
   }
   consume_messages().await;
}