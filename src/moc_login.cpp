/****************************************************************************
** Meta object code from reading C++ file 'login.h'
**
** Created: Fri Jan 17 02:16:43 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "login.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'login.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LogIn[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x0a,
      13,    6,    6,    6, 0x0a,
      34,    6,    6,    6, 0x0a,
      50,    6,    6,    6, 0x0a,
      71,    6,    6,    6, 0x0a,
      89,    6,    6,    6, 0x0a,
     103,    6,    6,    6, 0x0a,
     120,    6,    6,    6, 0x0a,
     139,    6,    6,    6, 0x0a,
     158,    6,    6,    6, 0x0a,
     178,    6,    6,    6, 0x0a,
     197,    6,    6,    6, 0x0a,
     217,    6,    6,    6, 0x0a,
     236,    6,    6,    6, 0x0a,
     251,    6,    6,    6, 0x0a,
     267,    6,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_LogIn[] = {
    "LogIn\0\0end()\0deleteUserFunction()\0"
    "logOnFunction()\0listScoresFunction()\0"
    "addUserFunction()\0getUserData()\0"
    "deleteUserData()\0loggedInFunction()\0"
    "listUserFunction()\0addFriendFunction()\0"
    "deFriendFunction()\0sortScoreFunction()\0"
    "shortestFunction()\0playFunction()\0"
    "addThisFriend()\0deleteThisFriend()\0"
};

void LogIn::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LogIn *_t = static_cast<LogIn *>(_o);
        switch (_id) {
        case 0: _t->end(); break;
        case 1: _t->deleteUserFunction(); break;
        case 2: _t->logOnFunction(); break;
        case 3: _t->listScoresFunction(); break;
        case 4: _t->addUserFunction(); break;
        case 5: _t->getUserData(); break;
        case 6: _t->deleteUserData(); break;
        case 7: _t->loggedInFunction(); break;
        case 8: _t->listUserFunction(); break;
        case 9: _t->addFriendFunction(); break;
        case 10: _t->deFriendFunction(); break;
        case 11: _t->sortScoreFunction(); break;
        case 12: _t->shortestFunction(); break;
        case 13: _t->playFunction(); break;
        case 14: _t->addThisFriend(); break;
        case 15: _t->deleteThisFriend(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData LogIn::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LogIn::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LogIn,
      qt_meta_data_LogIn, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LogIn::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LogIn::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LogIn::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LogIn))
        return static_cast<void*>(const_cast< LogIn*>(this));
    return QWidget::qt_metacast(_clname);
}

int LogIn::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
