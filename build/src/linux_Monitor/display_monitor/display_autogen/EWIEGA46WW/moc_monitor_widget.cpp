/****************************************************************************
** Meta object code from reading C++ file 'monitor_widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "monitor_widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'monitor_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_linux_Monitor__MonitorWidget_t {
    QByteArrayData data[11];
    char stringdata0[167];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_linux_Monitor__MonitorWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_linux_Monitor__MonitorWidget_t qt_meta_stringdata_linux_Monitor__MonitorWidget = {
    {
QT_MOC_LITERAL(0, 0, 28), // "linux_Monitor::MonitorWidget"
QT_MOC_LITERAL(1, 29, 14), // "ClickCpuButton"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 18), // "ClickSoftIrqButton"
QT_MOC_LITERAL(4, 64, 14), // "ClickMemButton"
QT_MOC_LITERAL(5, 79, 14), // "ClickNetButton"
QT_MOC_LITERAL(6, 94, 17), // "onServiceSelected"
QT_MOC_LITERAL(7, 112, 11), // "serviceName"
QT_MOC_LITERAL(8, 124, 21), // "onServiceListReceived"
QT_MOC_LITERAL(9, 146, 14), // "QNetworkReply*"
QT_MOC_LITERAL(10, 161, 5) // "reply"

    },
    "linux_Monitor::MonitorWidget\0"
    "ClickCpuButton\0\0ClickSoftIrqButton\0"
    "ClickMemButton\0ClickNetButton\0"
    "onServiceSelected\0serviceName\0"
    "onServiceListReceived\0QNetworkReply*\0"
    "reply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_linux_Monitor__MonitorWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    1,   48,    2, 0x08 /* Private */,
       8,    1,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, 0x80000000 | 9,   10,

       0        // eod
};

void linux_Monitor::MonitorWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MonitorWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ClickCpuButton(); break;
        case 1: _t->ClickSoftIrqButton(); break;
        case 2: _t->ClickMemButton(); break;
        case 3: _t->ClickNetButton(); break;
        case 4: _t->onServiceSelected((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->onServiceListReceived((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject linux_Monitor::MonitorWidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_linux_Monitor__MonitorWidget.data,
    qt_meta_data_linux_Monitor__MonitorWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *linux_Monitor::MonitorWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *linux_Monitor::MonitorWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_linux_Monitor__MonitorWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int linux_Monitor::MonitorWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
