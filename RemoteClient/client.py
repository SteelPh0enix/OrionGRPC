import grpc
from proto.Chassis_pb2 import ChassisData, ChassisFeedback
from proto.Chassis_pb2_grpc import ChassisServiceStub

GRPC_SERVER_IP = '0.0.0.0'
GRPC_SERVER_PORT = '5000'


def test_comms(stub):
    for i in range(0, 10):
        response = stub.Drive(ChassisData(velocity=i*10, rotation=i*-10))
        print(response)


def run():
    with grpc.insecure_channel('{0}:{1}'.format(GRPC_SERVER_IP, GRPC_SERVER_PORT)) as channel:
        stub = ChassisServiceStub(channel)
        test_comms(stub)


if __name__ == '__main__':
    run()
