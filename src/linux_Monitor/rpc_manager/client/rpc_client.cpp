#include "rpc_client.h"
#include <cpr/cpr.h>
#include <iostream>
#include <nlohmann/json.hpp>

namespace linux_Monitor
{

    RpcClient::RpcClient(const std::string &service_name)
    {
        std::string server_address = discoverService(service_name);
        auto channel = grpc::CreateChannel(server_address, grpc::InsecureChannelCredentials());
        stub_ptr_ = linux_Monitor::GrpcManager::NewStub(channel);
        health_stub_ = grpc::health::v1::Health::NewStub(channel); // 初始化健康检查 Stub
    }

    RpcClient::~RpcClient() {}

    std::string RpcClient::discoverService(const std::string &service_name)
    {
        auto response = cpr::Get(cpr::Url{"http://192.168.231.128:8500/v1/catalog/service/" + service_name});
        if (response.status_code == 200)
        {
            auto json = nlohmann::json::parse(response.text);
            if (!json.empty())
            {
                auto serviceNode = json[0];
                std::string address = serviceNode["ServiceAddress"];
                int port = serviceNode["ServicePort"];
                return address + ":" + std::to_string(port);
            }
        }
        throw std::runtime_error("Failed to discover service from Consul");
    }

    void RpcClient::SetMonitorInfo(const linux_Monitor::MonitorInfo &monitor_info)
    {
        ::grpc::ClientContext context;
        ::google::protobuf::Empty response;
        ::grpc::Status status = stub_ptr_->SetMonitorInfo(&context, monitor_info, &response);
        if (!status.ok())
        {
            std::cerr << "Failed to set monitor info: " << status.error_message() << std::endl;
        }
    }

    void RpcClient::GetMonitorInfo(linux_Monitor::MonitorInfo *monitor_info)
    {
        ::grpc::ClientContext context;
        ::google::protobuf::Empty request;
        ::grpc::Status status = stub_ptr_->GetMonitorInfo(&context, request, monitor_info);
        if (!status.ok())
        {
            std::cerr << "Failed to get monitor info: " << status.error_message() << std::endl;
        }
    }

    std::string RpcClient::CheckHealth()
    {
        grpc::ClientContext context;
        grpc::health::v1::HealthCheckRequest request;
        grpc::health::v1::HealthCheckResponse response;
        request.set_service(""); // 如有需要，指定服务名称
        auto status = health_stub_->Check(&context, request, &response);
        if (status.ok())
        {
            return "Service is " + response.status();
        }
        else
        {
            return "Health check failed: " + status.error_message();
        }
    }

} // namespace linux_Monitor
