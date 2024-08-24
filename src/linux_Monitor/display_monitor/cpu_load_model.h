#pragma once

#include <QAbstractTableModel>
#include <vector>
#include "monitor_inter.h"

#include "monitor_info.grpc.pb.h"
#include "monitor_info.pb.h"

namespace linux_Monitor
{
    // CpuLoadModel 类提供了CPU负载数据的表格模型
    class CpuLoadModel : public MonitorInterModel
    {
        Q_OBJECT

    public:
        explicit CpuLoadModel(QObject *parent = nullptr);

        virtual ~CpuLoadModel() {}

        // 获取行数
        int rowCount(const QModelIndex &parent = QModelIndex()) const override;
        // 获取列数
        int columnCount(const QModelIndex &parent = QModelIndex()) const override;
        // 获取数据
        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
        // 获取表头数据
        QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

        // 更新监控信息
        void UpdateMonitorInfo(const linux_Monitor::MonitorInfo &monitor_info);

    signals:
        // 数据改变信号
        void dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight,
                         const QVector<int> &roles);

    private:
        // 插入单个CPU负载数据
        std::vector<QVariant> insert_one_cpu_load(const linux_Monitor::CpuLoad &cpu_load);
        // 存储监控数据
        std::vector<std::vector<QVariant>> monitor_data_;
        // 表头数据
        QStringList header_;

        // 定义CPU负载数据的列枚举
        enum CpuLoad
        {
            CPU_AVG_1 = 0,
            CPU_AVG_3,
            CPU_AVG_15,
            COLUMN_MAX
        };
    };

} // namespace linux_Monitor