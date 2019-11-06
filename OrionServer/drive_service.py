from proto.Chassis_pb2_grpc import ChassisServiceServicer
from proto.Chassis_pb2 import ChassisData, ChassisFeedback


class DriveServicer(ChassisServiceServicer):
    def __init__(self, orion_comm):
        self.orion = orion_comm

    def request_to_dict(self, request: ChassisData) -> dict:
        return {
            'Y': request.velocity,
            'X': request.rotation
        }

    def dict_to_response(self, response: dict) -> ChassisFeedback:
        return ChassisFeedback(leftPower=response['LF'],
                               rightPower=response['RF'],
                               errorCode=response['ErrorCode'],
                               errorDescription=response['ErrorDescription'])

    def Drive(self, request, context):
        request_json = self.request_to_dict(request)
        response_json = self.orion.send_json(
            request_json)
        return self.dict_to_response(response_json)
