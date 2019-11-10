CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra -Wpedantic
LDFLAGS = -L/usr/local/lib `pkg-config --libs protobuf grpc++ grpc` -Wl,--no-as-needed -lgrpc++_reflection -Wl,--as-needed -ldl -lpthread -pthread -lserial

chassis_server: proto/Chassis.pb.o proto/Chassis.grpc.pb.o chassis_main.o
	$(CXX) $^ $(CXXFLAGS) $(LDFLAGS) -o $@

arm_server: proto/Chassis.pb.o proto/Chassis.grpc.pb.o arm_main.o
	$(CXX) $^ $(CXXFLAGS) $(LDFLAGS) -o $@

clean:
	rm proto/*.o *.o server
