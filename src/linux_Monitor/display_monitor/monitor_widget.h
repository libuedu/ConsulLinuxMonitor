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
            // ����ж��̲߳�����Ҫֹͣ���������ڴ˴�����
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
        void onServiceSelected(const QString &serviceName); // ѡ�����Ĳۺ���
        void onServiceListReceived(QNetworkReply *reply);   // ���շ����б�Ĳۺ���

    private:
        void fetchServiceList();                            // ��ȡ�����б�
        void updateDataModel(const QString &serviceName);   // ��������ģ��
        void updateButtonNames(const QString &serviceName); // ���°�ť����

        QComboBox *serviceComboBox_;            // ����ѡ��������
        QNetworkAccessManager *networkManager_; // ����HTTP����
        QTimer *serviceRefreshTimer_;           // ����ˢ�·����б�ļ�ʱ��

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

        QPushButton *cpu_button_;      // CPU��ذ�ť
        QPushButton *soft_irq_button_; // ���жϼ�ذ�ť
        QPushButton *mem_button_;      // �ڴ��ذ�ť
        QPushButton *net_button_;      // �����ذ�ť
        QWidget *buttonMenu_;          // ��ť�˵�
    };

} // namespace linux_Monitor
