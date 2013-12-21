/****************************************************************************
** Meta object code from reading C++ file 'cube.h'
**
** Created: Tue Feb 16 23:50:40 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "cube.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cube.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Cube[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
       8,    6,    5,    5, 0x05,
      23,    6,    5,    5, 0x05,

 // slots: signature, parameters, type, tag, flags
      42,   38,    5,    5, 0x0a,
      52,    6,    5,    5, 0x0a,
      63,    6,    5,    5, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Cube[] = {
    "Cube\0\0a\0XaChanged(int)\0YaChanged(int)\0"
    "n_d\0setD(int)\0setXa(int)\0setYa(int)\0"
};

const QMetaObject Cube::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_Cube,
      qt_meta_data_Cube, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Cube::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Cube::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Cube::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Cube))
        return static_cast<void*>(const_cast< Cube*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int Cube::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: XaChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: YaChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: setD((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: setXa((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: setYa((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Cube::XaChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Cube::YaChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
