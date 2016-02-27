/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Spherebot_UI/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[53];
    char stringdata0[938];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 16), // "force_disconnect"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 22), // "successfully_connected"
QT_MOC_LITERAL(4, 52, 26), // "not_successfully_connected"
QT_MOC_LITERAL(5, 79, 16), // "print_next_layer"
QT_MOC_LITERAL(6, 96, 11), // "abort_print"
QT_MOC_LITERAL(7, 108, 13), // "restart_print"
QT_MOC_LITERAL(8, 122, 19), // "abort_restart_print"
QT_MOC_LITERAL(9, 142, 19), // "processReceivedData"
QT_MOC_LITERAL(10, 162, 4), // "line"
QT_MOC_LITERAL(11, 167, 10), // "sendDataUI"
QT_MOC_LITERAL(12, 178, 4), // "data"
QT_MOC_LITERAL(13, 183, 19), // "refreshSendProgress"
QT_MOC_LITERAL(14, 203, 5), // "value"
QT_MOC_LITERAL(15, 209, 15), // "fitgraphicsView"
QT_MOC_LITERAL(16, 225, 13), // "resetPortList"
QT_MOC_LITERAL(17, 239, 22), // "on_sendButton_released"
QT_MOC_LITERAL(18, 262, 22), // "on_resetButton_clicked"
QT_MOC_LITERAL(19, 285, 29), // "on_sendString_editingFinished"
QT_MOC_LITERAL(20, 315, 26), // "on_servoSlider_sliderMoved"
QT_MOC_LITERAL(21, 342, 8), // "position"
QT_MOC_LITERAL(22, 351, 28), // "on_servospinBox_valueChanged"
QT_MOC_LITERAL(23, 380, 4), // "arg1"
QT_MOC_LITERAL(24, 385, 30), // "on_penRotationBox_valueChanged"
QT_MOC_LITERAL(25, 416, 30), // "on_eggRotationBox_valueChanged"
QT_MOC_LITERAL(26, 447, 25), // "on_saveFileButton_clicked"
QT_MOC_LITERAL(27, 473, 27), // "on_fileTextEdit_textChanged"
QT_MOC_LITERAL(28, 501, 35), // "on_servoFeedrateSlider_valueC..."
QT_MOC_LITERAL(29, 537, 28), // "on_setDiameterButton_clicked"
QT_MOC_LITERAL(30, 566, 19), // "interpretSentString"
QT_MOC_LITERAL(31, 586, 6), // "string"
QT_MOC_LITERAL(32, 593, 25), // "on_sendString_textChanged"
QT_MOC_LITERAL(33, 619, 15), // "entry_connected"
QT_MOC_LITERAL(34, 635, 17), // "entry_try_connect"
QT_MOC_LITERAL(35, 653, 18), // "entry_disconnected"
QT_MOC_LITERAL(36, 672, 18), // "entry_transmitting"
QT_MOC_LITERAL(37, 691, 13), // "entry_sending"
QT_MOC_LITERAL(38, 705, 19), // "entry_start_sending"
QT_MOC_LITERAL(39, 725, 13), // "entry_stopped"
QT_MOC_LITERAL(40, 739, 10), // "entry_idle"
QT_MOC_LITERAL(41, 750, 11), // "entry_abort"
QT_MOC_LITERAL(42, 762, 13), // "entry_restart"
QT_MOC_LITERAL(43, 776, 21), // "entry_ask_for_restart"
QT_MOC_LITERAL(44, 798, 24), // "entry_ask_for_next_layer"
QT_MOC_LITERAL(45, 823, 22), // "entry_load_file_dialog"
QT_MOC_LITERAL(46, 846, 13), // "leave_sending"
QT_MOC_LITERAL(47, 860, 8), // "loadFile"
QT_MOC_LITERAL(48, 869, 8), // "fileName"
QT_MOC_LITERAL(49, 878, 8), // "saveFile"
QT_MOC_LITERAL(50, 887, 17), // "handle_port_error"
QT_MOC_LITERAL(51, 905, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(52, 934, 3) // "err"

    },
    "MainWindow\0force_disconnect\0\0"
    "successfully_connected\0"
    "not_successfully_connected\0print_next_layer\0"
    "abort_print\0restart_print\0abort_restart_print\0"
    "processReceivedData\0line\0sendDataUI\0"
    "data\0refreshSendProgress\0value\0"
    "fitgraphicsView\0resetPortList\0"
    "on_sendButton_released\0on_resetButton_clicked\0"
    "on_sendString_editingFinished\0"
    "on_servoSlider_sliderMoved\0position\0"
    "on_servospinBox_valueChanged\0arg1\0"
    "on_penRotationBox_valueChanged\0"
    "on_eggRotationBox_valueChanged\0"
    "on_saveFileButton_clicked\0"
    "on_fileTextEdit_textChanged\0"
    "on_servoFeedrateSlider_valueChanged\0"
    "on_setDiameterButton_clicked\0"
    "interpretSentString\0string\0"
    "on_sendString_textChanged\0entry_connected\0"
    "entry_try_connect\0entry_disconnected\0"
    "entry_transmitting\0entry_sending\0"
    "entry_start_sending\0entry_stopped\0"
    "entry_idle\0entry_abort\0entry_restart\0"
    "entry_ask_for_restart\0entry_ask_for_next_layer\0"
    "entry_load_file_dialog\0leave_sending\0"
    "loadFile\0fileName\0saveFile\0handle_port_error\0"
    "QSerialPort::SerialPortError\0err"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      42,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  224,    2, 0x06 /* Public */,
       3,    0,  225,    2, 0x06 /* Public */,
       4,    0,  226,    2, 0x06 /* Public */,
       5,    0,  227,    2, 0x06 /* Public */,
       6,    0,  228,    2, 0x06 /* Public */,
       7,    0,  229,    2, 0x06 /* Public */,
       8,    0,  230,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,  231,    2, 0x0a /* Public */,
      11,    1,  234,    2, 0x0a /* Public */,
      13,    1,  237,    2, 0x0a /* Public */,
      15,    0,  240,    2, 0x0a /* Public */,
      16,    0,  241,    2, 0x08 /* Private */,
      17,    0,  242,    2, 0x08 /* Private */,
      18,    0,  243,    2, 0x08 /* Private */,
      19,    0,  244,    2, 0x08 /* Private */,
      20,    1,  245,    2, 0x08 /* Private */,
      22,    1,  248,    2, 0x08 /* Private */,
      24,    1,  251,    2, 0x08 /* Private */,
      25,    1,  254,    2, 0x08 /* Private */,
      26,    0,  257,    2, 0x08 /* Private */,
      27,    0,  258,    2, 0x08 /* Private */,
      28,    1,  259,    2, 0x08 /* Private */,
      29,    0,  262,    2, 0x08 /* Private */,
      30,    1,  263,    2, 0x08 /* Private */,
      32,    1,  266,    2, 0x08 /* Private */,
      33,    0,  269,    2, 0x08 /* Private */,
      34,    0,  270,    2, 0x08 /* Private */,
      35,    0,  271,    2, 0x08 /* Private */,
      36,    0,  272,    2, 0x08 /* Private */,
      37,    0,  273,    2, 0x08 /* Private */,
      38,    0,  274,    2, 0x08 /* Private */,
      39,    0,  275,    2, 0x08 /* Private */,
      40,    0,  276,    2, 0x08 /* Private */,
      41,    0,  277,    2, 0x08 /* Private */,
      42,    0,  278,    2, 0x08 /* Private */,
      43,    0,  279,    2, 0x08 /* Private */,
      44,    0,  280,    2, 0x08 /* Private */,
      45,    0,  281,    2, 0x08 /* Private */,
      46,    0,  282,    2, 0x08 /* Private */,
      47,    1,  283,    2, 0x08 /* Private */,
      49,    1,  286,    2, 0x08 /* Private */,
      50,    1,  289,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   31,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   48,
    QMetaType::Bool, QMetaType::QString,   48,
    QMetaType::Void, 0x80000000 | 51,   52,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->force_disconnect(); break;
        case 1: _t->successfully_connected(); break;
        case 2: _t->not_successfully_connected(); break;
        case 3: _t->print_next_layer(); break;
        case 4: _t->abort_print(); break;
        case 5: _t->restart_print(); break;
        case 6: _t->abort_restart_print(); break;
        case 7: _t->processReceivedData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->sendDataUI((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->refreshSendProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->fitgraphicsView(); break;
        case 11: _t->resetPortList(); break;
        case 12: _t->on_sendButton_released(); break;
        case 13: _t->on_resetButton_clicked(); break;
        case 14: _t->on_sendString_editingFinished(); break;
        case 15: _t->on_servoSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->on_servospinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->on_penRotationBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->on_eggRotationBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->on_saveFileButton_clicked(); break;
        case 20: _t->on_fileTextEdit_textChanged(); break;
        case 21: _t->on_servoFeedrateSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->on_setDiameterButton_clicked(); break;
        case 23: _t->interpretSentString((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 24: _t->on_sendString_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 25: _t->entry_connected(); break;
        case 26: _t->entry_try_connect(); break;
        case 27: _t->entry_disconnected(); break;
        case 28: _t->entry_transmitting(); break;
        case 29: _t->entry_sending(); break;
        case 30: _t->entry_start_sending(); break;
        case 31: _t->entry_stopped(); break;
        case 32: _t->entry_idle(); break;
        case 33: _t->entry_abort(); break;
        case 34: _t->entry_restart(); break;
        case 35: _t->entry_ask_for_restart(); break;
        case 36: _t->entry_ask_for_next_layer(); break;
        case 37: _t->entry_load_file_dialog(); break;
        case 38: _t->leave_sending(); break;
        case 39: _t->loadFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 40: { bool _r = _t->saveFile((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 41: _t->handle_port_error((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::force_disconnect)) {
                *result = 0;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::successfully_connected)) {
                *result = 1;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::not_successfully_connected)) {
                *result = 2;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::print_next_layer)) {
                *result = 3;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::abort_print)) {
                *result = 4;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::restart_print)) {
                *result = 5;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::abort_restart_print)) {
                *result = 6;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 42)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 42;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 42)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 42;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::force_disconnect()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void MainWindow::successfully_connected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void MainWindow::not_successfully_connected()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void MainWindow::print_next_layer()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void MainWindow::abort_print()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void MainWindow::restart_print()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void MainWindow::abort_restart_print()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
