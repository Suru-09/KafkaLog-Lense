#!/bin/bash

# create the generated directory if it doesn't exist
mkdir -p ../producers/cpp/generated

if [ $? -ne 0 ]; then
    echo "Error: Failed to create generated directory"
    exit 1
fi

echo "Building C++ classes from protobuf"
protoc --proto_path=../proto --cpp_out=../producers/cpp/generated/ LogMessage.proto

# Check the exit status of the protoc command
if [ $? -ne 0 ]; then
    echo "Warning: Failed to generate C++ classes from protobuf"
else
    echo "C++ classes from protobuf have been generated"
fi