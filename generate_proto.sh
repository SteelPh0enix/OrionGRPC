#!/bin/sh

mkdir ./RemoteClient/proto
mkdir ./OrionServer/proto
mkdir ./OrionServerCPP/proto

python3 -m grpc_tools.protoc -I./Protocols --python_out=./OrionServer/proto --grpc_python_out=./OrionServer/proto Chassis.proto
python3 -m grpc_tools.protoc -I./Protocols --python_out=./RemoteClient/proto --grpc_python_out=./RemoteClient/proto Chassis.proto

protoc -I./Protocols --grpc_out=./OrionServerCPP/proto --plugin=protoc-gen-grpc=/usr/local/bin/grpc_cpp_plugin ./Protocols/Chassis.proto
protoc -I./Protocols --cpp_out=./OrionServerCPP/proto ./Protocols/Chassis.proto
