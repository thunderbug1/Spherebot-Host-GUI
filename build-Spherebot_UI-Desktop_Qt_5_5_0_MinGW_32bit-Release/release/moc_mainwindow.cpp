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
    QByteArrayData data[49];
    char stringdata0[870];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 22), // "successfully_connected"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 26), // "not_successfully_connected"
QT_MOC_LITERAL(4, 62, 16), // "print_next_layer"
QT_MOC_LITERAL(5, 79, 11), // "abort_print"
QT_MOC_LITERAL(6, 91, 13), // "restart_print"
QT_MOC_LITERAL(7, 105, 19), // "abort_restart_print"
QT_MOC_LITERAL(8, 125, 19), // "processReceivedData"
QT_MOC_LITERAL(9, 145, 4), // "line"
QT_MOC_LITERAL(10, 150, 10), // "sendDataUI"
QT_MOC_LITERAL(11, 161, 4), // "data"
QT_MOC_LITERAL(12, 166, 19), // "refreshSendProgress"
QT_MOC_LITERAL(13, 186, 5), // "value"
QT_MOC_LITERAL(14, 192, 15), // "fitgraphicsView"
QT_MOC_LITERAL(15, 208, 13), // "resetPortList"
QT_MOC_LITERAL(16, 222, 22), // "on_sendButton_released"
QT_MOC_LITERAL(17, 245, 22), // "on_resetButton_clicked"
QT_MOC_LITERAL(18, 268, 29), // "on_sendString_editingFinished"
QT_MOC_LITERAL(19, 298, 26), // "on_servoSlider_sliderMoved"
QT_MOC_LITERAL(20, 325, 8), // "position"
QT_MOC_LITERAL(21, 334, 28), // "on_servospinBox_valueChanged"
QT_MOC_LITERAL(22, 363, 4), // "arg1"
QT_MOC_LITERAL(23, 368, 30), // "on_penRotationBox_valueChanged"
QT_MOC_LITERAL(24, 399, 30), // "on_eggRotationBox_valueChanged"
QT_MOC_LITERAL(25, 430, 25), // "on_saveFileButton_clicked"
QT_MOC_LITERAL(26, 456, 27), // "on_fileTextEdit_textChanged"
QT_MOC_LITERAL(27, 484, 35), // "on_servoFeedrateSlider_valueC..."
QT_MOC_LITERAL(28, 520, 28), // "on_setDiameterButton_clicked"
QT_MOC_LITERAL(29, 549, 19), // "interpretSentString"
QT_MOC_LITERAL(30, 569, 6), // "string"
QT_MOC_LITERAL(31, 576, 25), // "on_sendString_textChanged"
QT_MOC_LITERAL(32, 602, 15), // "entry_connected"
QT_MOC_LITERAL(33, 618, 17), // "entry_try_connect"
QT_MOC_LITERAL(34, 636, 18), // "entry_disconnected"
QT_MOC_LITERAL(35, 655, 18), // "entry_transmitting"
QT_MOC_LITERAL(36, 674, 13), // "entry_sending"
QT_MOC_LITERAL(37, 688, 19), // "entry_start_sending"
QT_MOC_LITERAL(38, 708, 13), // "entry_stopped"
QT_MOC_LITERAL(39, 722, 10), // "entry_idle"
QT_MOC_LITERAL(40, 733, 11), // "entry_abort"
QT_MOC_LITERAL(41, 745, 13), // "entry_restart"
QT_MOC_LITERAL(42, 759, 21), // "entry_ask_for_restart"
QT_MOC_LITERAL(43, 781, 24), // "entry_ask_for_next_layer"
QT_MOC_LITERAL(44, 806, 22), // "entry_load_file_dialog"
QT_MOC_LITERAL(45, 829, 13), // "leave_sending"
QT_MOC_LITERAL(46, 843, 8), // "loadFile"
QT_MOC_LITERAL(47, 852, 8), // "fileName"
QT_MOC_LITERAL(48, 861, 8) // "saveFile"

    },
    "MainWindow\0successfully_connected\0\0"
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
    "loadFile\0fileName\0saveFile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      40,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  214,    2, 0x06 /* Public */,
       3,    0,  215,    2, 0x06 /* Public */,
       4,    0,  216,    2, 0x06 /* Public */,
       5,    0,  217,    2, 0x06 /* Public */,
       6,    0,  218,    2, 0x06 /* Public */,
       7,    0,  219,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,  220,    2, 0x0a /* Public */,
      10,    1,  223,    2, 0x0a /* Public */,
      12,    1,  226,    2, 0x0a /* Public */,
      14,    0,  229,    2, 0x0a /* Public */,
      15,    0,  230,    2, 0x08 /* Private */,
      16,    0,  231,    2, 0x08 /* Private */,
      17,    0,  232,    2, 0x08 /* Private */,
      18,    0,  233,    2, 0x08 /* Private */,
      19,    1,  234,    2, 0x08 /* Private */,
      21,    1,  237,    2, 0x08 /* Private */,
      23,    1,  240,    2, 0x08 /* Private */,
      24,    1,  243,    2, 0x08 /* Private */,
      25,    0,  246,    2, 0x08 /* Private */,
      26,    0,  247,    2, 0x08 /* Private */,
      27,    1,  248,    2, 0x08 /* Private */,
      28,    0,  251,    2, 0x08 /* Private */,
      29,    1,  252,    2, 0x08 /* Private */,
      31,    1,  255,    2, 0x08 /* Private */,
      32,    0,  258,    2, 0x08 /* Private */,
      33,    0,  259,    2, 0x08 /* Private */,
      34,    0,  260,    2, 0x08 /* Private */,
      35,    0,  261,    2, 0x08 /* Private */,
      36,    0,  262,    2, 0x08 /* Private */,
      37,    0,  263,    2, 0x08 /* Private */,
      38,    0,  264,    2, 0x08 /* Private */,
      39,    0,  265,    2, 0x08 /* Private */,
      40,    0,  266,    2, 0x08 /* Private */,
      41,    0,  267,    2, 0x08 /* Private */,
      42,    0,  268,    2, 0x08 /* Private */,
      43,    0,  269,    2, 0x08 /* Private */,
      44,    0,  270,    2, 0x08 /* Private */,
      45,    0,  271,    2, 0x08 /* Private */,
      46,    1,  272,    2, 0x08 /* Private */,
      48,    1,  275,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   30,
    QMetaType::Void, QMetaType::QString,   22,
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
    QMetaType::Void, QMetaType::QString,   47,
    QMetaType::Bool, QMetaType::QString,   47,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->successfully_connected(); break;
        case 1: _t->not_successfully_connected(); break;
        case 2: _t->print_next_layer(); break;
        case 3: _t->abort_print(); break;
        case 4: _t->restart_print(); break;
        case 5: _t->abort_restart_print(); break;
        case 6: _t->processReceivedData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->sendDataUI((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->refreshSendProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->fitgraphicsView(); break;
        case 10: _t->resetPortList(); break;
        case 11: _t->on_sendButton_released(); break;
        case 12: _t->on_resetButton_clicked(); break;
        case 13: _t->on_sendString_editingFinished(); break;
        case 14: _t->on_servoSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->on_servospinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->on_penRotationBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->on_eggRotationBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->on_saveFileButton_clicked(); break;
        case 19: _t->on_fileTextEdit_textChanged(); break;
        case 20: _t->on_servoFeedrateSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->on_setDiameterButton_clicked(); break;
        case 22: _t->interpretSentString((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 23: _t->on_sendString_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 24: _t->entry_connected(); break;
        case 25: _t->entry_try_connect(); break;
        case 26: _t->entry_disconnected(); break;
        case 27: _t->entry_transmitting(); break;
        case 28: _t->entry_sending(); break;
        case 29: _t->entry_start_sending(); break;
        case 30: _t->entry_stopped(); break;
        case 31: _t->entry_idle(); break;
        case 32: _t->entry_abort(); break;
        case 33: _t->entry_restart(); break;
        case 34: _t->entry_ask_for_restart(); break;
        case 35: _t->entry_ask_for_next_layer(); break;
        case 36: _t->entry_load_file_dialog(); break;
        case 37: _t->leave_sending(); break;
        case 38: _t->loadFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 39: { bool _r = _t->saveFile((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::successfully_connected)) {
                *result = 0;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::not_successfully_connected)) {
                *result = 1;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::print_next_layer)) {
                *result = 2;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::abort_print)) {
                *result = 3;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::restart_print)) {
                *result = 4;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::abort_restart_print)) {
                *result = 5;
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
        if (_id < 40)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 40;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 40)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 40;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::successfully_connected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void MainWindow::not_successfully_connected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void MainWindow::print_next_layer()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void MainWindow::abort_print()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void MainWindow::restart_print()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void MainWindow::abort_restart_print()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
