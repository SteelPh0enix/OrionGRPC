$ErrorActionPreference = 'silentlycontinue'
mkdir .\OrionServer\proto > $null
mkdir .\RemoteClient\proto > $null

py -m grpc_tools.protoc -I./Protocols --python_out=./OrionServer/proto --grpc_python_out=./OrionServer/proto ./Protocols/Chassis.proto
py -m grpc_tools.protoc -I./Protocols --python_out=./RemoteClient/proto --grpc_python_out=./RemoteClient/proto ./Protocols/Chassis.proto