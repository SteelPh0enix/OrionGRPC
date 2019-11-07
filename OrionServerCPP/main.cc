#include "proto/Chassis.grpc.pb.h"
#include "proto/Chassis.pb.h"

#include <grpc++/grpc++.h>
#include <grpc++/server.h>
#include <grpc++/server_builder.h>
#include <grpc++/server_context.h>

#include <iostream>
#include <memory>

class DriveServer final : public ChassisService::Service {
    public:
        virtual grpc::Status Drive(grpc::ServerContext* context, ChassisData const* request, ChassisFeedback* response) override {
            std::cout << "Got ChassisData: " << request->velocity() << ", " << request->rotation() << '\n';
            response->set_leftpower(request->velocity());
            response->set_rightpower(request->rotation());
            response->set_errorcode(69);
            response->set_errordescription("nope");
            return grpc::Status::OK;
        }
};

int main() {
    std::string server_address("0.0.0.0:5000");
    DriveServer service;

    grpc::ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << '\n';
    server->Wait();
}