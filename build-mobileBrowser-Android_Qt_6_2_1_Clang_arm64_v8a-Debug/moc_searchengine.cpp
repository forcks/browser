/****************************************************************************
** Meta object code from reading C++ file 'searchengine.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mobileBrowser/searchengine.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'searchengine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SearchEngine_t {
    const uint offsetsAndSize[34];
    char stringdata0[199];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_SearchEngine_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_SearchEngine_t qt_meta_stringdata_SearchEngine = {
    {
QT_MOC_LITERAL(0, 12), // "SearchEngine"
QT_MOC_LITERAL(13, 6), // "search"
QT_MOC_LITERAL(20, 0), // ""
QT_MOC_LITERAL(21, 4), // "addr"
QT_MOC_LITERAL(26, 14), // "changeActiveId"
QT_MOC_LITERAL(41, 8), // "activeId"
QT_MOC_LITERAL(50, 15), // "compliteAddress"
QT_MOC_LITERAL(66, 10), // "createPage"
QT_MOC_LITERAL(77, 8), // "savePage"
QT_MOC_LITERAL(86, 14), // "savePageInFile"
QT_MOC_LITERAL(101, 10), // "deletePage"
QT_MOC_LITERAL(112, 11), // "saveHistory"
QT_MOC_LITERAL(124, 11), // "loadHistory"
QT_MOC_LITERAL(136, 25), // "deleteSelectedAddrHistory"
QT_MOC_LITERAL(162, 2), // "id"
QT_MOC_LITERAL(165, 15), // "clearAllHistory"
QT_MOC_LITERAL(181, 17) // "getActiveSearcher"

    },
    "SearchEngine\0search\0\0addr\0changeActiveId\0"
    "activeId\0compliteAddress\0createPage\0"
    "savePage\0savePageInFile\0deletePage\0"
    "saveHistory\0loadHistory\0"
    "deleteSelectedAddrHistory\0id\0"
    "clearAllHistory\0getActiveSearcher"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SearchEngine[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   98,    2, 0x06,    1 /* Public */,
       4,    1,  101,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    1,  104,    2, 0x0a,    5 /* Public */,
       6,    2,  107,    2, 0x0a,    7 /* Public */,
       6,    0,  112,    2, 0x0a,   10 /* Public */,
       7,    1,  113,    2, 0x0a,   11 /* Public */,
       8,    2,  116,    2, 0x0a,   13 /* Public */,
       9,    0,  121,    2, 0x0a,   16 /* Public */,
      10,    1,  122,    2, 0x0a,   17 /* Public */,
      11,    1,  125,    2, 0x0a,   19 /* Public */,
      12,    0,  128,    2, 0x0a,   21 /* Public */,
      13,    1,  129,    2, 0x0a,   22 /* Public */,
      15,    0,  132,    2, 0x0a,   24 /* Public */,
      16,    0,  133,    2, 0x0a,   25 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::QString,

       0        // eod
};

void SearchEngine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SearchEngine *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->search((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->changeActiveId((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->compliteAddress((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->compliteAddress((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->compliteAddress(); break;
        case 5: _t->createPage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->savePage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->savePageInFile(); break;
        case 8: _t->deletePage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->saveHistory((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->loadHistory(); break;
        case 11: _t->deleteSelectedAddrHistory((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->clearAllHistory(); break;
        case 13: { QString _r = _t->getActiveSearcher();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SearchEngine::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SearchEngine::search)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SearchEngine::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SearchEngine::changeActiveId)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject SearchEngine::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_SearchEngine.offsetsAndSize,
    qt_meta_data_SearchEngine,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_SearchEngine_t
, QtPrivate::TypeAndForceComplete<SearchEngine, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>


>,
    nullptr
} };


const QMetaObject *SearchEngine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SearchEngine::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SearchEngine.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SearchEngine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void SearchEngine::search(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SearchEngine::changeActiveId(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
