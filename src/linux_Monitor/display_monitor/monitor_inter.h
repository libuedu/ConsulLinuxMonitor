#pragma once
#include <QAbstractTableModel>
#include <QObject>

namespace linux_Monitor
{
    // MonitorInterModel 提供了监控数据模型的基类。
    class MonitorInterModel : public QAbstractTableModel
    {
        Q_OBJECT

    public:
        // 显式构造函数
        explicit MonitorInterModel(QObject *parent = nullptr)
            : QAbstractTableModel(parent) {}

        // 覆盖 data 方法以提供特定单元格的内容
        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

        // 覆盖 headerData 方法以自定义表头外观
        QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

        // 析构函数
        virtual ~MonitorInterModel() {}
    };

} // namespace linux_Monitor