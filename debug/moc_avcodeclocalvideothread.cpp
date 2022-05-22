/****************************************************************************
** Meta object code from reading C++ file 'avcodeclocalvideothread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../avcodeclocalvideothread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'avcodeclocalvideothread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AVCodecLocalVideoThread_t {
    QByteArrayData data[9];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AVCodecLocalVideoThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AVCodecLocalVideoThread_t qt_meta_stringdata_AVCodecLocalVideoThread = {
    {
QT_MOC_LITERAL(0, 0, 23), // "AVCodecLocalVideoThread"
QT_MOC_LITERAL(1, 24, 15), // "singalVideoData"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 8), // "AVFrame*"
QT_MOC_LITERAL(4, 50, 9), // "pFrameRGB"
QT_MOC_LITERAL(5, 60, 5), // "width"
QT_MOC_LITERAL(6, 66, 6), // "height"
QT_MOC_LITERAL(7, 73, 13), // "initAvdecodec"
QT_MOC_LITERAL(8, 87, 14) // "closeAvdecodec"

    },
    "AVCodecLocalVideoThread\0singalVideoData\0"
    "\0AVFrame*\0pFrameRGB\0width\0height\0"
    "initAvdecodec\0closeAvdecodec"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AVCodecLocalVideoThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   36,    2, 0x08 /* Private */,
       8,    0,   37,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Int,    4,    5,    6,

 // slots: parameters
    QMetaType::Int,
    QMetaType::Int,

       0        // eod
};

void AVCodecLocalVideoThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AVCodecLocalVideoThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->singalVideoData((*reinterpret_cast< AVFrame*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: { int _r = _t->initAvdecodec();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: { int _r = _t->closeAvdecodec();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AVCodecLocalVideoThread::*)(AVFrame * , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AVCodecLocalVideoThread::singalVideoData)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AVCodecLocalVideoThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_AVCodecLocalVideoThread.data,
    qt_meta_data_AVCodecLocalVideoThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AVCodecLocalVideoThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AVCodecLocalVideoThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AVCodecLocalVideoThread.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AVCodecLocalVideoThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void AVCodecLocalVideoThread::singalVideoData(AVFrame * _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
