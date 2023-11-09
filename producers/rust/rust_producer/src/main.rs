pub mod producer;
pub mod uid_generator;
pub mod LogMessage;
pub mod utils;

use utils::uitls::produce_messages;

#[tokio::main]
async fn main() {
    produce_messages().await;
}
