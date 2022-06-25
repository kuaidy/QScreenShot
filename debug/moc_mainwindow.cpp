/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../include/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtNetwork/QSslError>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[32];
    char stringdata0[279];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 8), // "senddata"
QT_MOC_LITERAL(20, 0), // ""
QT_MOC_LITERAL(21, 3), // "str"
QT_MOC_LITERAL(25, 10), // "shotscreen"
QT_MOC_LITERAL(36, 28), // "on_pb_fullscreenshot_clicked"
QT_MOC_LITERAL(65, 27), // "on_pb_regscreenshot_clicked"
QT_MOC_LITERAL(93, 25), // "on_pb_delayedshot_clicked"
QT_MOC_LITERAL(119, 11), // "receiveData"
QT_MOC_LITERAL(131, 4), // "data"
QT_MOC_LITERAL(136, 30), // "on_pb_widgetscreenshot_clicked"
QT_MOC_LITERAL(167, 27), // "on_pb_activewinshot_clicked"
QT_MOC_LITERAL(195, 25), // "on_pb_windowsshot_clicked"
QT_MOC_LITERAL(221, 23), // "on_pb_fixedsize_clicked"
QT_MOC_LITERAL(245, 7), // "showWin"
QT_MOC_LITERAL(253, 25) // "on_pb_colorpicker_clicked"

    },
    "MainWindow\0senddata\0\0str\0shotscreen\0"
    "on_pb_fullscreenshot_clicked\0"
    "on_pb_regscreenshot_clicked\0"
    "on_pb_delayedshot_clicked\0receiveData\0"
    "data\0on_pb_widgetscreenshot_clicked\0"
    "on_pb_activewinshot_clicked\0"
    "on_pb_windowsshot_clicked\0"
    "on_pb_fixedsize_clicked\0showWin\0"
    "on_pb_colorpicker_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   86,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   89,    2, 0x08,    3 /* Private */,
       5,    0,   90,    2, 0x08,    4 /* Private */,
       6,    0,   91,    2, 0x08,    5 /* Private */,
       7,    0,   92,    2, 0x08,    6 /* Private */,
       8,    1,   93,    2, 0x08,    7 /* Private */,
      10,    0,   96,    2, 0x08,    9 /* Private */,
      11,    0,   97,    2, 0x08,   10 /* Private */,
      12,    0,   98,    2, 0x08,   11 /* Private */,
      13,    0,   99,    2, 0x08,   12 /* Private */,
      14,    0,  100,    2, 0x08,   13 /* Private */,
      15,    0,  101,    2, 0x08,   14 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPixmap,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->senddata((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->shotscreen(); break;
        case 2: _t->on_pb_fullscreenshot_clicked(); break;
        case 3: _t->on_pb_regscreenshot_clicked(); break;
        case 4: _t->on_pb_delayedshot_clicked(); break;
        case 5: _t->receiveData((*reinterpret_cast< QPixmap(*)>(_a[1]))); break;
        case 6: _t->on_pb_widgetscreenshot_clicked(); break;
        case 7: _t->on_pb_activewinshot_clicked(); break;
        case 8: _t->on_pb_windowsshot_clicked(); break;
        case 9: _t->on_pb_fixedsize_clicked(); break;
        case 10: _t->showWin(); break;
        case 11: _t->on_pb_colorpicker_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::senddata)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPixmap, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::senddata(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
