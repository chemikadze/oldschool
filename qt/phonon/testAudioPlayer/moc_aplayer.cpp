/****************************************************************************
** Meta object code from reading C++ file 'aplayer.h'
**
** Created: Thu Jun 24 19:37:13 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "aplayer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'aplayer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_APlayer[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,    9,    8,    8, 0x08,
      44,    8,    8,    8, 0x08,
      58,    8,    8,    8, 0x08,
      81,    8,    8,    8, 0x08,
     108,  106,    8,    8, 0x08,
     148,    8,    8,    8, 0x0a,
     155,    8,    8,    8, 0x0a,
     167,    8,    8,    8, 0x0a,
     179,  174,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_APlayer[] = {
    "APlayer\0\0index\0treeItemClicked(QModelIndex)\0"
    "treeChanged()\0setPlaybackMax(qint64)\0"
    "setPlaybackState(qint64)\0,\0"
    "fileDoubleClicked(QTreeWidgetItem*,int)\0"
    "play()\0playPause()\0stop()\0path\0"
    "setDir(QString)\0"
};

const QMetaObject APlayer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_APlayer,
      qt_meta_data_APlayer, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &APlayer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *APlayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *APlayer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_APlayer))
        return static_cast<void*>(const_cast< APlayer*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int APlayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: treeItemClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: treeChanged(); break;
        case 2: setPlaybackMax((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 3: setPlaybackState((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 4: fileDoubleClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: play(); break;
        case 6: playPause(); break;
        case 7: stop(); break;
        case 8: setDir((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
