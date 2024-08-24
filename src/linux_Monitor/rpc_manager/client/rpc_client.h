#pragma once

#include <grpc/grpc.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/grpcpp.h>
#include <string>
#include "monitor_info.grpc.pb.h"
#include "monitor_info.pb.h"
#include "health.grpc.pb.h"
#include "health.pb.h"

namespace linux_Monitor
{
    class RpcClient
    {
    public:
        RpcClient(const std::string &server_address = "localhost:50051");
        ~RpcClient();
        void SetMonitorInfo(const linux_Monitor::MonitorInfo &monito_info);
        void GetMonitorInfo(linux_Monitor::MonitorInfo *monito_info);
        std::string discoverService(const std::string &service_name);
        std::string CheckHealth(); // 健康检查方法

    private:
        std::unique_ptr<linux_Monitor::GrpcManager::Stub> stub_ptr_;
        std::unique_ptr<grpc::health::v1::Health::Stub> health_stub_; // 健康检查 Stub
    };
} // namespace linux_Monitor
