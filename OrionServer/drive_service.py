from proto.Chassis_pb2_grpc import ChassisServiceServicer
from proto.Chassis_pb2 import ChassisData, ChassisFeedback
import json

class DriveServicer(ChassisServiceServicer):
    def __init__(self, orion_comm):
        self.orion = orion_comm

    def request_to_dict(self, request: ChassisData) -> dict:
        return {
            'VEL': request.velocity,
            'ROT': request.rotation
        }


    def dict_to_response(self, response: dict) -> ChassisFeedback:
        # TODO: You left it here.
        return ChassisFeedback()

    def Drive(self, request_iterator, context):
        for drive_request in request_iterator:
            request_json = self.request_to_dict(drive_request)
            print("Request: {0}".format(request_json))
            response_json = self.orion.send_json(
                request_json)
            print("Response: {0}".format(response_json))
            yield self.dict_to_response(response_json)
