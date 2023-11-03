use std::path::PathBuf;
use std::fs;

fn main() {
    let out_dir = PathBuf::from("src");

    // if protos folder doesn't exist, create it
    let protos_dir = PathBuf::from("src/protos");
    if !protos_dir.exists() {
        fs::create_dir(&protos_dir).expect("Failed to create protos directory");
    }

    // always sync the proto files before building
    let internal_proto = PathBuf::from("src/protos/LogMessage.proto");
    let external_proto = PathBuf::from("../../proto/LogMessage.proto");
   
   fs::copy(&external_proto, &internal_proto).expect("Failed to copy proto file");
    
    protoc_rust::Codegen::new()
        .out_dir(&out_dir)
        .input(&internal_proto)
        .run()
        .expect("protobuf compilation failed");

    println!("Protocol Buffers code generated successfully!");
}