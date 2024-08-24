#pragma once
#include <QAbstractTableModel>
#include <QObject>

namespace linux_Monitor
{
    // MonitorInterModel �ṩ�˼������ģ�͵Ļ��ࡣ
    class MonitorInterModel : public QAbstractTableModel
    {
        Q_OBJECT

    public:
        // ��ʽ���캯��
        explicit MonitorInterModel(QObject *parent = nullptr)
            : QAbstractTableModel(parent) {}

        // ���� data �������ṩ�ض���Ԫ�������
        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

        // ���� headerData �������Զ����ͷ���
        QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

        // ��������
        virtual ~MonitorInterModel() {}
    };

} // namespace linux_Monitor