/****************************************************************************
** Meta object code from reading C++ file 'imuser.h'
**
** Created: Wed Aug 26 19:12:58 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "imuser.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imuser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ImUser[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x05,
      27,    7,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
      42,    7,    7,    7, 0x0a,
      59,    7,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ImUser[] = {
    "ImUser\0\0disconnectedUser()\0incomingData()\0"
    "disconnectUser()\0readData()\0"
};

const QMetaObject ImUser::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ImUser,
      qt_meta_data_ImUser, 0 }
};

const QMetaObject *ImUser::metaObject() const
{
    return &staticMetaObject;
}

void *ImUser::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ImUser))
        return static_cast<void*>(const_cast< ImUser*>(this));
    return QObject::qt_metacast(_clname);
}

int ImUser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: disconnectedUser(); break;
        case 1: incomingData(); break;
        case 2: disconnectUser(); break;
        case 3: readData(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void ImUser::disconnectedUser()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ImUser::incomingData()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
