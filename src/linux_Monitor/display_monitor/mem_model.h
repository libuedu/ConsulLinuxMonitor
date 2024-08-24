#pragma once

#include <QAbstractTableModel>
#include <vector>
#include "monitor_inter.h"

#include "monitor_info.grpc.pb.h"
#include "monitor_info.pb.h"

namespace linux_Monitor
{
    // MemModel �����ڱ�ʾ�ڴ�״̬������ģ��
    class MemModel : public MonitorInterModel
    {
        Q_OBJECT

    public:
        explicit MemModel(QObject *parent = nullptr);

        virtual ~MemModel() {}

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
        // �������ڴ���Ϣ���뵽�����б���
        std::vector<QVariant> insert_one_mem_info(const linux_Monitor::MemInfo &mem_info);
        // �洢������ݵĶ�ά����
        std::vector<std::vector<QVariant>> monitor_data_;
        // ��ͷ��Ϣ�б�
        QStringList header_;

        // �����ڴ���Ϣ����ö��
        enum MemInfo
        {
            USED_PERCENT = 0,
            TOTAL,
            FREE,
            AVAIL,
            BUFFERS,
            CACHED,
            SWAP_CACHED,
            ACTIVE,
            INACTIVE,
            ACTIVE_ANON,
            INACTIVE_ANON,
            DIRTY,
            WRITEBACK,
            ANON_PAGES,
            MAPPED,
            KRECLAIMABLE,
            SRECLAIMABLE,
            SUNRECLAIM,
            COLUMN_MAX
        };
    };

} // namespace linux_Monitor