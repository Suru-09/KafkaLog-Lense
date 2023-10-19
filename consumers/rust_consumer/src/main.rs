mod consumer;

use crate::consumer::consumer::consume_messages;

#[tokio::main]
async fn main() {
   consume_messages().await;
}