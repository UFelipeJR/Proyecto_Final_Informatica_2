QT       += core gui multimedia


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    conevision.cpp \
    entities.cpp \
    main.cpp \
    mezeek.cpp \
    particle.cpp \
    resources.cpp \
    rick.cpp \
    scenery.cpp \
    videogame.cpp \
    weapon.cpp \
    text.cpp \
    headmezeek.cpp

HEADERS += \
    conevision.h \
    entities.h \
    mezeek.h \
    particle.h \
    resources.h \
    rick.h \
    scenery.h \
    videogame.h \
    weapon.h \
    text.h \
    headmezeek.h

FORMS += \
    videogame.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES += \
    Resources/Fondo/wallpaper.jpg
