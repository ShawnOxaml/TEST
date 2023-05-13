/****************************************************************************
** Meta object code from reading C++ file 'compredecomprefilethread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../QZIP/compredecomprefilethread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'compredecomprefilethread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CompreDecompreFileThread_t {
    QByteArrayData data[12];
    char stringdata0[164];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CompreDecompreFileThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CompreDecompreFileThread_t qt_meta_stringdata_CompreDecompreFileThread = {
    {
QT_MOC_LITERAL(0, 0, 24), // "CompreDecompreFileThread"
QT_MOC_LITERAL(1, 25, 22), // "compression_res_signal"
QT_MOC_LITERAL(2, 48, 0), // ""
QT_MOC_LITERAL(3, 49, 7), // "ResultE"
QT_MOC_LITERAL(4, 57, 3), // "res"
QT_MOC_LITERAL(5, 61, 8), // "progress"
QT_MOC_LITERAL(6, 70, 7), // "remarks"
QT_MOC_LITERAL(7, 78, 24), // "decompression_res_signal"
QT_MOC_LITERAL(8, 103, 20), // "compression_file_run"
QT_MOC_LITERAL(9, 124, 7), // "srcPath"
QT_MOC_LITERAL(10, 132, 8), // "destPath"
QT_MOC_LITERAL(11, 141, 22) // "decompression_file_run"

    },
    "CompreDecompreFileThread\0"
    "compression_res_signal\0\0ResultE\0res\0"
    "progress\0remarks\0decompression_res_signal\0"
    "compression_file_run\0srcPath\0destPath\0"
    "decompression_file_run"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CompreDecompreFileThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   44,    2, 0x06 /* Public */,
       1,    2,   51,    2, 0x26 /* Public | MethodCloned */,
       7,    3,   56,    2, 0x06 /* Public */,
       7,    2,   63,    2, 0x26 /* Public | MethodCloned */,

 // slots: name, argc, parameters, tag, flags
       8,    2,   68,    2, 0x0a /* Public */,
      11,    2,   73,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::UChar, QMetaType::QString,    4,    5,    6,
    QMetaType::Void, 0x80000000 | 3, QMetaType::UChar,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::UChar, QMetaType::QString,    4,    5,    6,
    QMetaType::Void, 0x80000000 | 3, QMetaType::UChar,    4,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    9,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    9,   10,

       0        // eod
};

void CompreDecompreFileThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CompreDecompreFileThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->compression_res_signal((*reinterpret_cast< ResultE(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 1: _t->compression_res_signal((*reinterpret_cast< ResultE(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2]))); break;
        case 2: _t->decompression_res_signal((*reinterpret_cast< ResultE(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 3: _t->decompression_res_signal((*reinterpret_cast< ResultE(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2]))); break;
        case 4: _t->compression_file_run((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->decompression_file_run((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CompreDecompreFileThread::*)(ResultE , quint8 , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CompreDecompreFileThread::compression_res_signal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CompreDecompreFileThread::*)(ResultE , quint8 , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CompreDecompreFileThread::decompression_res_signal)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CompreDecompreFileThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CompreDecompreFileThread.data,
    qt_meta_data_CompreDecompreFileThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CompreDecompreFileThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CompreDecompreFileThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CompreDecompreFileThread.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CompreDecompreFileThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void CompreDecompreFileThread::compression_res_signal(ResultE _t1, quint8 _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 2
void CompreDecompreFileThread::decompression_res_signal(ResultE _t1, quint8 _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
