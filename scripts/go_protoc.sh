#!/bin/bash

mkdir -p ../producers/go/main/protobuf

if [ $? -ne 0 ]; then
    echo "Error: Failed to create generated directory"
    exit 1
fi

echo "Building Go file from protobuf"
protoc --proto_path=../proto --go_out=../producers/go/main/protobuf LogMessage.proto

# Check the exit status of the protoc command
if [ $? -ne 0 ]; then
    echo "Warning: Failed to generate Go file from protobuf"
else
    echo "Go file from protobuf has been generated"
fi