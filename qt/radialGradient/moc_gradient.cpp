/****************************************************************************
** Meta object code from reading C++ file 'gradient.h'
**
** Created: Sun Apr 19 12:53:51 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "gradient.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gradient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QPaintWidget[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      17,   14,   13,   13, 0x05,
      32,   29,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      44,   14,   13,   13, 0x0a,
      55,   29,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QPaintWidget[] = {
    "QPaintWidget\0\0px\0movedX(int)\0py\0"
    "movedY(int)\0moveX(int)\0moveY(int)\0"
};

const QMetaObject QPaintWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QPaintWidget,
      qt_meta_data_QPaintWidget, 0 }
};

const QMetaObject *QPaintWidget::metaObject() const
{
    return &staticMetaObject;
}

void *QPaintWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QPaintWidget))
        return static_cast<void*>(const_cast< QPaintWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int QPaintWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: movedX((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: movedY((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: moveX((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: moveY((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void QPaintWidget::movedX(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QPaintWidget::movedY(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
