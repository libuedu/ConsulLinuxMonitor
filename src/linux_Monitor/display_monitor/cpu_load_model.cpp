#include "cpu_load_model.h"

namespace linux_Monitor
{
    CpuLoadModel::CpuLoadModel(QObject *parent) : MonitorInterModel(parent)
    {
        header_ << tr("load_1");
        header_ << tr("load_3");
        header_ << tr("load_15");
    }

    int CpuLoadModel::rowCount(const QModelIndex &parent) const
    {
        return monitor_data_.size();
    }

    int CpuLoadModel::columnCount(const QModelIndex &parent) const
    {
        return COLUMN_MAX;
    }

    QVariant CpuLoadModel::headerData(int section, Qt::Orientation orientation,
                                      int role) const
    {
        if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
        {
            return header_[section];
        }

        return MonitorInterModel::headerData(section, orientation, role);
    }

    QVariant CpuLoadModel::data(const QModelIndex &index, int role) const
    {
        if (index.row() >= monitor_data_.size() || index.row() < 0)
        {
            return QVariant(); // 确保不越界
        }

        if (role == Qt::DisplayRole)
        {
            return monitor_data_[index.row()][index.column()];
        }
        return QVariant();
    }

    void CpuLoadModel::UpdateMonitorInfo(
        const linux_Monitor::MonitorInfo &monitor_info)
    {
        beginResetModel();
        monitor_data_.clear();

        monitor_data_.push_back(insert_one_cpu_load(monitor_info.cpu_load()));
        endResetModel();
    }

    std::vector<QVariant> CpuLoadModel::insert_one_cpu_load(
        const linux_Monitor::CpuLoad &cpu_load)
    {
        std::vector<QVariant> cpu_load_list;
        for (int i = CpuLoad::CPU_AVG_1; i < COLUMN_MAX; i++)
        {
            switch (i)
            {
            case CpuLoad::CPU_AVG_1:
                cpu_load_list.push_back(QVariant(cpu_load.load_avg_1()));
                break;
            case CpuLoad::CPU_AVG_3:
                cpu_load_list.push_back(QVariant(cpu_load.load_avg_3()));
                break;
            case CpuLoad::CPU_AVG_15:
                cpu_load_list.push_back(QVariant(cpu_load.load_avg_15()));
                break;
            default:
                break;
            }
        }
        return cpu_load_list;
    }
} // namespace linux_Monitor