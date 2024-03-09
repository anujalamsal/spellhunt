QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    desert.cpp \
    island.cpp \
    lose.cpp \
    losedesert.cpp \
    loseisland.cpp \
    main.cpp \
    dialog.cpp \
    sec.cpp \
    win.cpp \
    windesert.cpp \
    winisland.cpp

HEADERS += \
    desert.h \
    dialog.h \
    island.h \
    lose.h \
    losedesert.h \
    loseisland.h \
    sec.h \
    win.h \
    windesert.h \
    winisland.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    desert.ui \
    island.ui \
    lose.ui \
    losedesert.ui \
    loseisland.ui \
    sec.ui \
    win.ui \
    windesert.ui \
    winisland.ui

RESOURCES += \
    images.qrc
