/****************************************************************************
** Meta object code from reading C++ file 'imserver.h'
**
** Created: Wed Aug 26 19:12:59 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "imserver.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ImServer[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      25,    9,    9,    9, 0x0a,
      38,    9,    9,    9, 0x0a,
      48,    9,    9,    9, 0x0a,
      69,    9,   62,    9, 0x0a,
      78,   76,    9,    9, 0x0a,
      94,    9,    9,    9, 0x0a,
     102,    9,    9,    9, 0x0a,
     113,  109,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ImServer[] = {
    "ImServer\0\0usersChanged()\0deleteUser()\0"
    "addUser()\0processData()\0qint16\0port()\0"
    "p\0setPort(qint16)\0close()\0open()\0str\0"
    "sendServerMessage(QString)\0"
};

const QMetaObject ImServer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ImServer,
      qt_meta_data_ImServer, 0 }
};

const QMetaObject *ImServer::metaObject() const
{
    return &staticMetaObject;
}

void *ImServer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ImServer))
        return static_cast<void*>(const_cast< ImServer*>(this));
    return QObject::qt_metacast(_clname);
}

int ImServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: usersChanged(); break;
        case 1: deleteUser(); break;
        case 2: addUser(); break;
        case 3: processData(); break;
        case 4: { qint16 _r = port();
            if (_a[0]) *reinterpret_cast< qint16*>(_a[0]) = _r; }  break;
        case 5: setPort((*reinterpret_cast< qint16(*)>(_a[1]))); break;
        case 6: close(); break;
        case 7: open(); break;
        case 8: sendServerMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void ImServer::usersChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
