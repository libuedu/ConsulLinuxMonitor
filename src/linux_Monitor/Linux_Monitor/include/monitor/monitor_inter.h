#pragma once

#include <iostream>
#include <string>
#include "monitor_info.grpc.pb.h"

// 基础监控接口类，所有监控类型的基类。
namespace linux_Monitor
{
    class MonitorInter
    {
    public:
        MonitorInter() {}
        virtual ~MonitorInter() {}

        // 纯虚函数，用于更新监控信息，派生类必须实现。
        virtual void UpdateOnce(linux_Monitor::MonitorInfo *monitor_info) = 0;

        // 纯虚函数，用于停止监控，派生类必须实现。
        virtual void Stop() = 0;
    };
} // namespace linux_Monitor