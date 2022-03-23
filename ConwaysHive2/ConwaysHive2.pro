QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bee.cpp \
    cell.cpp \
    controller.cpp \
    deepptr.cpp \
    funfactsdialog.cpp \
    game.cpp \
    hivebeetle.cpp \
    honeybee.cpp \
    insect.cpp \
    larva.cpp \
    main.cpp \
    mainwindow.cpp \
    queenbee.cpp \
    rulesdialog.cpp \
    swarm.cpp \
    wasp.cpp

HEADERS += \
    bee.h \
    cell.h \
    controller.h \
    funfactsdialog.h \
    game.h \
    hivebeetle.h \
    honeybee.h \
    insect.h \
    larva.h \
    mainwindow.h \
    queenbee.h \
    rulesdialog.h \
    wasp.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/binS
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    funfactsdialog.ui \
    rulesdialog.ui

RESOURCES += \
    Resources.qrc

RC_ICONS = logo.ico
