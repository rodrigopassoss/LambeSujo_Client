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
    QByteArrayData data[20];
    char stringdata0[391];
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
QT_MOC_LITERAL(15, 277, 25), // "on_slider_vr_valueChanged"
QT_MOC_LITERAL(16, 303, 20), // "on_finalizar_clicked"
QT_MOC_LITERAL(17, 324, 22), // "on_finalizar_2_clicked"
QT_MOC_LITERAL(18, 347, 20), // "on_iniciar_3_clicked"
QT_MOC_LITERAL(19, 368, 22) // "on_finalizar_3_clicked"

    },
    "MainWindow\0on_iniciar_clicked\0\0"
    "updateData\0updateFPS\0updateReferee\0"
    "on_iniciar_2_clicked\0on_conectar_serial_clicked\0"
    "on_atualiza_serial_clicked\0"
    "on_tipos_variaveis_currentIndexChanged\0"
    "index\0on_objetos_currentIndexChanged\0"
    "on_time_currentIndexChanged\0"
    "on_slider_vl_valueChanged\0value\0"
    "on_slider_vr_valueChanged\0"
    "on_finalizar_clicked\0on_finalizar_2_clicked\0"
    "on_iniciar_3_clicked\0on_finalizar_3_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08 /* Private */,
       3,    0,   95,    2, 0x08 /* Private */,
       4,    0,   96,    2, 0x08 /* Private */,
       5,    0,   97,    2, 0x08 /* Private */,
       6,    0,   98,    2, 0x08 /* Private */,
       7,    0,   99,    2, 0x08 /* Private */,
       8,    0,  100,    2, 0x08 /* Private */,
       9,    1,  101,    2, 0x08 /* Private */,
      11,    1,  104,    2, 0x08 /* Private */,
      12,    1,  107,    2, 0x08 /* Private */,
      13,    1,  110,    2, 0x08 /* Private */,
      15,    1,  113,    2, 0x08 /* Private */,
      16,    0,  116,    2, 0x08 /* Private */,
      17,    0,  117,    2, 0x08 /* Private */,
      18,    0,  118,    2, 0x08 /* Private */,
      19,    0,  119,    2, 0x08 /* Private */,

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
        case 12: _t->on_finalizar_clicked(); break;
        case 13: _t->on_finalizar_2_clicked(); break;
        case 14: _t->on_iniciar_3_clicked(); break;
        case 15: _t->on_finalizar_3_clicked(); break;
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
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
