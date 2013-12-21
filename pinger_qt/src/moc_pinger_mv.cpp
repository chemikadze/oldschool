/****************************************************************************
** Meta object code from reading C++ file 'pinger_mv.h'
**
** Created: Thu Dec 25 00:50:29 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "pinger_mv.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pinger_mv.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_aMainWindow[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_aMainWindow[] = {
    "aMainWindow\0\0run()\0"
};

const QMetaObject aMainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_aMainWindow,
      qt_meta_data_aMainWindow, 0 }
};

const QMetaObject *aMainWindow::metaObject() const
{
    return &staticMetaObject;
}

void *aMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_aMainWindow))
        return static_cast<void*>(const_cast< aMainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int aMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: run(); break;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
