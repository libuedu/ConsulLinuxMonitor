#include <QApplication>
#include <thread>
#include <memory>
#include "monitor_widget.h"
#include "rpc_client.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // ��ʼ�� MonitorWidget
    linux_Monitor::MonitorWidget monitor_widget;
    monitor_widget.show();

    std::unique_ptr<std::thread> data_thread;
    data_thread = std::make_unique<std::thread>([&]()
                                                {
        linux_Monitor::MonitorInfo monitor_info;

        while (true) {
            // ��ȡѡ���ķ�������
            QString selectedService = monitor_widget.getServiceComboBox()->currentText();
            if (selectedService.isEmpty()) {
                std::this_thread::sleep_for(std::chrono::seconds(2));
                continue;
            }

            try {
                // ʹ�÷������Ƴ�ʼ��RpcClient���ڲ�����з����֣�
                linux_Monitor::RpcClient rpc_client(selectedService.toStdString());
                monitor_info.Clear();
                rpc_client.GetMonitorInfo(&monitor_info);

                monitor_widget.UpdateData(monitor_info);
            } catch (const std::exception &e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }

            std::this_thread::sleep_for(std::chrono::seconds(2));
        } });

    data_thread->detach();

    return app.exec();
}