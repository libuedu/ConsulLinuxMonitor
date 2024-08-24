#include <memory>
#include <thread>
#include <string>
#include <vector>
#include "common.h"
#include "myLog.h"
#include "rpc_client.h"
#include "monitorFactory.h"
#include "monitor_info.grpc.pb.h"
#include "monitor_info.pb.h"
#include <ifaddrs.h>
#include <arpa/inet.h>

std::string GetLocalIPAddress()
{
    struct ifaddrs *ifap, *ifa;
    struct sockaddr_in *sa;
    char *addr;
    std::string ipAddress = "127.0.0.1"; // 默认 IP

    getifaddrs(&ifap);
    for (ifa = ifap; ifa; ifa = ifa->ifa_next)
    {
        if (ifa->ifa_addr && ifa->ifa_addr->sa_family == AF_INET)
        {
            sa = (struct sockaddr_in *)ifa->ifa_addr;
            addr = inet_ntoa(sa->sin_addr);
            if (strcmp(ifa->ifa_name, "lo") != 0) // 忽略本地回环地址
            {
                ipAddress = addr;
                break;
            }
        }
    }

    freeifaddrs(ifap);
    return ipAddress;
}
int main()
{
    std::vector<std::shared_ptr<linux_Monitor::MonitorInter>> runners_;
    runners_.push_back(linux_Monitor::MonitorFactory::CreateMonitor("CpuSoftIrq"));
    runners_.push_back(linux_Monitor::MonitorFactory::CreateMonitor("CpuLoad"));
    runners_.push_back(linux_Monitor::MonitorFactory::CreateMonitor("CpuStat"));
    runners_.push_back(linux_Monitor::MonitorFactory::CreateMonitor("Mem"));
    runners_.push_back(linux_Monitor::MonitorFactory::CreateMonitor("Net"));

    Common common;
    std::string log_path = common.get_log_path();
    MyLog *myLog = new MyLog(log_path, "common");

    LOG(INFO) << "Log Hello World!!!";

    std::string ipAddress = GetLocalIPAddress();
    std::string serviceName = "grpc-monitor-" + ipAddress;
    // 假设服务名为 "grpc-monitor"，您需要根据实际注册的名称进行修改
    linux_Monitor::RpcClient rpc_client_(serviceName);
    char *name = getenv("USER");
    // std::cout << "Used";
    std::unique_ptr<std::thread> thread_ = std::make_unique<std::thread>([&]()
                                                                         {
        while (true)
        {
            linux_Monitor::MonitorInfo monitor_info;
            monitor_info.set_name(std::string(name ? name : "unknown"));
            for (auto &runner : runners_)
            {
                runner->UpdateOnce(&monitor_info);
            }

            rpc_client_.SetMonitorInfo(monitor_info);
            std::this_thread::sleep_for(std::chrono::seconds(3));
        } });

    thread_->join();
    delete myLog;
    return 0;
}
