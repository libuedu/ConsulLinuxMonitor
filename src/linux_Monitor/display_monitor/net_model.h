#pragma once

#include <QAbstractTableModel>
#include <vector>
#include "monitor_inter.h"

#include "monitor_info.grpc.pb.h"
#include "monitor_info.pb.h"

namespace linux_Monitor
{
    // NetModel �����ڱ�ʾ����״̬������ģ��
    class NetModel : public MonitorInterModel
    {
        Q_OBJECT

    public:
        explicit NetModel(QObject *parent = nullptr);

        virtual ~NetModel() {}

        // ���ر�������
        int rowCount(const QModelIndex &parent = QModelIndex()) const override;
        // ���ر�������
        int columnCount(const QModelIndex &parent = QModelIndex()) const override;
        // ����ָ����Ԫ�������
        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
        // ���ر�ͷ������
        QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

        // ���¼����Ϣ
        void UpdateMonitorInfo(const linux_Monitor::MonitorInfo &monitor_info);

    signals:
        // �����ݱ仯ʱ�����ź�
        void dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles);

    private:
        // ������������Ϣ���뵽�����б���
        std::vector<QVariant> insert_one_net_info(const linux_Monitor::NetInfo &net_info);
        // �洢������ݵĶ�ά����
        std::vector<std::vector<QVariant>> monitor_data_;
        // ��ͷ��Ϣ�б�
        QStringList header_;

        // ����������Ϣ����ö��
        enum NetModelInfo
        {
            NAME = 0,
            SEND_RATE,
            RCV_RATE,
            SEND_PACKETS_RATE,
            RCV_PACKETS_RATE,
            COLUMN_MAX
        };
    };

} // namespace linux_Monitor