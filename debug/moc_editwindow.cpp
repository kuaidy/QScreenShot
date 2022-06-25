/****************************************************************************
** Meta object code from reading C++ file 'editwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../include/editwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtNetwork/QSslError>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'editwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_editwindow_t {
    const uint offsetsAndSize[32];
    char stringdata0[297];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_editwindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_editwindow_t qt_meta_stringdata_editwindow = {
    {
QT_MOC_LITERAL(0, 10), // "editwindow"
QT_MOC_LITERAL(11, 21), // "on_paintrec_triggered"
QT_MOC_LITERAL(33, 0), // ""
QT_MOC_LITERAL(34, 23), // "on_paintarrow_triggered"
QT_MOC_LITERAL(58, 7), // "checked"
QT_MOC_LITERAL(66, 26), // "on_filesaveother_triggered"
QT_MOC_LITERAL(93, 18), // "on_vague_triggered"
QT_MOC_LITERAL(112, 31), // "on_actionpaintfreedom_triggered"
QT_MOC_LITERAL(144, 20), // "on_enlarge_triggered"
QT_MOC_LITERAL(165, 19), // "on_narrow_triggered"
QT_MOC_LITERAL(185, 21), // "on_fileopen_triggered"
QT_MOC_LITERAL(207, 20), // "on_setting_triggered"
QT_MOC_LITERAL(228, 12), // "removeSubTab"
QT_MOC_LITERAL(241, 5), // "index"
QT_MOC_LITERAL(247, 25), // "on_actionupload_triggered"
QT_MOC_LITERAL(273, 23) // "on_actionCrop_triggered"

    },
    "editwindow\0on_paintrec_triggered\0\0"
    "on_paintarrow_triggered\0checked\0"
    "on_filesaveother_triggered\0"
    "on_vague_triggered\0on_actionpaintfreedom_triggered\0"
    "on_enlarge_triggered\0on_narrow_triggered\0"
    "on_fileopen_triggered\0on_setting_triggered\0"
    "removeSubTab\0index\0on_actionupload_triggered\0"
    "on_actionCrop_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_editwindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   98,    2, 0x08,    1 /* Private */,
       3,    0,   99,    2, 0x08,    2 /* Private */,
       1,    1,  100,    2, 0x08,    3 /* Private */,
       3,    1,  103,    2, 0x08,    5 /* Private */,
       5,    0,  106,    2, 0x08,    7 /* Private */,
       6,    1,  107,    2, 0x08,    8 /* Private */,
       7,    1,  110,    2, 0x08,   10 /* Private */,
       8,    0,  113,    2, 0x08,   12 /* Private */,
       9,    0,  114,    2, 0x08,   13 /* Private */,
      10,    0,  115,    2, 0x08,   14 /* Private */,
      11,    0,  116,    2, 0x08,   15 /* Private */,
      12,    1,  117,    2, 0x08,   16 /* Private */,
      14,    0,  120,    2, 0x08,   18 /* Private */,
      15,    1,  121,    2, 0x08,   19 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,

       0        // eod
};

void editwindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<editwindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_paintrec_triggered(); break;
        case 1: _t->on_paintarrow_triggered(); break;
        case 2: _t->on_paintrec_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_paintarrow_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_filesaveother_triggered(); break;
        case 5: _t->on_vague_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_actionpaintfreedom_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_enlarge_triggered(); break;
        case 8: _t->on_narrow_triggered(); break;
        case 9: _t->on_fileopen_triggered(); break;
        case 10: _t->on_setting_triggered(); break;
        case 11: _t->removeSubTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_actionupload_triggered(); break;
        case 13: _t->on_actionCrop_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject editwindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_editwindow.offsetsAndSize,
    qt_meta_data_editwindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_editwindow_t
, QtPrivate::TypeAndForceComplete<editwindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>


>,
    nullptr
} };


const QMetaObject *editwindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *editwindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_editwindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int editwindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
