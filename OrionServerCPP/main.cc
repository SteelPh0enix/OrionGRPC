#include "proto/Chassis.grpc.pb.h"
#include "proto/Chassis.pb.h"

#include <grpc++/grpc++.h>
#include <grpc++/server.h>
#include <grpc++/server_builder.h>
#include <grpc++/server_context.h>

#include <nlohmann/json.hpp>

#include <SerialStream.h>

#include <iostream>
#include <memory>

using json = nlohmann::json;

class DriveServer final : public ChassisService::Service {
    public:
        virtual grpc::Status Drive(grpc::ServerContext* context, ChassisData const* request, ChassisFeedback* response) override {
            std::cout << "Got ChassisData: V:" << request->velocity() << ", R:" << request->rotation() << '\n';
            json outputJson;

            outputJson["X"] = request->rotation();
            outputJson["Y"] = request->velocity();

            auto jsonString = outputJson.dump() + '\n';

            std::cout << "Sending to chassis: " << jsonString << '\n';

            return grpc::Status::OK;
        }

    private:

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