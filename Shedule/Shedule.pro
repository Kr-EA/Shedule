QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    UIDgenerator.cpp \
    alertWindow.cpp \
    confirmaction.cpp \
    dialog.cpp \
    groupcreator.cpp \
    main.cpp \
    mainwindow.cpp \
    setsubjects.cpp \
    tdialog.cpp

HEADERS += \
    UIDgenerator.h \
    alertWindow.h \
    confirmaction.h \
    dialog.h \
    groupcreator.h \
    mainwindow.h \
    setsubjects.h \
    tdialog.h

FORMS += \
    alertWindow.ui \
    confirmaction.ui \
    dialog.ui \
    groupcreator.ui \
    mainwindow.ui \
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
