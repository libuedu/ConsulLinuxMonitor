#include <QColor>
#include <QFont>

#include "monitor_inter.h"

namespace linux_Monitor
{
    // 自定义表头数据
    QVariant MonitorInterModel::headerData(int section, Qt::Orientation orientation,
                                           int role) const
    {
        if (role == Qt::FontRole)
        {
            // 设置表头字体
            return QVariant::fromValue(QFont("Microsoft YaHei", 10, QFont::Bold));
        }

        if (role == Qt::BackgroundRole)
        {
            // 设置表头背景色
            return QVariant::fromValue(QColor(Qt::lightGray));
        }

        // 调用基类的 headerData
        return QAbstractTableModel::headerData(section, orientation, role);
    }

    // 自定义单元格数据显示
    QVariant MonitorInterModel::data(const QModelIndex &index, int role) const
    {
        if (role == Qt::TextAlignmentRole)
        {
            // 设置文本对齐方式
            return QVariant(Qt::AlignLeft | Qt::AlignVCenter);
        }

        if (role == Qt::TextColorRole)
        {
            // 设置文本颜色
            return QVariant::fromValue(QColor(Qt::black));
        }

        if (role == Qt::BackgroundRole)
        {
            // 设置单元格背景色
            return QVariant::fromValue(QColor(Qt::white));
        }

        // 若无数据可用，返回空的 QVariant
        return QVariant();
    }

} // namespace linux_Monitor