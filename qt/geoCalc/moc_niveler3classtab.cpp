/****************************************************************************
** Meta object code from reading C++ file 'niveler3classtab.h'
**
** Created: Sat Feb 27 21:46:41 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "niveler3classtab.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'niveler3classtab.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Niveler3ClassTab[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x0a,
      31,   17,   17,   17, 0x0a,
      47,   17,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Niveler3ClassTab[] = {
    "Niveler3ClassTab\0\0addMeasure()\0"
    "deleteMeasure()\0calculate()\0"
};

const QMetaObject Niveler3ClassTab::staticMetaObject = {
    { &AbstractCalculationTab::staticMetaObject, qt_meta_stringdata_Niveler3ClassTab,
      qt_meta_data_Niveler3ClassTab, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Niveler3ClassTab::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Niveler3ClassTab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Niveler3ClassTab::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Niveler3ClassTab))
        return static_cast<void*>(const_cast< Niveler3ClassTab*>(this));
    return AbstractCalculationTab::qt_metacast(_clname);
}

int Niveler3ClassTab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractCalculationTab::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: addMeasure(); break;
        case 1: deleteMeasure(); break;
        case 2: calculate(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
