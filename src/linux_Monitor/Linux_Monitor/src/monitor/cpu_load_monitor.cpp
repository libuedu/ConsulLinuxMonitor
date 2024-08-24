#include "cpu_load_monitor.h"
#include "read_file.h"
#include "common.h"
#include "myLog.h"

#include <stdexcept>

namespace linux_Monitor
{
    void CpuLoadMonitor::UpdateOnce(linux_Monitor::MonitorInfo *monitor_info)
    {
        ReadFile cpu_load_file("/proc/loadavg");
        std::vector<std::string> cpu_load;

        if (!cpu_load_file.ReadLine(&cpu_load) || cpu_load.size() < 3)
        {
            LOG(ERROR) << "Failed to read CPU load data or data is incomplete.";
            return;
        }

        try
        {
            load_avg_1_ = std::stof(cpu_load[0]);
            load_avg_3_ = std::stof(cpu_load[1]);
            load_avg_15_ = std::stof(cpu_load[2]);
        }
        catch (const std::exception &e)
        {
            LOG(ERROR) << "Error converting CPU load data to float: " << e.what();
            return;
        }

        auto cpu_load_msg = monitor_info->mutable_cpu_load();
        cpu_load_msg->set_load_avg_1(load_avg_1_);
        cpu_load_msg->set_load_avg_3(load_avg_3_);
        cpu_load_msg->set_load_avg_15(load_avg_15_);
        LOG(INFO) << "The CPU load monitoring information is updated.";
    }
}
