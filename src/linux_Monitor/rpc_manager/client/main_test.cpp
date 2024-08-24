#include <iostream>
#include "rpc_client.h"
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

int main(int argc, char *argv[])
{
    try
    {
        std::string ipAddress = GetLocalIPAddress();
        std::string serviceName = "grpc-monitor-" + ipAddress;
        // 假设服务名为 "grpc-monitor"，您需要根据实际注册的名称进行修改
        linux_Monitor::RpcClient rpc_client(serviceName);

        // 执行健康检查并输出结果
        std::string health_status = rpc_client.CheckHealth();
        std::cout << "Health Check Status: " << health_status << std::endl;

        // 设置监控信息
        linux_Monitor::MonitorInfo monitor_info;
        auto soft_irq = monitor_info.add_soft_irq();
        soft_irq->set_cpu("cpu1");
        auto soft_irq2 = monitor_info.add_soft_irq();
        soft_irq2->set_cpu("cpu2");

        // 调用 RPC 方法
        rpc_client.SetMonitorInfo(monitor_info);
        std::cout << "Monitor info successfully set." << std::endl;

        // 可以选择获取监控信息以验证
        linux_Monitor::MonitorInfo received_info;
        rpc_client.GetMonitorInfo(&received_info);
        std::cout << "Received monitor info for CPU: " << received_info.soft_irq(0).cpu() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception encountered: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}
