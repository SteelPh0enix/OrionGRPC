CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra -Wpedantic
LDFLAGS = `pkg-config --libs protobuf grpc++` -pthread -Wl,--no-as-needed -lgrpc++_reflection -Wl,--as-needed -ldl

server: proto/Chassis.pb.o proto/Chassis.grpc.pb.o main.o
	$(CXX) $^ $(CXXFLAGS) $(LDFLAGS) -o $@

clean:
	rm proto/*.o *.o server