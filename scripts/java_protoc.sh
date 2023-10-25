#!/bin/bash

echo "Building Java classes from protobuf"
protoc --proto_path=../../proto --java_out=./src/main/java LogMessage.proto

# Check the exit status of the protoc command
if [ $? -ne 0 ]; then
    echo "Warning: Failed to generate Java classes from protobuf"
else
    echo "Java classes from protobuf have been generated"
fi
