#pragma once

#include <QAbstractTableModel>
#include <vector>
#include "monitor_inter.h"

#include "monitor_info.grpc.pb.h"
#include "monitor_info.pb.h"

namespace linux_Monitor
{
    // NetModel 类用于表示网络状态的数据模型
    class NetModel : public MonitorInterModel
    {
        Q_OBJECT

    public:
        explicit NetModel(QObject *parent = nullptr);

        virtual ~NetModel() {}

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
        // 将单个网络信息插入到数据列表中
        std::vector<QVariant> insert_one_net_info(const linux_Monitor::NetInfo &net_info);
        // 存储监控数据的二维向量
        std::vector<std::vector<QVariant>> monitor_data_;
        // 表头信息列表
        QStringList header_;

        // 定义网络信息的列枚举
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