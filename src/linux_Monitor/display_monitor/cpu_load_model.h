#pragma once

#include <QAbstractTableModel>
#include <vector>
#include "monitor_inter.h"

#include "monitor_info.grpc.pb.h"
#include "monitor_info.pb.h"

namespace linux_Monitor
{
    // CpuLoadModel ���ṩ��CPU�������ݵı��ģ��
    class CpuLoadModel : public MonitorInterModel
    {
        Q_OBJECT

    public:
        explicit CpuLoadModel(QObject *parent = nullptr);

        virtual ~CpuLoadModel() {}

        // ��ȡ����
        int rowCount(const QModelIndex &parent = QModelIndex()) const override;
        // ��ȡ����
        int columnCount(const QModelIndex &parent = QModelIndex()) const override;
        // ��ȡ����
        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
        // ��ȡ��ͷ����
        QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

        // ���¼����Ϣ
        void UpdateMonitorInfo(const linux_Monitor::MonitorInfo &monitor_info);

    signals:
        // ���ݸı��ź�
        void dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight,
                         const QVector<int> &roles);

    private:
        // ���뵥��CPU��������
        std::vector<QVariant> insert_one_cpu_load(const linux_Monitor::CpuLoad &cpu_load);
        // �洢�������
        std::vector<std::vector<QVariant>> monitor_data_;
        // ��ͷ����
        QStringList header_;

        // ����CPU�������ݵ���ö��
        enum CpuLoad
        {
            CPU_AVG_1 = 0,
            CPU_AVG_3,
            CPU_AVG_15,
            COLUMN_MAX
        };
    };

} // namespace linux_Monitor