// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: Chassis.proto

#include "Chassis.pb.h"
#include "Chassis.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/method_handler_impl.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>

static const char* ChassisService_method_names[] = {
  "/ChassisService/Drive",
};

std::unique_ptr< ChassisService::Stub> ChassisService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< ChassisService::Stub> stub(new ChassisService::Stub(channel));
  return stub;
}

ChassisService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_Drive_(ChassisService_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status ChassisService::Stub::Drive(::grpc::ClientContext* context, const ::ChassisData& request, ::ChassisFeedback* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_Drive_, context, request, response);
}

void ChassisService::Stub::experimental_async::Drive(::grpc::ClientContext* context, const ::ChassisData* request, ::ChassisFeedback* response, std::function<void(::grpc::Status)> f) {
  return ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_Drive_, context, request, response, std::move(f));
}

void ChassisService::Stub::experimental_async::Drive(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::ChassisFeedback* response, std::function<void(::grpc::Status)> f) {
  return ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_Drive_, context, request, response, std::move(f));
}

::grpc::ClientAsyncResponseReader< ::ChassisFeedback>* ChassisService::Stub::AsyncDriveRaw(::grpc::ClientContext* context, const ::ChassisData& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::ChassisFeedback>::Create(channel_.get(), cq, rpcmethod_Drive_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::ChassisFeedback>* ChassisService::Stub::PrepareAsyncDriveRaw(::grpc::ClientContext* context, const ::ChassisData& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::ChassisFeedback>::Create(channel_.get(), cq, rpcmethod_Drive_, context, request, false);
}

ChassisService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ChassisService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< ChassisService::Service, ::ChassisData, ::ChassisFeedback>(
          std::mem_fn(&ChassisService::Service::Drive), this)));
}

ChassisService::Service::~Service() {
}

::grpc::Status ChassisService::Service::Drive(::grpc::ServerContext* context, const ::ChassisData* request, ::ChassisFeedback* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


static const char* ArmService_method_names[] = {
  "/ArmService/RotateTurntable",
  "/ArmService/MoveLowerActuator",
  "/ArmService/MoveUpperActuator",
  "/ArmService/RotateGrasper",
  "/ArmService/MoveGrasperX",
  "/ArmService/MoveGrasperY",
};

std::unique_ptr< ArmService::Stub> ArmService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< ArmService::Stub> stub(new ArmService::Stub(channel));
  return stub;
}

ArmService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_RotateTurntable_(ArmService_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_MoveLowerActuator_(ArmService_method_names[1], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_MoveUpperActuator_(ArmService_method_names[2], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_RotateGrasper_(ArmService_method_names[3], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_MoveGrasperX_(ArmService_method_names[4], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_MoveGrasperY_(ArmService_method_names[5], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status ArmService::Stub::RotateTurntable(::grpc::ClientContext* context, const ::MotorData& request, ::ArmFeedback* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_RotateTurntable_, context, request, response);
}

void ArmService::Stub::experimental_async::RotateTurntable(::grpc::ClientContext* context, const ::MotorData* request, ::ArmFeedback* response, std::function<void(::grpc::Status)> f) {
  return ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_RotateTurntable_, context, request, response, std::move(f));
}

void ArmService::Stub::experimental_async::RotateTurntable(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::ArmFeedback* response, std::function<void(::grpc::Status)> f) {
  return ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_RotateTurntable_, context, request, response, std::move(f));
}

::grpc::ClientAsyncResponseReader< ::ArmFeedback>* ArmService::Stub::AsyncRotateTurntableRaw(::grpc::ClientContext* context, const ::MotorData& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::ArmFeedback>::Create(channel_.get(), cq, rpcmethod_RotateTurntable_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::ArmFeedback>* ArmService::Stub::PrepareAsyncRotateTurntableRaw(::grpc::ClientContext* context, const ::MotorData& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::ArmFeedback>::Create(channel_.get(), cq, rpcmethod_RotateTurntable_, context, request, false);
}

::grpc::Status ArmService::Stub::MoveLowerActuator(::grpc::ClientContext* context, const ::MotorData& request, ::ArmFeedback* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_MoveLowerActuator_, context, request, response);
}

void ArmService::Stub::experimental_async::MoveLowerActuator(::grpc::ClientContext* context, const ::MotorData* request, ::ArmFeedback* response, std::function<void(::grpc::Status)> f) {
  return ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_MoveLowerActuator_, context, request, response, std::move(f));
}

void ArmService::Stub::experimental_async::MoveLowerActuator(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::ArmFeedback* response, std::function<void(::grpc::Status)> f) {
  return ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_MoveLowerActuator_, context, request, response, std::move(f));
}

::grpc::ClientAsyncResponseReader< ::ArmFeedback>* ArmService::Stub::AsyncMoveLowerActuatorRaw(::grpc::ClientContext* context, const ::MotorData& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::ArmFeedback>::Create(channel_.get(), cq, rpcmethod_MoveLowerActuator_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::ArmFeedback>* ArmService::Stub::PrepareAsyncMoveLowerActuatorRaw(::grpc::ClientContext* context, const ::MotorData& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::ArmFeedback>::Create(channel_.get(), cq, rpcmethod_MoveLowerActuator_, context, request, false);
}

::grpc::Status ArmService::Stub::MoveUpperActuator(::grpc::ClientContext* context, const ::MotorData& request, ::ArmFeedback* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_MoveUpperActuator_, context, request, response);
}

void ArmService::Stub::experimental_async::MoveUpperActuator(::grpc::ClientContext* context, const ::MotorData* request, ::ArmFeedback* response, std::function<void(::grpc::Status)> f) {
  return ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_MoveUpperActuator_, context, request, response, std::move(f));
}

void ArmService::Stub::experimental_async::MoveUpperActuator(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::ArmFeedback* response, std::function<void(::grpc::Status)> f) {
  return ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_MoveUpperActuator_, context, request, response, std::move(f));
}

::grpc::ClientAsyncResponseReader< ::ArmFeedback>* ArmService::Stub::AsyncMoveUpperActuatorRaw(::grpc::ClientContext* context, const ::MotorData& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::ArmFeedback>::Create(channel_.get(), cq, rpcmethod_MoveUpperActuator_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::ArmFeedback>* ArmService::Stub::PrepareAsyncMoveUpperActuatorRaw(::grpc::ClientContext* context, const ::MotorData& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::ArmFeedback>::Create(channel_.get(), cq, rpcmethod_MoveUpperActuator_, context, request, false);
}

::grpc::Status ArmService::Stub::RotateGrasper(::grpc::ClientContext* context, const ::MotorData& request, ::ArmFeedback* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_RotateGrasper_, context, request, response);
}

void ArmService::Stub::experimental_async::RotateGrasper(::grpc::ClientContext* context, const ::MotorData* request, ::ArmFeedback* response, std::function<void(::grpc::Status)> f) {
  return ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_RotateGrasper_, context, request, response, std::move(f));
}

void ArmService::Stub::experimental_async::RotateGrasper(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::ArmFeedback* response, std::function<void(::grpc::Status)> f) {
  return ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_RotateGrasper_, context, request, response, std::move(f));
}

::grpc::ClientAsyncResponseReader< ::ArmFeedback>* ArmService::Stub::AsyncRotateGrasperRaw(::grpc::ClientContext* context, const ::MotorData& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::ArmFeedback>::Create(channel_.get(), cq, rpcmethod_RotateGrasper_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::ArmFeedback>* ArmService::Stub::PrepareAsyncRotateGrasperRaw(::grpc::ClientContext* context, const ::MotorData& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::ArmFeedback>::Create(channel_.get(), cq, rpcmethod_RotateGrasper_, context, request, false);
}

::grpc::Status ArmService::Stub::MoveGrasperX(::grpc::ClientContext* context, const ::MotorData& request, ::ArmFeedback* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_MoveGrasperX_, context, request, response);
}

void ArmService::Stub::experimental_async::MoveGrasperX(::grpc::ClientContext* context, const ::MotorData* request, ::ArmFeedback* response, std::function<void(::grpc::Status)> f) {
  return ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_MoveGrasperX_, context, request, response, std::move(f));
}

void ArmService::Stub::experimental_async::MoveGrasperX(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::ArmFeedback* response, std::function<void(::grpc::Status)> f) {
  return ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_MoveGrasperX_, context, request, response, std::move(f));
}

::grpc::ClientAsyncResponseReader< ::ArmFeedback>* ArmService::Stub::AsyncMoveGrasperXRaw(::grpc::ClientContext* context, const ::MotorData& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::ArmFeedback>::Create(channel_.get(), cq, rpcmethod_MoveGrasperX_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::ArmFeedback>* ArmService::Stub::PrepareAsyncMoveGrasperXRaw(::grpc::ClientContext* context, const ::MotorData& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::ArmFeedback>::Create(channel_.get(), cq, rpcmethod_MoveGrasperX_, context, request, false);
}

::grpc::Status ArmService::Stub::MoveGrasperY(::grpc::ClientContext* context, const ::MotorData& request, ::ArmFeedback* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_MoveGrasperY_, context, request, response);
}

void ArmService::Stub::experimental_async::MoveGrasperY(::grpc::ClientContext* context, const ::MotorData* request, ::ArmFeedback* response, std::function<void(::grpc::Status)> f) {
  return ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_MoveGrasperY_, context, request, response, std::move(f));
}

void ArmService::Stub::experimental_async::MoveGrasperY(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::ArmFeedback* response, std::function<void(::grpc::Status)> f) {
  return ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_MoveGrasperY_, context, request, response, std::move(f));
}

::grpc::ClientAsyncResponseReader< ::ArmFeedback>* ArmService::Stub::AsyncMoveGrasperYRaw(::grpc::ClientContext* context, const ::MotorData& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::ArmFeedback>::Create(channel_.get(), cq, rpcmethod_MoveGrasperY_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::ArmFeedback>* ArmService::Stub::PrepareAsyncMoveGrasperYRaw(::grpc::ClientContext* context, const ::MotorData& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::ArmFeedback>::Create(channel_.get(), cq, rpcmethod_MoveGrasperY_, context, request, false);
}

ArmService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ArmService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< ArmService::Service, ::MotorData, ::ArmFeedback>(
          std::mem_fn(&ArmService::Service::RotateTurntable), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ArmService_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< ArmService::Service, ::MotorData, ::ArmFeedback>(
          std::mem_fn(&ArmService::Service::MoveLowerActuator), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ArmService_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< ArmService::Service, ::MotorData, ::ArmFeedback>(
          std::mem_fn(&ArmService::Service::MoveUpperActuator), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ArmService_method_names[3],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< ArmService::Service, ::MotorData, ::ArmFeedback>(
          std::mem_fn(&ArmService::Service::RotateGrasper), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ArmService_method_names[4],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< ArmService::Service, ::MotorData, ::ArmFeedback>(
          std::mem_fn(&ArmService::Service::MoveGrasperX), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ArmService_method_names[5],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< ArmService::Service, ::MotorData, ::ArmFeedback>(
          std::mem_fn(&ArmService::Service::MoveGrasperY), this)));
}

ArmService::Service::~Service() {
}

::grpc::Status ArmService::Service::RotateTurntable(::grpc::ServerContext* context, const ::MotorData* request, ::ArmFeedback* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status ArmService::Service::MoveLowerActuator(::grpc::ServerContext* context, const ::MotorData* request, ::ArmFeedback* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status ArmService::Service::MoveUpperActuator(::grpc::ServerContext* context, const ::MotorData* request, ::ArmFeedback* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status ArmService::Service::RotateGrasper(::grpc::ServerContext* context, const ::MotorData* request, ::ArmFeedback* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status ArmService::Service::MoveGrasperX(::grpc::ServerContext* context, const ::MotorData* request, ::ArmFeedback* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status ArmService::Service::MoveGrasperY(::grpc::ServerContext* context, const ::MotorData* request, ::ArmFeedback* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


