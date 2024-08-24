#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <boost/chrono.hpp>

#include "monitor_inter.h"
#include "monitor_info.grpc.pb.h"
#include "monitor_info.pb.h"

namespace linux_Monitor
{
    // CPU软中断监控类。
    class CpuSoftIrqMonitor : public MonitorInter
    {
        struct SoftIrq
        {
            std::string cpu_name;                              // 表示统计信息所属的 CPU 标识
            int64_t hi;                                        // 高优先级任务的软中断处理时间
            int64_t timer;                                     // 计时器软中断处理时间
            int64_t net_tx;                                    // 网络传输软中断处理时间
            int64_t net_rx;                                    // 网络接收软中断处理时间
            int64_t block;                                     // 块设备软中断处理时间
            int64_t irq_poll;                                  // 轮询 IRQ 软中断处理时间
            int64_t tasklet;                                   // 小任务软中断处理时间
            int64_t sched;                                     // 调度软中断处理时间
            int64_t hrtimer;                                   // 高分辨率计时器软中断处理时间
            int64_t rcu;                                       // RCU 软中断处理时间
            boost::chrono::steady_clock::time_point timepoint; // 最后更新时间
        };

    public:
        CpuSoftIrqMonitor() {}
        void UpdateOnce(linux_Monitor::MonitorInfo *monitor_info);
        void Stop() override {}
        void updateMonitorInfo(const SoftIrq &info, const SoftIrq &old, double period, linux_Monitor::MonitorInfo *monitor_info);

    private:
        std::unordered_map<std::string, struct SoftIrq> cpu_softirqs_; // CPU软中断数据映射
    };

} // namespace linux_Monitor
