#include "mem_monitor.h"
#include "read_file.h"
#include "utils.h"
#include "common.h"
#include "myLog.h" // 确保包含您的日志库头文件

namespace linux_Monitor
{
    static constexpr float KBToGB = 1000 * 1000; // 定义将 KB 转换为 GB 的常量

    // 从 /proc/meminfo 文件读取并更新内存监控信息
    void MemMonitor::UpdateOnce(linux_Monitor::MonitorInfo *monitor_info)
    {
        ReadFile mem_file("/proc/meminfo");
        struct MemInfo mem_info;
        std::vector<std::string> mem_datas;

        while (mem_file.ReadLine(&mem_datas))
        {
            if (mem_datas.size() < 2)
            {
                LOG(WARNING) << "Skip invalid or incomplete in-memory data rows";
                continue;
            }

            try
            {
                long long value = std::stoll(mem_datas[1]);
                if (mem_datas[0] == "MemTotal:")
                {
                    mem_info.total = value;
                }
                else if (mem_datas[0] == "MemFree:")
                {
                    mem_info.free = value;
                }
                else if (mem_datas[0] == "MemAvailable:")
                {
                    mem_info.avail = value;
                }
                else if (mem_datas[0] == "Buffers:")
                {
                    mem_info.buffers = value;
                }
                else if (mem_datas[0] == "Cached:")
                {
                    mem_info.cached = value;
                }
                else if (mem_datas[0] == "SwapCached:")
                {
                    mem_info.swap_cached = value;
                }
                else if (mem_datas[0] == "Active:")
                {
                    mem_info.active = value;
                }
                else if (mem_datas[0] == "Inactive:")
                {
                    mem_info.in_active = value;
                }
                else if (mem_datas[0] == "Active(anon):")
                {
                    mem_info.active_anon = value;
                }
                else if (mem_datas[0] == "Inactive(anon):")
                {
                    mem_info.inactive_anon = value;
                }
                else if (mem_datas[0] == "Active(file):")
                {
                    mem_info.active_file = value;
                }
                else if (mem_datas[0] == "Inactive(file):")
                {
                    mem_info.inactive_file = value;
                }
                else if (mem_datas[0] == "Dirty:")
                {
                    mem_info.dirty = value;
                }
                else if (mem_datas[0] == "Writeback:")
                {
                    mem_info.writeback = value;
                }
                else if (mem_datas[0] == "AnonPages:")
                {
                    mem_info.anon_pages = value;
                }
                else if (mem_datas[0] == "Mapped:")
                {
                    mem_info.mapped = value;
                }
                else if (mem_datas[0] == "KReclaimable:")
                {
                    mem_info.kReclaimable = value;
                }
                else if (mem_datas[0] == "SReclaimable:")
                {
                    mem_info.sReclaimable = value;
                }
                else if (mem_datas[0] == "SUnreclaim:")
                {
                    mem_info.sUnreclaim = value;
                }
            }
            catch (const std::exception &e)
            {
                LOG(ERROR) << "Parsing error, data item: " << mem_datas[0] << " ERROR: " << e.what();
            }

            mem_datas.clear();
        }

        if (mem_info.total == 0)
        {
            LOG(ERROR) << "The total memory data is not found or is zero, and the update operation is aborted";
            return;
        }

        auto mem_detail = monitor_info->mutable_mem_info();

        mem_detail->set_used_percent((mem_info.total - mem_info.avail) * 1.0 /
                                     mem_info.total * 100.0);
        mem_detail->set_total(mem_info.total / KBToGB);
        mem_detail->set_free(mem_info.free / KBToGB);
        mem_detail->set_avail(mem_info.avail / KBToGB);
        mem_detail->set_buffers(mem_info.buffers / KBToGB);
        mem_detail->set_cached(mem_info.cached / KBToGB);
        mem_detail->set_swap_cached(mem_info.swap_cached / KBToGB);
        mem_detail->set_active(mem_info.active / KBToGB);
        mem_detail->set_inactive(mem_info.in_active / KBToGB);
        mem_detail->set_active_anon(mem_info.active_anon / KBToGB);
        mem_detail->set_inactive_anon(mem_info.inactive_anon / KBToGB);
        mem_detail->set_active_file(mem_info.active_file / KBToGB);
        mem_detail->set_inactive_file(mem_info.inactive_file / KBToGB);
        mem_detail->set_dirty(mem_info.dirty / KBToGB);
        mem_detail->set_writeback(mem_info.writeback / KBToGB);
        mem_detail->set_anon_pages(mem_info.anon_pages / KBToGB);
        mem_detail->set_mapped(mem_info.mapped / KBToGB);
        mem_detail->set_kreclaimable(mem_info.kReclaimable / KBToGB);
        mem_detail->set_sreclaimable(mem_info.sReclaimable / KBToGB);
        mem_detail->set_sunreclaim(mem_info.sUnreclaim / KBToGB);

        LOG(INFO) << "The memory monitoring information is updated.";
    }
} // namespace linux_Monitor
