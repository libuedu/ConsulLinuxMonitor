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
    class NetMonitor : public MonitorInter
    {
        struct NetInfo
        {
            std::string name;                                  // 网络接口名称。
            int64_t rcv_bytes;                                 // 存储从该网络接口接收到的总字节数。
            int64_t rcv_packets;                               // 记录从该网络接口接收到的数据包总数。
            int64_t err_in;                                    // 记录接收过程中发生的错误包数量。
            int64_t drop_in;                                   // 记录因缓冲区溢出或其他原因而丢弃的接收包数量。
            int64_t snd_bytes;                                 // 存储通过该网络接口发送的总字节数。
            int64_t snd_packets;                               // 记录通过该网络接口发送的数据包总数。
            int64_t err_out;                                   // 记录发送过程中发生的错误包数量。
            int64_t drop_out;                                  // 记录因缓冲区溢出或其他原因而丢弃的发送包数量。
            boost::chrono::steady_clock::time_point timepoint; // 记录最后一次更新该网络接口信息的时间点。
        };

    public:
        NetMonitor() {}
        void UpdateOnce(linux_Monitor::MonitorInfo *monitor_info);
        void Stop() override {}
        void UpdateNetworkMetrics(const NetInfo &old_info, const NetInfo &new_info, double period,
                                  linux_Monitor::MonitorInfo *monitor_info);

    private:
        std::unordered_map<std::string, struct NetInfo> net_info_;
    };

} // namespace linux_Monitor