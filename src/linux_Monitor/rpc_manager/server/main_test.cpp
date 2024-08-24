#include <iostream>
#include <grpc/grpc.h>
#include <grpcpp/server_builder.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include "rpc_manager.h"
#include <thread>

constexpr char kServerPortInfo[] = "0.0.0.0:50051";

void InitServer()
{
    grpc::EnableDefaultHealthCheckService(true);
    grpc::reflection::InitProtoReflectionServerBuilderPlugin();

    grpc::ServerBuilder builder;
    builder.AddListeningPort(kServerPortInfo, grpc::InsecureServerCredentials());

    linux_Monitor::GrpcManagerImpl grpc_server;
    builder.RegisterService(&grpc_server);

    try
    {
        std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
        grpc_server.set_health_check_service(server->GetHealthCheckService());
        std::cout << "Server listening on 0.0.0.0:50051" << std::endl;
        server->Wait();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Server failed to start: " << e.what() << std::endl;
    }
}

int main()
{
    InitServer();
    return 0;
}
