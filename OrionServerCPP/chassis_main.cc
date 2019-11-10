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

std::string const CHASSIS_SERIAL_PORT_NAME{"/dev/ttyACM0"};

class DriveServer final : public ChassisService::Service {
    public:
        DriveServer(std::string const& chassisPortName) {
            chassisStream.Open(chassisPortName);
            chassisStream.SetBaudRate(LibSerial::SerialStreamBuf::BAUD_115200);
            chassisStream.SetCharSize(LibSerial::SerialStreamBuf::CHAR_SIZE_8);
            chassisStream.SetFlowControl(LibSerial::SerialStreamBuf::FLOW_CONTROL_NONE);
            chassisStream.SetParity(LibSerial::SerialStreamBuf::PARITY_NONE);
        }

        virtual grpc::Status Drive(grpc::ServerContext* context, ChassisData const* request, ChassisFeedback* response) override {
            std::cout << "Got ChassisData: V:" << request->velocity() << ", R:" << request->rotation() << '\n';
            json outputJson;

            outputJson["Y"] = request->velocity();
            outputJson["X"] = request->rotation();

            auto jsonString = outputJson.dump();

            std::cout << "Sending to chassis: " << jsonString << '\n';
            chassisStream << jsonString << '\n';

            // std::string chassisStringFeedback{"{\"ErrorCode\":123,\"ErrorDescription\":\"dupa\",\"LF\":123,\"RF\":456}"};
            std::string chassisStringFeedback{};
            std::getline(chassisStream, chassisStringFeedback);
            std::cout << "Got feedback: " << chassisStringFeedback << '\n';

            auto feedbackJson = json::parse(chassisStringFeedback);

            response->set_errorcode(feedbackJson["ErrorCode"]);
            response->set_errordescription(feedbackJson["ErrorDescription"]);
            response->set_leftpower(feedbackJson["LF"]);
            response->set_rightpower(feedbackJson["RF"]);

            return grpc::Status::OK;
        }

    private:
        LibSerial::SerialStream chassisStream;
};

int main() {
    std::cout << "Remember to run this as root!\n";
    std::string chassis_server_address("0.0.0.0:5000");
    DriveServer service(CHASSIS_SERIAL_PORT_NAME);


    grpc::ServerBuilder builder;
    builder.AddListeningPort(chassis_server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << chassis_server_address << '\n';
    server->Wait();
}