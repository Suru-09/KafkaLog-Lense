use sha256::digest;
use rand::{distributions::Alphanumeric, Rng};
use serde_json::json;
use std::io::Error;
use std::result::Result;
use std::io::Write;

fn generate_random_string(length: usize) -> String {
    rand::thread_rng()
        .sample_iter(&Alphanumeric)
        .take(length)
        .map(char::from)
        .collect()
}


fn generate_uid() -> String {
    let timestamp = chrono::Utc::now().timestamp();
    let mut uid = String::new();
    uid.push_str(&timestamp.to_string());
    uid.push_str(&generate_random_string(32));

    digest(uid.as_bytes())
}

fn write_uid_to_file(uid: &str) -> Result<(), Error> {
    let file = std::fs::File::create("uid.json");
    match file {
        Ok(mut f) => {
            let json = json!({ "uid": uid });
            let bytes = serde_json::to_vec(&json).unwrap();
            f.write_all(&bytes)
        }
        Err(e) => Err(e),
    }
}

fn read_uid_from_json() -> Result<String, Error> {
    let file = std::fs::File::open("uid.json");
    match file {
        Ok(f) => {
            let reader = std::io::BufReader::new(f);
            let json: serde_json::Value = serde_json::from_reader(reader).unwrap();
            let uid = json["uid"].as_str().unwrap();
            Ok(uid.to_string())
        }
        Err(e) => Err(e),
    }
}

pub fn init_uid() -> Result<String, Error> {
    if read_uid_from_json().is_ok() {
        read_uid_from_json()
    } 
    else {
        let uid = generate_uid();
        match write_uid_to_file(&uid) {
            Ok(_) => Ok(uid),
            Err(e) => Err(e),
        }
    } 
}