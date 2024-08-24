#pragma once

#include <string>
#include <iostream>

#include "monitor_inter.h"
#include "monitor_info.grpc.pb.h"
#include "monitor_info.pb.h"

namespace linux_Monitor
{
    // CPU负载监控类，实现基础监控接口。
    class CpuLoadMonitor : public MonitorInter
    {
    public:
        CpuLoadMonitor() = default;
        void UpdateOnce(linux_Monitor::MonitorInfo *monitor_info) override;
        void Stop() override {}

    private:
        float load_avg_1_;  // 1分钟平均负载。
        float load_avg_3_;  // 5分钟平均负载。
        float load_avg_15_; // 15分钟平均负载。
    };
} // namespace linux_Monitor