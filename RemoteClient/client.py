import grpc
from proto.Chassis_pb2 import ChassisData, ChassisFeedback, MotorData, ArmFeedback
from proto.Chassis_pb2_grpc import ChassisServiceStub, ArmServiceStub
from time import sleep
from inputs import get_gamepad, devices
import keyboard


GRPC_SERVER_IP = '192.168.43.94'
GRPC_SERVER_PORT = '5000'
GRPC_ARM_SERVER_PORT = '5001'
GRPC_CHASSIS_STUB = None
GRPC_ARM_STUB = None
MAX_POWER = 150


def test_comms(stub):
    for i in range(0, 10):
        response = stub.Drive(ChassisData(velocity=i*10, rotation=0))
        print(response)
        sleep(1)


def drive(vel, rot):
    print(GRPC_CHASSIS_STUB.Drive(ChassisData(velocity=vel, rotation=rot)))


def drive_forward(d):
    drive(MAX_POWER, 0)


def drive_backward(d):
    drive(-MAX_POWER, 0)


def rotate_left(d):
    drive(0, -MAX_POWER)


def rotate_right(d):
    drive(0, MAX_POWER)


def stop_chassis(d):
    drive(0, 0)


def make_keybinds():
    keyboard.on_press_key('w', drive_forward)
    keyboard.on_release_key('w', stop_chassis)
    keyboard.on_press_key('s', drive_backward)
    keyboard.on_release_key('s', stop_chassis)
    keyboard.on_press_key('a', rotate_left)
    keyboard.on_release_key('a', stop_chassis)
    keyboard.on_press_key('d', rotate_right)
    keyboard.on_release_key('d', stop_chassis)

def calculate_value(val):
    return ((val - 128) / 128) * MAX_POWER

chassis_channel = grpc.insecure_channel('{0}:{1}'.format(GRPC_SERVER_IP, GRPC_SERVER_IP))
arm_channel = grpc.insecure_channel('{0}:{1}'.format(GRPC_SERVER_IP, GRPC_ARM_SERVER_PORT))
GRPC_CHASSIS_STUB = ChassisServiceStub(chassis_channel)
GRPC_ARM_STUB = ArmServiceStub(arm_channel)
last_x = 0.0
last_y = 0.0
while True:
    events = get_gamepad()
    for event in events:
       print(event.ev_type, event.code, event.state)
       if event.code == 'ABS_Y':
            print("Y: ", -calculate_value(event.state))
            last_y = -calculate_value(event.state)
       elif event.code == 'ABS_X':
            print("X: ", calculate_value(event.state))
            last_x = calculate_value(event.state)
       drive(last_y, last_x)

