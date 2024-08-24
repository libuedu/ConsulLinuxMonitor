#pragma once

#include <QStandardItemModel>
#include <QtWidgets>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTimer>
#include <string>

#include "cpu_load_model.h"
#include "cpu_softirq_model.h"
#include "cpu_stat_model.h"
#include "mem_model.h"
#include "net_model.h"
#include "rpc_client.h"

#include "monitor_info.grpc.pb.h"
#include "monitor_info.pb.h"

namespace linux_Monitor
{
    class MonitorWidget : public QWidget
    {
        Q_OBJECT
    public:
        explicit MonitorWidget(QWidget *parent = nullptr);
        ~MonitorWidget()
        {
            // 如果有多线程操作需要停止和清理，请在此处处理
        }

        QWidget *ShowAllMonitorWidget(const std::string &name);
        QWidget *InitCpuMonitorWidget();
        QWidget *InitSoftIrqMonitorWidget();
        QWidget *InitMemMonitorWidget();
        QWidget *InitNetMonitorWidget();
        QWidget *InitButtonMenu(const std::string &name);

        void UpdateData(const linux_Monitor::MonitorInfo &monitor_info);
        QComboBox *getServiceComboBox() const { return serviceComboBox_; }

    private slots:
        void ClickCpuButton();
        void ClickSoftIrqButton();
        void ClickMemButton();
        void ClickNetButton();
        void onServiceSelected(const QString &serviceName); // 选择服务的槽函数
        void onServiceListReceived(QNetworkReply *reply);   // 接收服务列表的槽函数

    private:
        void fetchServiceList();                            // 获取服务列表
        void updateDataModel(const QString &serviceName);   // 更新数据模型
        void updateButtonNames(const QString &serviceName); // 更新按钮名称

        QComboBox *serviceComboBox_;            // 服务选择下拉框
        QNetworkAccessManager *networkManager_; // 用于HTTP请求
        QTimer *serviceRefreshTimer_;           // 定期刷新服务列表的计时器

        QTableView *monitor_view_ = nullptr;
        QTableView *cpu_load_monitor_view_ = nullptr;
        QTableView *cpu_stat_monitor_view_ = nullptr;
        QTableView *mem_monitor_view_ = nullptr;
        QTableView *net_monitor_view_ = nullptr;

        CpuSoftirqModel *cpu_softirq_model_ = nullptr;
        CpuLoadModel *cpu_load_model_ = nullptr;
        CpuStatModel *cpu_stat_model_ = nullptr;
        MemModel *mem_model_ = nullptr;
        NetModel *net_model_ = nullptr;

        QStackedLayout *stack_menu_ = nullptr;

        QPushButton *cpu_button_;      // CPU监控按钮
        QPushButton *soft_irq_button_; // 软中断监控按钮
        QPushButton *mem_button_;      // 内存监控按钮
        QPushButton *net_button_;      // 网络监控按钮
        QWidget *buttonMenu_;          // 按钮菜单
    };

} // namespace linux_Monitor
