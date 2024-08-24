#include "rpc_manager.h"
#include <iostream>
#include <cpr/cpr.h>
#include <ifaddrs.h>
#include <arpa/inet.h>

namespace linux_Monitor
{

    GrpcManagerImpl::GrpcManagerImpl()
    {
        // 注册服务到 Consul
        registerService();
    }

    GrpcManagerImpl::~GrpcManagerImpl()
    {
        // 从 Consul 注销服务
        deregisterService();
    }

    std::string GetLocalIPAddress()
    {
        struct ifaddrs *ifap, *ifa;
        struct sockaddr_in *sa;
        char *addr;
        std::string ipAddress = "127.0.0.1"; // 默认 IP

        getifaddrs(&ifap);
        for (ifa = ifap; ifa; ifa = ifa->ifa_next)
        {
            if (ifa->ifa_addr && ifa->ifa_addr->sa_family == AF_INET)
            {
                sa = (struct sockaddr_in *)ifa->ifa_addr;
                addr = inet_ntoa(sa->sin_addr);
                if (strcmp(ifa->ifa_name, "lo") != 0) // 忽略本地回环地址
                {
                    ipAddress = addr;
                    break;
                }
            }
        }

        freeifaddrs(ifap);
        return ipAddress;
    }

    void GrpcManagerImpl::registerService()
    {
        std::string ipAddress = GetLocalIPAddress();
        std::string serviceName = "grpc-monitor-" + ipAddress;

        std::string serviceJson = R"({
            "ID": ")" + serviceName +
                                  R"(",
            "Name": ")" + serviceName +
                                  R"(",
            "Tags": ["grpc"],
            "Address": ")" + ipAddress +
                                  R"(",
            "Port": 50051,
            "Check": {
                "GRPC": ")" + ipAddress +
                                  R"(:50051",
                "GRPCUseTLS": false,
                "Interval": "10s",
                "Timeout": "5s"
            }
        })";

        auto response = cpr::Put(cpr::Url{"http://127.0.0.1:8500/v1/agent/service/register"},
                                 cpr::Body{serviceJson}, cpr::Header{{"Content-Type", "application/json"}});
        if (response.status_code != 200)
        {
            throw std::runtime_error("Failed to register service with Consul: " + response.text);
        }
    }

    void GrpcManagerImpl::deregisterService()
    {
        std::string ipAddress = GetLocalIPAddress();
        auto response = cpr::Put(cpr::Url{"http://127.0.0.1:8500/v1/agent/service/deregister/grpc-monitor-" + ipAddress});
        if (response.status_code != 200)
        {
            std::cerr << "Failed to deregister service from Consul" << std::endl;
        }
    }

    ::grpc::Status GrpcManagerImpl::SetMonitorInfo(::grpc::ServerContext *context,
                                                   const linux_Monitor::MonitorInfo *request,
                                                   ::google::protobuf::Empty *response)
    {
        monitor_infos_.Clear();
        monitor_infos_ = *request;
        return grpc::Status::OK;
    }

    ::grpc::Status GrpcManagerImpl::GetMonitorInfo(::grpc::ServerContext *context,
                                                   const ::google::protobuf::Empty *request,
                                                   linux_Monitor::MonitorInfo *response)
    {
        *response = monitor_infos_;
        return grpc::Status::OK;
    }

    ::grpc::Status GrpcManagerImpl::HealthCheck(::grpc::ServerContext *context,
                                                const ::google::protobuf::Empty *request,
                                                ::google::protobuf::Empty *response)
    {
        std::cout << "Get HealthCheck Service" << std::endl;
        return grpc::Status::OK;
    }

} // namespace linux_Monitor
