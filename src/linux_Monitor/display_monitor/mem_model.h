#pragma once

#include <QAbstractTableModel>
#include <vector>
#include "monitor_inter.h"

#include "monitor_info.grpc.pb.h"
#include "monitor_info.pb.h"

namespace linux_Monitor
{
    // MemModel 类用于表示内存状态的数据模型
    class MemModel : public MonitorInterModel
    {
        Q_OBJECT

    public:
        explicit MemModel(QObject *parent = nullptr);

        virtual ~MemModel() {}

        // 返回表格的行数
        int rowCount(const QModelIndex &parent = QModelIndex()) const override;
        // 返回表格的列数
        int columnCount(const QModelIndex &parent = QModelIndex()) const override;
        // 返回指定单元格的数据
        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
        // 返回表头的数据
        QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

        // 更新监控信息
        void UpdateMonitorInfo(const linux_Monitor::MonitorInfo &monitor_info);

    signals:
        // 当数据变化时发出信号
        void dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles);

    private:
        // 将单个内存信息插入到数据列表中
        std::vector<QVariant> insert_one_mem_info(const linux_Monitor::MemInfo &mem_info);
        // 存储监控数据的二维向量
        std::vector<std::vector<QVariant>> monitor_data_;
        // 表头信息列表
        QStringList header_;

        // 定义内存信息的列枚举
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