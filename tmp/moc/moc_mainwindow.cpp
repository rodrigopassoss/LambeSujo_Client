/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[16];
    char stringdata0[303];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 18), // "on_iniciar_clicked"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 10), // "updateData"
QT_MOC_LITERAL(4, 42, 9), // "updateFPS"
QT_MOC_LITERAL(5, 52, 13), // "updateReferee"
QT_MOC_LITERAL(6, 66, 20), // "on_iniciar_2_clicked"
QT_MOC_LITERAL(7, 87, 26), // "on_conectar_serial_clicked"
QT_MOC_LITERAL(8, 114, 26), // "on_atualiza_serial_clicked"
QT_MOC_LITERAL(9, 141, 38), // "on_tipos_variaveis_currentInd..."
QT_MOC_LITERAL(10, 180, 5), // "index"
QT_MOC_LITERAL(11, 186, 30), // "on_objetos_currentIndexChanged"
QT_MOC_LITERAL(12, 217, 27), // "on_time_currentIndexChanged"
QT_MOC_LITERAL(13, 245, 25), // "on_slider_vl_valueChanged"
QT_MOC_LITERAL(14, 271, 5), // "value"
QT_MOC_LITERAL(15, 277, 25) // "on_slider_vr_valueChanged"

    },
    "MainWindow\0on_iniciar_clicked\0\0"
    "updateData\0updateFPS\0updateReferee\0"
    "on_iniciar_2_clicked\0on_conectar_serial_clicked\0"
    "on_atualiza_serial_clicked\0"
    "on_tipos_variaveis_currentIndexChanged\0"
    "index\0on_objetos_currentIndexChanged\0"
    "on_time_currentIndexChanged\0"
    "on_slider_vl_valueChanged\0value\0"
    "on_slider_vr_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    1,   81,    2, 0x08 /* Private */,
      11,    1,   84,    2, 0x08 /* Private */,
      12,    1,   87,    2, 0x08 /* Private */,
      13,    1,   90,    2, 0x08 /* Private */,
      15,    1,   93,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Int,   14,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_iniciar_clicked(); break;
        case 1: _t->updateData(); break;
        case 2: _t->updateFPS(); break;
        case 3: _t->updateReferee(); break;
        case 4: _t->on_iniciar_2_clicked(); break;
        case 5: _t->on_conectar_serial_clicked(); break;
        case 6: _t->on_atualiza_serial_clicked(); break;
        case 7: _t->on_tipos_variaveis_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_objetos_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_time_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_slider_vl_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_slider_vr_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
