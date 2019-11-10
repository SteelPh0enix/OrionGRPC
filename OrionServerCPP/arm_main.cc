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
std::string const ARM_SERIAL_PORT_NAME{"/dev/ttyACM1"};

class ArmMovementService final : public ArmService::Service {
    public:
        ArmMovementService(std::string const& portName) {
            armStream.Open(portName);
            armStream.SetBaudRate(LibSerial::SerialStreamBuf::BAUD_115200);
            armStream.SetCharSize(LibSerial::SerialStreamBuf::CHAR_SIZE_8);
            armStream.SetFlowControl(LibSerial::SerialStreamBuf::FLOW_CONTROL_NONE);
            armStream.SetParity(LibSerial::SerialStreamBuf::PARITY_NONE);
        }

        virtual grpc::Status RotateTurntable(grpc::ServerContext* context, MotorData const* request, ArmFeedback* response) override {
            json armJson{{"TRT", request->power()}};   
            std::cout << "JSON: " << armJson.dump() << '\n';
            armStream << armJson.dump() << '\n';

            std::string feedbackString{};
            std::getline(armStream, feedbackString);

            auto feedbackJson = json::parse(feedbackString);
            response->set_errorcode(feedbackJson["ErrorCode"]);
            response->set_errordescription(feedbackJson["ErrorDescription"]);

            return grpc::Status::OK;
        }

        virtual grpc::Status MoveLowerActuator(grpc::ServerContext* context, MotorData const* request, ArmFeedback* response) override {
            json armJson{{"LAC", request->power()}};   
            std::cout << "JSON: " << armJson.dump() << '\n';
            armStream << armJson.dump() << '\n';

            std::string feedbackString{};
            std::getline(armStream, feedbackString);

            auto feedbackJson = json::parse(feedbackString);
            response->set_errorcode(feedbackJson["ErrorCode"]);
            response->set_errordescription(feedbackJson["ErrorDescription"]);

            return grpc::Status::OK;
        }

        virtual grpc::Status MoveUpperActuator(grpc::ServerContext* context, MotorData const* request, ArmFeedback* response) override {
            json armJson{{"UAC", request->power()}};   
            std::cout << "JSON: " << armJson.dump() << '\n';
            armStream << armJson.dump() << '\n';

            std::string feedbackString{};
            std::getline(armStream, feedbackString);

            auto feedbackJson = json::parse(feedbackString);
            response->set_errorcode(feedbackJson["ErrorCode"]);
            response->set_errordescription(feedbackJson["ErrorDescription"]);

            return grpc::Status::OK;
        }

        virtual grpc::Status RotateGrasper(grpc::ServerContext* context, MotorData const* request, ArmFeedback* response) override {
            json armJson{{"GRPR", request->power()}};   
            std::cout << "JSON: " << armJson.dump() << '\n';
            armStream << armJson.dump() << '\n';

            std::string feedbackString{};
            std::getline(armStream, feedbackString);

            auto feedbackJson = json::parse(feedbackString);
            response->set_errorcode(feedbackJson["ErrorCode"]);
            response->set_errordescription(feedbackJson["ErrorDescription"]);

            return grpc::Status::OK;
        }

        virtual grpc::Status MoveGrasperX(grpc::ServerContext* context, MotorData const* request, ArmFeedback* response) override {
            json armJson{{"GRPX", request->power()}};   
            std::cout << "JSON: " << armJson.dump() << '\n';
            armStream << armJson.dump() << '\n';

            std::string feedbackString{};
            std::getline(armStream, feedbackString);

            auto feedbackJson = json::parse(feedbackString);
            response->set_errorcode(feedbackJson["ErrorCode"]);
            response->set_errordescription(feedbackJson["ErrorDescription"]);

            return grpc::Status::OK;
        }

        virtual grpc::Status MoveGrasperY(grpc::ServerContext* context, MotorData const* request, ArmFeedback* response) override {
            json armJson{{"GRPY", request->power()}};   
            std::cout << "JSON: " << armJson.dump() << '\n';
            armStream << armJson.dump() << '\n';

            std::string feedbackString{};
            std::getline(armStream, feedbackString);

            auto feedbackJson = json::parse(feedbackString);
            response->set_errorcode(feedbackJson["ErrorCode"]);
            response->set_errordescription(feedbackJson["ErrorDescription"]);

            return grpc::Status::OK;
        }
    private:
        LibSerial::SerialStream armStream;
};

int main() {
    std::cout << "Remember to run this as root!\n";
    std::string arm_server_address("0.0.0.0:5001");
    ArmMovementService service(ARM_SERIAL_PORT_NAME);


    grpc::ServerBuilder builder;
    builder.AddListeningPort(arm_server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << arm_server_address << '\n';
    server->Wait();
}