/****************************************************************************
** Meta object code from reading C++ file 'serialportassistant.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../QTproject/SerialPortAssistant-master/serialportassistant.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serialportassistant.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SerialPortAssistant_t {
    QByteArrayData data[13];
    char stringdata0[149];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SerialPortAssistant_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SerialPortAssistant_t qt_meta_stringdata_SerialPortAssistant = {
    {
QT_MOC_LITERAL(0, 0, 19), // "SerialPortAssistant"
QT_MOC_LITERAL(1, 20, 16), // "switchSerialPort"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 7), // "receive"
QT_MOC_LITERAL(4, 46, 4), // "send"
QT_MOC_LITERAL(5, 51, 8), // "transmit"
QT_MOC_LITERAL(6, 60, 14), // "transmitString"
QT_MOC_LITERAL(7, 75, 19), // "transmitHexadecimal"
QT_MOC_LITERAL(8, 95, 18), // "transmitCircularly"
QT_MOC_LITERAL(9, 114, 12), // "transmitFile"
QT_MOC_LITERAL(10, 127, 8), // "openFile"
QT_MOC_LITERAL(11, 136, 6), // "saveAs"
QT_MOC_LITERAL(12, 143, 5) // "clear"

    },
    "SerialPortAssistant\0switchSerialPort\0"
    "\0receive\0send\0transmit\0transmitString\0"
    "transmitHexadecimal\0transmitCircularly\0"
    "transmitFile\0openFile\0saveAs\0clear"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SerialPortAssistant[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x0a /* Public */,
       3,    0,   70,    2, 0x0a /* Public */,
       4,    0,   71,    2, 0x0a /* Public */,
       5,    0,   72,    2, 0x0a /* Public */,
       6,    0,   73,    2, 0x0a /* Public */,
       7,    0,   74,    2, 0x0a /* Public */,
       8,    0,   75,    2, 0x0a /* Public */,
       9,    0,   76,    2, 0x0a /* Public */,
      10,    0,   77,    2, 0x0a /* Public */,
      11,    0,   78,    2, 0x0a /* Public */,
      12,    0,   79,    2, 0x0a /* Public */,

 // slots: parameters
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

       0        // eod
};

void SerialPortAssistant::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SerialPortAssistant *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->switchSerialPort(); break;
        case 1: _t->receive(); break;
        case 2: _t->send(); break;
        case 3: _t->transmit(); break;
        case 4: _t->transmitString(); break;
        case 5: _t->transmitHexadecimal(); break;
        case 6: _t->transmitCircularly(); break;
        case 7: _t->transmitFile(); break;
        case 8: _t->openFile(); break;
        case 9: _t->saveAs(); break;
        case 10: _t->clear(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject SerialPortAssistant::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_SerialPortAssistant.data,
    qt_meta_data_SerialPortAssistant,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SerialPortAssistant::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SerialPortAssistant::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SerialPortAssistant.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int SerialPortAssistant::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
