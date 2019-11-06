import json
import serial
from time import sleep


class OrionCommunicator():
    def __init__(self, port, baudrate):
        self.serialport = serial.Serial(port, baudrate, timeout=None)

    def send_json(self, msg):
        json_bytes = (json.dumps(msg) + '\n').encode('ASCII')
        print('[Serial TX] {0}'.format(json_bytes))
        self.serialport.write(json_bytes)
        self.serialport.flush()

        response = self.serialport.readline()
        print('[Serial RX] {0}'.format(response))
        return json.loads(response.decode('ASCII'))


if __name__ == '__main__':
    comm = OrionCommunicator('COM5', 115200)
    sleep(1)

    for i in range(0, 20):
        comm.send_json({'Y': 100.0, 'X': -100.0})
