#include "monitor_inter.h"
#include "cpu_load_monitor.h"
#include "cpu_softirq_monitor.h"
#include "cpu_stat_monitor.h"
#include "mem_monitor.h"
#include "net_monitor.h"
#include <memory>
#include <string>

namespace linux_Monitor
{

    class MonitorFactory
    {
    public:
        static std::shared_ptr<MonitorInter> CreateMonitor(const std::string &type)
        {
            if (type == "CpuSoftIrq")
            {
                return std::make_shared<CpuSoftIrqMonitor>();
            }
            else if (type == "CpuLoad")
            {
                return std::make_shared<CpuLoadMonitor>();
            }
            else if (type == "CpuStat")
            {
                return std::make_shared<CpuStatMonitor>();
            }
            else if (type == "Mem")
            {
                return std::make_shared<MemMonitor>();
            }
            else if (type == "Net")
            {
                return std::make_shared<NetMonitor>();
            }
            return nullptr;
        }
    };

} // namespace linux_Monitor
