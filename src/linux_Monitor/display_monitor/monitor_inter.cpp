#include <QColor>
#include <QFont>

#include "monitor_inter.h"

namespace linux_Monitor
{
    // �Զ����ͷ����
    QVariant MonitorInterModel::headerData(int section, Qt::Orientation orientation,
                                           int role) const
    {
        if (role == Qt::FontRole)
        {
            // ���ñ�ͷ����
            return QVariant::fromValue(QFont("Microsoft YaHei", 10, QFont::Bold));
        }

        if (role == Qt::BackgroundRole)
        {
            // ���ñ�ͷ����ɫ
            return QVariant::fromValue(QColor(Qt::lightGray));
        }

        // ���û���� headerData
        return QAbstractTableModel::headerData(section, orientation, role);
    }

    // �Զ��嵥Ԫ��������ʾ
    QVariant MonitorInterModel::data(const QModelIndex &index, int role) const
    {
        if (role == Qt::TextAlignmentRole)
        {
            // �����ı����뷽ʽ
            return QVariant(Qt::AlignLeft | Qt::AlignVCenter);
        }

        if (role == Qt::TextColorRole)
        {
            // �����ı���ɫ
            return QVariant::fromValue(QColor(Qt::black));
        }

        if (role == Qt::BackgroundRole)
        {
            // ���õ�Ԫ�񱳾�ɫ
            return QVariant::fromValue(QColor(Qt::white));
        }

        // �������ݿ��ã����ؿյ� QVariant
        return QVariant();
    }

} // namespace linux_Monitor