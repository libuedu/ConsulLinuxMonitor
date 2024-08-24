#pragma once

#include <grpcpp/support/status.h>
#include <unordered_map>
#include "monitor_info.grpc.pb.h"
#include "monitor_info.pb.h"
#include "health.grpc.pb.h"
#include "health.pb.h"
#include <grpcpp/health_check_service_interface.h>
namespace linux_Monitor
{
    class GrpcManagerImpl : public linux_Monitor::GrpcManager::Service
    {
    public:
        GrpcManagerImpl();

        virtual ~GrpcManagerImpl();

        ::grpc::Status SetMonitorInfo(::grpc::ServerContext *context,
                                      const linux_Monitor::MonitorInfo *request,
                                      ::google::protobuf::Empty *response);
        ::grpc::Status GetMonitorInfo(::grpc::ServerContext *context,
                                      const ::google::protobuf::Empty *request,
                                      linux_Monitor::MonitorInfo *response);
        ::grpc::Status HealthCheck(::grpc::ServerContext *context,
                                   const ::google::protobuf::Empty *request,
                                   ::google::protobuf::Empty *response);
        void registerService();
        void deregisterService();
        void set_health_check_service(
            grpc::HealthCheckServiceInterface *health_check_service)
        {
            health_check_service_ = health_check_service;
        }

    private:
        linux_Monitor::MonitorInfo monitor_infos_;
        grpc::HealthCheckServiceInterface *health_check_service_ = nullptr;
    };

} // namespace linux_Monitor
