#include "cpu_softirq_monitor.h"
#include "read_file.h"
#include "utils.h"
#include "common.h"
#include "myLog.h"
#include <thread>
#include <exception>

namespace linux_Monitor
{
    // 从 /proc/softirqs 文件中读取并更新一次 CPU 软中断监控信息
    void CpuSoftIrqMonitor::UpdateOnce(linux_Monitor::MonitorInfo *monitor_info)
    {
        ReadFile softirqs_file("/proc/softirqs");
        std::vector<std::string> one_softirq;
        std::vector<std::vector<std::string>> softirq;

        // 循环读取每一行，直到文件末尾
        while (softirqs_file.ReadLine(&one_softirq))
        {
            if (!one_softirq.empty())
            {
                softirq.push_back(one_softirq);
                one_softirq.clear();
            }
        }

        // 确保读取到的数据符合预期结构，至少包含 11 行（包括 CPU 行和每个 IRQ 类型一行）
        if (softirq.size() < 11 || softirq[0].size() < 2)
        {
            LOG(ERROR) << "SoftIRQ data is not fully read or corrupted.";
            return;
        }

        try
        {
            // 获取实际的CPU数量
            int cpu_count = std::thread::hardware_concurrency();

            // 处理每个 CPU 列（跳过第0列，即标题列）
            for (int i = 1; i <= cpu_count && i < softirq[0].size(); ++i)
            {
                std::string cpu_name = softirq[0][i];
                struct SoftIrq info;
                info.cpu_name = cpu_name;
                info.hi = std::stoll(softirq[1][i]);
                info.timer = std::stoll(softirq[2][i]);
                info.net_tx = std::stoll(softirq[3][i]);
                info.net_rx = std::stoll(softirq[4][i]);
                info.block = std::stoll(softirq[5][i]);
                info.irq_poll = std::stoll(softirq[6][i]);
                info.tasklet = std::stoll(softirq[7][i]);
                info.sched = std::stoll(softirq[8][i]);
                info.hrtimer = std::stoll(softirq[9][i]);
                info.rcu = std::stoll(softirq[10][i]);
                info.timepoint = boost::chrono::steady_clock::now();

                // 在映射中更新或添加新条目
                auto iter = cpu_softirqs_.find(cpu_name);
                if (iter != cpu_softirqs_.end())
                {
                    struct SoftIrq &old = (*iter).second;
                    double period = Utils::SteadyTimeSecond(info.timepoint, old.timepoint);
                    if (period > 0)
                    {
                        updateMonitorInfo(info, old, period, monitor_info);
                    }
                    old = info; // 使用当前数据更新旧数据
                }
                else
                {
                    cpu_softirqs_[cpu_name] = info;
                }
            }
        }
        catch (const std::exception &e)
        {
            LOG(ERROR) << "Error processing softirq data: " << e.what();
        }

        LOG(INFO) << "The CPU soft interrupt monitoring information is updated.";
    }

    // 更新监控信息
    void CpuSoftIrqMonitor::updateMonitorInfo(const SoftIrq &info, const SoftIrq &old, double period, linux_Monitor::MonitorInfo *monitor_info)
    {
        auto one_softirq_msg = monitor_info->add_soft_irq();
        one_softirq_msg->set_cpu(info.cpu_name);
        one_softirq_msg->set_hi((info.hi - old.hi) / period);
        one_softirq_msg->set_timer((info.timer - old.timer) / period);
        one_softirq_msg->set_net_tx((info.net_tx - old.net_tx) / period);
        one_softirq_msg->set_net_rx((info.net_rx - old.net_rx) / period);
        one_softirq_msg->set_block((info.block - old.block) / period);
        one_softirq_msg->set_irq_poll((info.irq_poll - old.irq_poll) / period);
        one_softirq_msg->set_tasklet((info.tasklet - old.tasklet) / period);
        one_softirq_msg->set_sched((info.sched - old.sched) / period);
        one_softirq_msg->set_hrtimer((info.hrtimer - old.hrtimer) / period);
        one_softirq_msg->set_rcu((info.rcu - old.rcu) / period);
    }
} // namespace linux_Monitor
