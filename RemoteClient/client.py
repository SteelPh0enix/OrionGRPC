import grpc
from proto.Chassis_pb2 import ChassisData, ChassisFeedback
from proto.Chassis_pb2_grpc import ChassisServiceStub
from time import sleep
import keyboard


GRPC_SERVER_IP = '192.168.43.94'
GRPC_SERVER_PORT = '5000'
GRPC_STUB = None
CHASSIS_MAX_POWER = 150

def test_comms(stub):
    for i in range(0, 10):
        response = stub.Drive(ChassisData(velocity=i*10, rotation=0))
        print(response)
        sleep(1)

def drive(vel, rot):
    print(GRPC_STUB.Drive(ChassisData(velocity=vel,rotation=rot)))

def drive_forward():
    drive(CHASSIS_MAX_POWER, 0)

def drive_backward():
    drive(-CHASSIS_MAX_POWER, 0)

def rotate_left():
    drive(0, -CHASSIS_MAX_POWER)

def rotate_right():
    drive(0, CHASSIS_MAX_POWER)

def stop_chassis():
    drive(0,0)

def make_keybinds():
    keyboard.on_press_key('w', drive_forward)
    keyboard.on_release_key('w', stop_chassis)
    keyboard.on_press_key('s', drive_backward)
    keyboard.on_release_key('s', stop_chassis)
    keyboard.on_press_key('a', rotate_left)
    keyboard.on_release_key('a', stop_chassis)
    keyboard.on_press_key('d', rotate_right)
    keyboard.on_release_key('s', stop_chassis)


def run():
    with grpc.insecure_channel('{0}:{1}'.format(GRPC_SERVER_IP, GRPC_SERVER_PORT)) as channel:
        stub = ChassisServiceStub(channel)
        GRPC_STUB = stub
        make_keybinds()
        keyboard.wait()

if __name__ == '__main__':
    run()
