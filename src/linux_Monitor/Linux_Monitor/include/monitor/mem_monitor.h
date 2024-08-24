#pragma once

#include <iostream>
#include <string>
#include <unordered_map>

#include "monitor_inter.h"
#include "monitor_info.grpc.pb.h"
#include "monitor_info.pb.h"

namespace linux_Monitor
{
    class MemMonitor : public MonitorInter
    {
        struct MemInfo
        {
            int64_t total;         // 系统总内存量（单位：MB或GB）
            int64_t free;          // 系统空闲内存量
            int64_t avail;         // 可用内存量，不一定全部空闲，但可被进程使用
            int64_t buffers;       // 用作缓冲的内存量
            int64_t cached;        // 用作缓存的内存量
            int64_t swap_cached;   // 被交换缓存使用的内存量
            int64_t active;        // 活跃的内存量，近期被使用
            int64_t in_active;     // 非活跃的内存量，较少使用
            int64_t active_anon;   // 匿名活跃内存量（没有关联的文件）
            int64_t inactive_anon; // 匿名非活跃内存量
            int64_t active_file;   // 文件活跃内存量（有关联的文件）
            int64_t inactive_file; // 文件非活跃内存量
            int64_t dirty;         // 待写回到磁盘的内存量
            int64_t writeback;     // 正在被写回磁盘的内存量
            int64_t anon_pages;    // 匿名页内存量
            int64_t mapped;        // 映射到用户空间的内存量
            int64_t kReclaimable;  // 内核可回收的内存量
            int64_t sReclaimable;  // Slab分配器中可回收的内存量
            int64_t sUnreclaim;    // Slab分配器中不可回收的内存量
        };

    public:
        MemMonitor() {}
        void UpdateOnce(linux_Monitor::MonitorInfo *monitor_info);
        void Stop() override {}
    };

} // namespace linux_Monitor