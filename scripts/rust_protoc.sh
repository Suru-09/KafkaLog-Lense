#!/bin/bash

echo "Building Rust classes from protobuf"
protoc --proto_path=../proto --rust_out=../consumers/rust_consumer/src/ LogMessage.proto

# Check the exit status of the protoc command
if [ $? -ne 0 ]; then
    echo "Warning: Failed to generate Rust classes from protobuf"
else
    echo "Rust classes from protobuf have been generated"
fi