CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra -Wpedantic
LDFLAGS = -L/usr/local/lib `pkg-config --libs protobuf grpc++ grpc` -Wl,--no-as-needed -lgrpc++_reflection -Wl,--as-needed -ldl -lpthread -pthread

server: proto/Chassis.pb.o proto/Chassis.grpc.pb.o main.o
	$(CXX) $^ $(CXXFLAGS) $(LDFLAGS) -o $@

clean:
	rm proto/*.o *.o server
