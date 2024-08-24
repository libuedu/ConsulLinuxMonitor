#pragma once

#include <QAbstractTableModel>
#include <vector>
#include "monitor_inter.h"

#include "monitor_info.grpc.pb.h"
#include "monitor_info.pb.h"

namespace linux_Monitor
{
    // CpuStatModel �����ڱ�ʾCPU״̬������ģ��
    class CpuStatModel : public MonitorInterModel
    {
        Q_OBJECT

    public:
        explicit CpuStatModel(QObject *parent = nullptr);

        virtual ~CpuStatModel() {}

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
        // ������CPU״̬��Ϣ���뵽�����б���
        std::vector<QVariant> insert_one_cpu_stat(const linux_Monitor::CpuStat &cpu_stat);
        // �洢������ݵĶ�ά����
        std::vector<std::vector<QVariant>> monitor_data_;
        // ��ͷ��Ϣ�б�
        QStringList header_;

        // ����CPU״̬��Ϣ����ö��
        enum CpuStat
        {
            CPU_NAME = 0,
            CPU_PERCENT,
            CPU_USER_PERCENT,
            CPU_SYSTEM_PERCENT,
            COLUMN_MAX
        };
    };

} // namespace linux_Monitor