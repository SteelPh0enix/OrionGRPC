# Generated by the gRPC Python protocol compiler plugin. DO NOT EDIT!
import grpc

from . import Chassis_pb2 as Chassis__pb2


class ChassisServiceStub(object):
    # missing associated documentation comment in .proto file
    pass

    def __init__(self, channel):
        """Constructor.

        Args:
          channel: A grpc.Channel.
        """
        self.Drive = channel.stream_stream(
            '/ChassisService/Drive',
            request_serializer=Chassis__pb2.ChassisData.SerializeToString,
            response_deserializer=Chassis__pb2.ChassisFeedback.FromString,
        )


class ChassisServiceServicer(object):
    # missing associated documentation comment in .proto file
    pass

    def Drive(self, request_iterator, context):
        # missing associated documentation comment in .proto file
        pass
        context.set_code(grpc.StatusCode.UNIMPLEMENTED)
        context.set_details('Method not implemented!')
        raise NotImplementedError('Method not implemented!')


def add_ChassisServiceServicer_to_server(servicer, server):
    rpc_method_handlers = {
        'Drive': grpc.stream_stream_rpc_method_handler(
            servicer.Drive,
            request_deserializer=Chassis__pb2.ChassisData.FromString,
            response_serializer=Chassis__pb2.ChassisFeedback.SerializeToString,
        ),
    }
    generic_handler = grpc.method_handlers_generic_handler(
        'ChassisService', rpc_method_handlers)
    server.add_generic_rpc_handlers((generic_handler,))
