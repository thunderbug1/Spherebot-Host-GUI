/****************************************************************************
** Meta object code from reading C++ file 'spherebot.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Spherebot_UI/spherebot.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'spherebot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_spherebot_t {
    QByteArrayData data[18];
    char stringdata0[201];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_spherebot_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_spherebot_t qt_meta_stringdata_spherebot = {
    {
QT_MOC_LITERAL(0, 0, 9), // "spherebot"
QT_MOC_LITERAL(1, 10, 8), // "dataSent"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 4), // "data"
QT_MOC_LITERAL(4, 25, 15), // "progressChanged"
QT_MOC_LITERAL(5, 41, 16), // "layerTransmitted"
QT_MOC_LITERAL(6, 58, 15), // "fileTransmitted"
QT_MOC_LITERAL(7, 74, 14), // "connectWithBot"
QT_MOC_LITERAL(8, 89, 8), // "portName"
QT_MOC_LITERAL(9, 98, 17), // "disconnectWithBot"
QT_MOC_LITERAL(10, 116, 13), // "processAnswer"
QT_MOC_LITERAL(11, 130, 6), // "answer"
QT_MOC_LITERAL(12, 137, 10), // "resendLine"
QT_MOC_LITERAL(13, 148, 10), // "resetState"
QT_MOC_LITERAL(14, 159, 3), // "set"
QT_MOC_LITERAL(15, 163, 10), // "intextfile"
QT_MOC_LITERAL(16, 174, 8), // "sendNext"
QT_MOC_LITERAL(17, 183, 17) // "trySendBufferLine"

    },
    "spherebot\0dataSent\0\0data\0progressChanged\0"
    "layerTransmitted\0fileTransmitted\0"
    "connectWithBot\0portName\0disconnectWithBot\0"
    "processAnswer\0answer\0resendLine\0"
    "resetState\0set\0intextfile\0sendNext\0"
    "trySendBufferLine"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_spherebot[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       4,    1,   82,    2, 0x06 /* Public */,
       5,    0,   85,    2, 0x06 /* Public */,
       6,    0,   86,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   87,    2, 0x0a /* Public */,
       7,    0,   90,    2, 0x0a /* Public */,
       9,    0,   91,    2, 0x0a /* Public */,
      10,    1,   92,    2, 0x0a /* Public */,
      12,    0,   95,    2, 0x0a /* Public */,
      13,    0,   96,    2, 0x0a /* Public */,
      14,    1,   97,    2, 0x0a /* Public */,
      16,    0,  100,    2, 0x0a /* Public */,
      17,    0,  101,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Bool, QMetaType::QString,    8,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void spherebot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        spherebot *_t = static_cast<spherebot *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dataSent((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->progressChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->layerTransmitted(); break;
        case 3: _t->fileTransmitted(); break;
        case 4: { bool _r = _t->connectWithBot((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: { bool _r = _t->connectWithBot();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: { bool _r = _t->disconnectWithBot();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: _t->processAnswer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->resendLine(); break;
        case 9: _t->resetState(); break;
        case 10: _t->set((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->sendNext(); break;
        case 12: _t->trySendBufferLine(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (spherebot::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&spherebot::dataSent)) {
                *result = 0;
            }
        }
        {
            typedef void (spherebot::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&spherebot::progressChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (spherebot::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&spherebot::layerTransmitted)) {
                *result = 2;
            }
        }
        {
            typedef void (spherebot::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&spherebot::fileTransmitted)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject spherebot::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_spherebot.data,
      qt_meta_data_spherebot,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *spherebot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *spherebot::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_spherebot.stringdata0))
        return static_cast<void*>(const_cast< spherebot*>(this));
    return QObject::qt_metacast(_clname);
}

int spherebot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void spherebot::dataSent(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void spherebot::progressChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void spherebot::layerTransmitted()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void spherebot::fileTransmitted()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
