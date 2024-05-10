/****************************************************************************
** Meta object code from reading C++ file 'tdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../tdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_tDialog_t {
    QByteArrayData data[9];
    char stringdata0[124];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_tDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_tDialog_t qt_meta_stringdata_tDialog = {
    {
QT_MOC_LITERAL(0, 0, 7), // "tDialog"
QT_MOC_LITERAL(1, 8, 28), // "on_ratingSetter_valueChanged"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 5), // "value"
QT_MOC_LITERAL(4, 44, 17), // "on_cancel_clicked"
QT_MOC_LITERAL(5, 62, 18), // "on_confirm_clicked"
QT_MOC_LITERAL(6, 81, 16), // "subjectsListSlot"
QT_MOC_LITERAL(7, 98, 16), // "QVector<QString>"
QT_MOC_LITERAL(8, 115, 8) // "tempData"

    },
    "tDialog\0on_ratingSetter_valueChanged\0"
    "\0value\0on_cancel_clicked\0on_confirm_clicked\0"
    "subjectsListSlot\0QVector<QString>\0"
    "tempData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_tDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x08 /* Private */,
       4,    0,   37,    2, 0x08 /* Private */,
       5,    0,   38,    2, 0x08 /* Private */,
       6,    1,   39,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

void tDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<tDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_ratingSetter_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_cancel_clicked(); break;
        case 2: _t->on_confirm_clicked(); break;
        case 3: _t->subjectsListSlot((*reinterpret_cast< QVector<QString>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QString> >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject tDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_tDialog.data,
    qt_meta_data_tDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *tDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *tDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_tDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int tDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
