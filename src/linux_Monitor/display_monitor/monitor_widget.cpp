#include "monitor_widget.h"
#include <QDebug>

namespace linux_Monitor
{

    MonitorWidget::MonitorWidget(QWidget *parent) : QWidget(parent), networkManager_(new QNetworkAccessManager(this))
    {
        // ����ѡ��������
        serviceComboBox_ = new QComboBox(this);
        connect(serviceComboBox_, SIGNAL(currentTextChanged(const QString &)), this, SLOT(onServiceSelected(const QString &)));

        QVBoxLayout *mainLayout = new QVBoxLayout(this);
        mainLayout->addWidget(serviceComboBox_); // ������ѡ����������ӵ�������

        // ��ʼ����ť�˵�
        buttonMenu_ = InitButtonMenu("Select a Service");
        mainLayout->addWidget(buttonMenu_);

        // ��ʼ��������ش���
        stack_menu_ = new QStackedLayout();
        stack_menu_->addWidget(InitCpuMonitorWidget());
        stack_menu_->addWidget(InitSoftIrqMonitorWidget());
        stack_menu_->addWidget(InitMemMonitorWidget());
        stack_menu_->addWidget(InitNetMonitorWidget());
        mainLayout->addLayout(stack_menu_);

        setLayout(mainLayout); // ����������

        // ����ˢ�·����б�
        serviceRefreshTimer_ = new QTimer(this);
        connect(serviceRefreshTimer_, &QTimer::timeout, this, &MonitorWidget::fetchServiceList);
        serviceRefreshTimer_->start(5000); // ÿ5��ˢ��һ�η����б�

        // ��ʼ����ȡ�����б�
        fetchServiceList();
    }

    QWidget *MonitorWidget::ShowAllMonitorWidget(const std::string &name)
    {
        QWidget *widget = new QWidget();
        stack_menu_ = new QStackedLayout();
        stack_menu_->addWidget(InitCpuMonitorWidget());
        stack_menu_->addWidget(InitSoftIrqMonitorWidget());
        stack_menu_->addWidget(InitMemMonitorWidget());
        stack_menu_->addWidget(InitNetMonitorWidget());

        QGridLayout *layout = new QGridLayout(this);
        layout->addWidget(InitButtonMenu(name), 1, 0);
        layout->addLayout(stack_menu_, 2, 0);
        widget->setLayout(layout);
        return widget;
    }

    QWidget *MonitorWidget::InitButtonMenu(const std::string &name)
    {
        // ������ť
        cpu_button_ = new QPushButton(QString::fromStdString(name) + "_cpu", this);
        soft_irq_button_ = new QPushButton(QString::fromStdString(name) + "_soft_irq", this);
        mem_button_ = new QPushButton(QString::fromStdString(name) + "_mem", this);
        net_button_ = new QPushButton(QString::fromStdString(name) + "_net", this);

        QFont *font = new QFont("Microsoft YaHei", 15, 40);
        cpu_button_->setFont(*font);
        soft_irq_button_->setFont(*font);
        mem_button_->setFont(*font);
        net_button_->setFont(*font);

        QHBoxLayout *layout = new QHBoxLayout();
        layout->addWidget(cpu_button_);
        layout->addWidget(soft_irq_button_);
        layout->addWidget(mem_button_);
        layout->addWidget(net_button_);

        QWidget *widget = new QWidget();
        widget->setLayout(layout);

        // ��ť������Ӳۺ���
        connect(cpu_button_, &QPushButton::clicked, this, &MonitorWidget::ClickCpuButton);
        connect(soft_irq_button_, &QPushButton::clicked, this, &MonitorWidget::ClickSoftIrqButton);
        connect(mem_button_, &QPushButton::clicked, this, &MonitorWidget::ClickMemButton);
        connect(net_button_, &QPushButton::clicked, this, &MonitorWidget::ClickNetButton);

        return widget;
    }

    QWidget *MonitorWidget::InitCpuMonitorWidget()
    {
        QWidget *widget = new QWidget();

        QLabel *cpu_load_label = new QLabel(this);
        cpu_load_label->setText(tr("Monitor CpuLoad:"));
        cpu_load_label->setFont(QFont("Microsoft YaHei", 10, 40));

        cpu_load_monitor_view_ = new QTableView;
        cpu_load_model_ = new CpuLoadModel;
        cpu_load_monitor_view_->setModel(cpu_load_model_);
        cpu_load_monitor_view_->show();

        QLabel *cpu_stat_label = new QLabel(this);
        cpu_stat_label->setText(tr("Monitor CpuStat:"));
        cpu_stat_label->setFont(QFont("Microsoft YaHei", 10, 40));

        cpu_stat_monitor_view_ = new QTableView;
        cpu_stat_model_ = new CpuStatModel;
        cpu_stat_monitor_view_->setModel(cpu_stat_model_);
        cpu_stat_monitor_view_->show();

        QGridLayout *layout = new QGridLayout();

        layout->addWidget(cpu_load_label, 3, 0);
        layout->addWidget(cpu_load_monitor_view_, 4, 0, 2, 2);

        layout->addWidget(cpu_stat_label, 1, 0, 1, 1);
        layout->addWidget(cpu_stat_monitor_view_, 2, 0, 1, 2);

        widget->setLayout(layout);
        return widget;
    }

    QWidget *MonitorWidget::InitSoftIrqMonitorWidget()
    {
        QWidget *widget = new QWidget();
        QLabel *monitor_label = new QLabel(this);
        monitor_label->setText(tr("Monitor softirq:"));
        monitor_label->setFont(QFont("Microsoft YaHei", 10, 40));

        monitor_view_ = new QTableView;
        cpu_softirq_model_ = new CpuSoftirqModel;
        QSortFilterProxyModel *sort_proxy = new QSortFilterProxyModel(this);
        sort_proxy->setSourceModel(cpu_softirq_model_);
        monitor_view_->setModel(sort_proxy);
        monitor_view_->setSortingEnabled(true);
        monitor_view_->show();

        QGridLayout *layout = new QGridLayout();
        layout->addWidget(monitor_label, 1, 0);
        layout->addWidget(monitor_view_, 2, 0, 1, 2);

        widget->setLayout(layout);
        return widget;
    }

    QWidget *MonitorWidget::InitMemMonitorWidget()
    {
        QWidget *widget = new QWidget();

        QLabel *mem_label = new QLabel(this);
        mem_label->setText(tr("Monitor mem:"));
        mem_label->setFont(QFont("Microsoft YaHei", 10, 40));

        mem_monitor_view_ = new QTableView;
        mem_model_ = new MemModel;
        mem_monitor_view_->setModel(mem_model_);
        mem_monitor_view_->show();

        QGridLayout *layout = new QGridLayout();

        layout->addWidget(mem_label, 1, 0);
        layout->addWidget(mem_monitor_view_, 2, 0, 1, 1);

        widget->setLayout(layout);
        return widget;
    }

    QWidget *MonitorWidget::InitNetMonitorWidget()
    {
        QWidget *widget = new QWidget();

        QLabel *net_label = new QLabel(this);
        net_label->setText(tr("Monitor net:"));
        net_label->setFont(QFont("Microsoft YaHei", 10, 40));

        net_monitor_view_ = new QTableView;
        net_model_ = new NetModel;
        net_monitor_view_->setModel(net_model_);
        net_monitor_view_->show();

        QGridLayout *layout = new QGridLayout();

        layout->addWidget(net_label, 1, 0);
        layout->addWidget(net_monitor_view_, 2, 0, 1, 1);

        widget->setLayout(layout);
        return widget;
    }

    void MonitorWidget::UpdateData(const linux_Monitor::MonitorInfo &monitor_info)
    {
        cpu_softirq_model_->UpdateMonitorInfo(monitor_info);
        cpu_load_model_->UpdateMonitorInfo(monitor_info);
        cpu_stat_model_->UpdateMonitorInfo(monitor_info);
        mem_model_->UpdateMonitorInfo(monitor_info);
        net_model_->UpdateMonitorInfo(monitor_info);
    }

    void MonitorWidget::ClickCpuButton()
    {
        stack_menu_->setCurrentIndex(0);
    }

    void MonitorWidget::ClickSoftIrqButton()
    {
        stack_menu_->setCurrentIndex(1);
    }

    void MonitorWidget::ClickMemButton()
    {
        stack_menu_->setCurrentIndex(2);
    }

    void MonitorWidget::ClickNetButton()
    {
        stack_menu_->setCurrentIndex(3);
    }

    void MonitorWidget::fetchServiceList()
    {
        QUrl url("http://localhost:8500/v1/catalog/services"); // Consul�����б�API
        QNetworkRequest request(url);
        connect(networkManager_, &QNetworkAccessManager::finished, this, &MonitorWidget::onServiceListReceived);
        networkManager_->get(request);
    }

    void MonitorWidget::onServiceListReceived(QNetworkReply *reply)
    {
        if (reply->error() == QNetworkReply::NoError)
        {
            QByteArray responseData = reply->readAll();
            QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
            QJsonObject jsonObj = jsonDoc.object();

            // // Debug ��������б�
            // qDebug() << "Service list received:" << jsonObj;

            if (!jsonObj.isEmpty()) // ��� JSON �Ƿ�Ϊ��
            {
                QString currentService = serviceComboBox_->currentText(); // ��¼��ǰѡ�еķ���

                // ������з����б�
                serviceComboBox_->clear();

                // �������з�������
                for (const QString &key : jsonObj.keys())
                {
                    // ֱ����ӷ�������
                    qDebug() << "Adding service to combo box:" << key;
                    serviceComboBox_->addItem(key);
                }

                // �ָ�֮ǰѡ�еķ���
                int index = serviceComboBox_->findText(currentService);
                if (index != -1)
                {
                    serviceComboBox_->setCurrentIndex(index);
                }
                else
                {
                    qDebug() << "Previously selected service no longer available.";
                }
            }
            else
            {
                qDebug() << "Received empty service list, keeping existing services.";
            }
        }
        else
        {
            qDebug() << "Failed to retrieve services:" << reply->errorString();
        }

        reply->deleteLater();
    }

    void MonitorWidget::onServiceSelected(const QString &serviceName)
    {
        qDebug() << "Service selected:" << serviceName;
        if (!serviceName.isEmpty())
        {
            updateDataModel(serviceName);
            updateButtonNames(serviceName); // ���°�ť����
        }
        else
        {
            qDebug() << "No service selected or service name is empty.";
        }
    }

    void MonitorWidget::updateButtonNames(const QString &serviceName)
    {
        // ����ѡ���ķ������Ƹ��°�ť����
        cpu_button_->setText(serviceName + "_cpu");
        soft_irq_button_->setText(serviceName + "_soft_irq");
        mem_button_->setText(serviceName + "_mem");
        net_button_->setText(serviceName + "_net");
    }

    void MonitorWidget::updateDataModel(const QString &serviceName)
    {
        try
        {
            // ʹ�÷������Ƴ�ʼ��RpcClient���ڲ�����з����֣�
            linux_Monitor::RpcClient rpc_client(serviceName.toStdString());

            // ����RPC���������ȡ�����Ϣ��
            linux_Monitor::MonitorInfo monitor_info;
            rpc_client.GetMonitorInfo(&monitor_info);
            qDebug() << "MonitorInfo received:" << QString::fromStdString(monitor_info.DebugString());
            // ��������ģ��
            this->UpdateData(monitor_info);

            qDebug() << "Successfully updated data for service:" << serviceName;
        }
        catch (const std::exception &e)
        {
            qDebug() << "Exception encountered while updating data for service:" << serviceName << ", Error:" << e.what();
        }
    }

} // namespace linux_Monitor