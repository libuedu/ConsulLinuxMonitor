#include "net_monitor.h"
#include "read_file.h"
#include "utils.h"
#include "common.h"
#include "myLog.h" // 包含您的日志库头文件

namespace linux_Monitor
{
    void NetMonitor::UpdateOnce(linux_Monitor::MonitorInfo *monitor_info)
    {
        ReadFile net_file("/proc/net/dev");
        std::vector<std::string> net_datas;
        while (net_file.ReadLine(&net_datas))
        {
            // 检查网络接口数据行的格式
            if (net_datas.size() >= 10 && !net_datas[0].empty() && net_datas[0].find(':') != std::string::npos)
            {
                struct NetInfo net_info;
                std::string name = net_datas[0].substr(0, net_datas[0].find(':'));
                net_info.name = name;
                try
                {
                    // 解析网络接口数据
                    net_info.rcv_bytes = std::stoll(net_datas[1]);
                    net_info.rcv_packets = std::stoll(net_datas[2]);
                    net_info.err_in = std::stoll(net_datas[3]);
                    net_info.drop_in = std::stoll(net_datas[4]);
                    net_info.snd_bytes = std::stoll(net_datas[9]);
                    net_info.snd_packets = std::stoll(net_datas[10]);
                    net_info.err_out = std::stoll(net_datas[11]);
                    net_info.drop_out = std::stoll(net_datas[12]);
                    net_info.timepoint = boost::chrono::steady_clock::now();

                    // 更新或添加网络信息
                    auto iter = net_info_.find(name);
                    if (iter != net_info_.end())
                    {
                        struct NetInfo old = std::move(iter->second);
                        double period = Utils::SteadyTimeSecond(net_info.timepoint, old.timepoint);
                        if (period > 0)
                        {
                            UpdateNetworkMetrics(iter->second, net_info, period, monitor_info);
                        }
                        iter->second = net_info; // 更新存储的网络信息
                    }
                    else
                    {
                        net_info_[name] = net_info; // 新网络接口
                    }
                }
                catch (const std::exception &e)
                {
                    LOG(ERROR) << "Parse network data anomalies: " << e.what() << ", Interface:" << name;
                }
            }
            else
            {
                LOG(WARNING) << "Invalid network data rows:" << net_datas[0];
            }
            net_datas.clear();
        }

        LOG(INFO) << "The network monitoring information is updated.";
    }

    void NetMonitor::UpdateNetworkMetrics(const NetInfo &old_info, const NetInfo &new_info, double period,
                                          linux_Monitor::MonitorInfo *monitor_info)
    {
        auto one_net_msg = monitor_info->add_net_info();
        one_net_msg->set_name(new_info.name);
        one_net_msg->set_send_rate((new_info.snd_bytes - old_info.snd_bytes) / 1024.0 / period);
        one_net_msg->set_rcv_rate((new_info.rcv_bytes - old_info.rcv_bytes) / 1024.0 / period);
        one_net_msg->set_send_packets_rate((new_info.snd_packets - old_info.snd_packets) / period);
        one_net_msg->set_rcv_packets_rate((new_info.rcv_packets - old_info.rcv_packets) / period);
    }

} // namespace monitor
