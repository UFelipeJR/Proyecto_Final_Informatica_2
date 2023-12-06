/****************************************************************************
** Meta object code from reading C++ file 'videogame.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Beta Etapa 3/Proyecto_Final/videogame.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'videogame.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSvideogameENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSvideogameENDCLASS = QtMocHelpers::stringData(
    "videogame",
    "punch",
    "",
    "changeLevel",
    "game",
    "throwWeapon",
    "powerUp",
    "initVideoGame",
    "killrick",
    "finish",
    "menuAnimation",
    "level1",
    "level2",
    "videos"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSvideogameENDCLASS_t {
    uint offsetsAndSizes[28];
    char stringdata0[10];
    char stringdata1[6];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[5];
    char stringdata5[12];
    char stringdata6[8];
    char stringdata7[14];
    char stringdata8[9];
    char stringdata9[7];
    char stringdata10[14];
    char stringdata11[7];
    char stringdata12[7];
    char stringdata13[7];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSvideogameENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSvideogameENDCLASS_t qt_meta_stringdata_CLASSvideogameENDCLASS = {
    {
        QT_MOC_LITERAL(0, 9),  // "videogame"
        QT_MOC_LITERAL(10, 5),  // "punch"
        QT_MOC_LITERAL(16, 0),  // ""
        QT_MOC_LITERAL(17, 11),  // "changeLevel"
        QT_MOC_LITERAL(29, 4),  // "game"
        QT_MOC_LITERAL(34, 11),  // "throwWeapon"
        QT_MOC_LITERAL(46, 7),  // "powerUp"
        QT_MOC_LITERAL(54, 13),  // "initVideoGame"
        QT_MOC_LITERAL(68, 8),  // "killrick"
        QT_MOC_LITERAL(77, 6),  // "finish"
        QT_MOC_LITERAL(84, 13),  // "menuAnimation"
        QT_MOC_LITERAL(98, 6),  // "level1"
        QT_MOC_LITERAL(105, 6),  // "level2"
        QT_MOC_LITERAL(112, 6)   // "videos"
    },
    "videogame",
    "punch",
    "",
    "changeLevel",
    "game",
    "throwWeapon",
    "powerUp",
    "initVideoGame",
    "killrick",
    "finish",
    "menuAnimation",
    "level1",
    "level2",
    "videos"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSvideogameENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   86,    2, 0x06,    1 /* Public */,
       3,    0,   87,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   88,    2, 0x08,    3 /* Private */,
       5,    0,   89,    2, 0x08,    4 /* Private */,
       6,    0,   90,    2, 0x08,    5 /* Private */,
       7,    0,   91,    2, 0x08,    6 /* Private */,
       8,    0,   92,    2, 0x08,    7 /* Private */,
       9,    0,   93,    2, 0x08,    8 /* Private */,
      10,    0,   94,    2, 0x08,    9 /* Private */,
      11,    0,   95,    2, 0x08,   10 /* Private */,
      12,    0,   96,    2, 0x08,   11 /* Private */,
      13,    0,   97,    2, 0x08,   12 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject videogame::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSvideogameENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSvideogameENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSvideogameENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<videogame, std::true_type>,
        // method 'punch'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'changeLevel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'game'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'throwWeapon'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'powerUp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'initVideoGame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'killrick'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'finish'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'menuAnimation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'level1'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'level2'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'videos'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void videogame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<videogame *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->punch(); break;
        case 1: _t->changeLevel(); break;
        case 2: _t->game(); break;
        case 3: _t->throwWeapon(); break;
        case 4: _t->powerUp(); break;
        case 5: _t->initVideoGame(); break;
        case 6: _t->killrick(); break;
        case 7: _t->finish(); break;
        case 8: _t->menuAnimation(); break;
        case 9: _t->level1(); break;
        case 10: _t->level2(); break;
        case 11: _t->videos(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (videogame::*)();
            if (_t _q_method = &videogame::punch; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (videogame::*)();
            if (_t _q_method = &videogame::changeLevel; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject *videogame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *videogame::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSvideogameENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int videogame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void videogame::punch()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void videogame::changeLevel()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
