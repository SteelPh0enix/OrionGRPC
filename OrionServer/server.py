from concurrent.futures import ThreadPoolExecutor
import sys
import grpc
from drive_service import DriveServicer
from proto.Chassis_pb2_grpc import add_ChassisServiceServicer_to_server
from orion_communicator import OrionCommunicator

GRPC_SERVER_ADDRESS = '[::]'
GRPC_SERVER_PORT = '16969'

SERIAL_PORT_NAME = ''
SERIAL_PORT_BAUDRATE = 115200

def runserver():
    print('Connecting to chassis...')
    orion_comm = OrionCommunicator(SERIAL_PORT_NAME, SERIAL_PORT_BAUDRATE)

    print('Creating GRPC servicer...')
    grpc_servicer = DriveServicer(orion_comm)

    print('Starting server...')
    server = grpc.server(ThreadPoolExecutor(2))
    add_ChassisServiceServicer_to_server(grpc_servicer, server)
    server.add_insecure_port('{0}:{1}'.format(
        GRPC_SERVER_ADDRESS, GRPC_SERVER_PORT))
    server.start()
    print('Server listening on {0}:{1}'.format(
        GRPC_SERVER_ADDRESS, GRPC_SERVER_PORT))
    try:
        while True:
            pass
    except KeyboardInterrupt:
        print("Shutting down...")
        sys.exit(0)


if __name__ == '__main__':
    runserver()
