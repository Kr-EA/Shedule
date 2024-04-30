QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    confirmaction.cpp \
    dialog.cpp \
    main.cpp \
    mainwindow.cpp \
    nonono.cpp \
    setsubjects.cpp \
    tdialog.cpp

HEADERS += \
    confirmaction.h \
    dialog.h \
    mainwindow.h \
    nonono.h \
    setsubjects.h \
    tdialog.h

FORMS += \
    confirmaction.ui \
    dialog.ui \
    mainwindow.ui \
    nonono.ui \
    setsubjects.ui \
    tdialog.ui

TRANSLATIONS += \
    Shedule_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Groups \
    Subjects \
    Teachers