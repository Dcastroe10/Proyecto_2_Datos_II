/****************************************************************************
** Meta object code from reading C++ file 'canvasimage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../PaintPlusPlus/canvasimage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'canvasimage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_canvasImage_t {
    QByteArrayData data[6];
    char stringdata0[71];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_canvasImage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_canvasImage_t qt_meta_stringdata_canvasImage = {
    {
QT_MOC_LITERAL(0, 0, 11), // "canvasImage"
QT_MOC_LITERAL(1, 12, 17), // "sendMousePosition"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 4), // "int&"
QT_MOC_LITERAL(4, 36, 16), // "sendMouseClicked"
QT_MOC_LITERAL(5, 53, 17) // "sendMouseReleased"

    },
    "canvasImage\0sendMousePosition\0\0int&\0"
    "sendMouseClicked\0sendMouseReleased"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_canvasImage[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,
       4,    2,   34,    2, 0x06 /* Public */,
       5,    0,   39,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    2,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    2,    2,
    QMetaType::Void,

       0        // eod
};

void canvasImage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<canvasImage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendMousePosition((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->sendMouseClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->sendMouseReleased(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (canvasImage::*)(int & , int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&canvasImage::sendMousePosition)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (canvasImage::*)(int & , int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&canvasImage::sendMouseClicked)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (canvasImage::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&canvasImage::sendMouseReleased)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject canvasImage::staticMetaObject = { {
    &QLabel::staticMetaObject,
    qt_meta_stringdata_canvasImage.data,
    qt_meta_data_canvasImage,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *canvasImage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *canvasImage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_canvasImage.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int canvasImage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void canvasImage::sendMousePosition(int & _t1, int & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void canvasImage::sendMouseClicked(int & _t1, int & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void canvasImage::sendMouseReleased()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
