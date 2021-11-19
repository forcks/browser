/****************************************************************************
** Meta object code from reading C++ file 'appengine.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mobileBrowser/appengine.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'appengine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AppEngine_t {
    const uint offsetsAndSize[20];
    char stringdata0[87];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_AppEngine_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_AppEngine_t qt_meta_stringdata_AppEngine = {
    {
QT_MOC_LITERAL(0, 9), // "AppEngine"
QT_MOC_LITERAL(10, 9), // "goToPages"
QT_MOC_LITERAL(20, 0), // ""
QT_MOC_LITERAL(21, 14), // "goToMainWindow"
QT_MOC_LITERAL(36, 8), // "goToMenu"
QT_MOC_LITERAL(45, 11), // "goToHistory"
QT_MOC_LITERAL(57, 5), // "pages"
QT_MOC_LITERAL(63, 10), // "mainWindow"
QT_MOC_LITERAL(74, 4), // "menu"
QT_MOC_LITERAL(79, 7) // "history"

    },
    "AppEngine\0goToPages\0\0goToMainWindow\0"
    "goToMenu\0goToHistory\0pages\0mainWindow\0"
    "menu\0history"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AppEngine[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x06,    1 /* Public */,
       3,    0,   63,    2, 0x06,    2 /* Public */,
       4,    0,   64,    2, 0x06,    3 /* Public */,
       5,    0,   65,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   66,    2, 0x0a,    5 /* Public */,
       7,    0,   67,    2, 0x0a,    6 /* Public */,
       8,    0,   68,    2, 0x0a,    7 /* Public */,
       9,    0,   69,    2, 0x0a,    8 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AppEngine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AppEngine *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->goToPages(); break;
        case 1: _t->goToMainWindow(); break;
        case 2: _t->goToMenu(); break;
        case 3: _t->goToHistory(); break;
        case 4: _t->pages(); break;
        case 5: _t->mainWindow(); break;
        case 6: _t->menu(); break;
        case 7: _t->history(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AppEngine::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppEngine::goToPages)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AppEngine::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppEngine::goToMainWindow)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (AppEngine::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppEngine::goToMenu)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (AppEngine::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppEngine::goToHistory)) {
                *result = 3;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject AppEngine::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_AppEngine.offsetsAndSize,
    qt_meta_data_AppEngine,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_AppEngine_t
, QtPrivate::TypeAndForceComplete<AppEngine, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *AppEngine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AppEngine::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AppEngine.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AppEngine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void AppEngine::goToPages()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void AppEngine::goToMainWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void AppEngine::goToMenu()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void AppEngine::goToHistory()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
