import json
import serial


class OrionCommunicator():
    def __init__(self, port, baudrate):
        self.serialport = serial.Serial(port, baudrate)

    def send_json(self, msg):
        json_bytes = (json.dumps(msg) + '\n').encode('ASCII')
        self.serialport.write(json_bytes)

        response_bytes = self.serialport.readline()
        return json.loads(response_bytes.decode('ASCII'))