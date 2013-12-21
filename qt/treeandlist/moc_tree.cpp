/****************************************************************************
** Meta object code from reading C++ file 'tree.h'
**
** Created: Tue Mar 10 22:50:41 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "tree.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tree.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TAL[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      10,    5,    4,    4, 0x0a,
      40,    4,    4,    4, 0x0a,
      62,   57,    4,    4, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TAL[] = {
    "TAL\0\0item\0addListItem(QTreeWidgetItem*)\0"
    "changeListMode()\0size\0resizeItems(int)\0"
};

const QMetaObject TAL::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TAL,
      qt_meta_data_TAL, 0 }
};

const QMetaObject *TAL::metaObject() const
{
    return &staticMetaObject;
}

void *TAL::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TAL))
        return static_cast<void*>(const_cast< TAL*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int TAL::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: addListItem((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 1: changeListMode(); break;
        case 2: resizeItems((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
