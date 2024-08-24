#include "cpu_stat_model.h"

namespace linux_Monitor
{
    CpuStatModel::CpuStatModel(QObject *parent) : MonitorInterModel(parent)
    {
        // ��ʼ����ͷ��Ϣ
        header_ << tr("name");
        header_ << tr("cpu_percent");
        header_ << tr("user");
        header_ << tr("system");
    }

    int CpuStatModel::rowCount(const QModelIndex &parent) const
    {
        return monitor_data_.size();
    }

    int CpuStatModel::columnCount(const QModelIndex &parent) const
    {
        return COLUMN_MAX;
    }

    QVariant CpuStatModel::headerData(int section, Qt::Orientation orientation, int role) const
    {
        if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
        {
            return header_[section];
        }

        return MonitorInterModel::headerData(section, orientation, role);
    }

    QVariant CpuStatModel::data(const QModelIndex &index, int role) const
    {
        if (index.row() < 0 || index.row() >= monitor_data_.size() || index.column() < 0 || index.column() >= COLUMN_MAX)
        {
            return QVariant(); // ��ֹԽ�����
        }

        if (role == Qt::DisplayRole)
        {
            return monitor_data_[index.row()][index.column()];
        }
        return QVariant();
    }

    void CpuStatModel::UpdateMonitorInfo(const linux_Monitor::MonitorInfo &monitor_info)
    {
        beginResetModel();
        monitor_data_.clear();

        for (int i = 0; i < monitor_info.cpu_stat_size(); i++)
        {
            monitor_data_.push_back(insert_one_cpu_stat(monitor_info.cpu_stat(i)));
        }

        endResetModel();
    }

    std::vector<QVariant> CpuStatModel::insert_one_cpu_stat(const linux_Monitor::CpuStat &cpu_stat)
    {
        std::vector<QVariant> cpu_stat_list;
        for (int i = CpuStat::CPU_NAME; i < COLUMN_MAX; i++)
        {
            switch (i)
            {
            case CpuStat::CPU_NAME:
                cpu_stat_list.push_back(QString::fromStdString(cpu_stat.cpu_name()));
                break;
            case CpuStat::CPU_PERCENT:
                cpu_stat_list.push_back(QVariant(cpu_stat.cpu_percent()));
                break;
            case CpuStat::CPU_USER_PERCENT:
                cpu_stat_list.push_back(QVariant(cpu_stat.usr_percent()));
                break;
            case CpuStat::CPU_SYSTEM_PERCENT:
                cpu_stat_list.push_back(QVariant(cpu_stat.system_percent()));
                break;
            default:
                break;
            }
        }
        return cpu_stat_list;
    }
} // namespace linux_Monitor