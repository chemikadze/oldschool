/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created: Mon Aug 17 15:31:00 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "widget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Widget[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x0a,
      19,    7,    7,    7, 0x0a,
      27,    7,    7,    7, 0x0a,
      41,    7,    7,    7, 0x0a,
      54,    7,    7,    7, 0x0a,
      70,   68,    7,    7, 0x0a,
      99,   95,    7,    7, 0x0a,
     144,  139,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Widget[] = {
    "Widget\0\0settings()\0about()\0sendMessage()\0"
    "changeName()\0processData()\0b\0"
    "setConnectionState(bool)\0err\0"
    "sockError(QAbstractSocket::SocketError)\0"
    "stat\0stateChanged(QAbstractSocket::SocketState)\0"
};

const QMetaObject Widget::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Widget,
      qt_meta_data_Widget, 0 }
};

const QMetaObject *Widget::metaObject() const
{
    return &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Widget))
        return static_cast<void*>(const_cast< Widget*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: settings(); break;
        case 1: about(); break;
        case 2: sendMessage(); break;
        case 3: changeName(); break;
        case 4: processData(); break;
        case 5: setConnectionState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: sockError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 7: stateChanged((*reinterpret_cast< QAbstractSocket::SocketState(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
