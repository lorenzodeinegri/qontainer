#-------------------------------------------------
#
# Project created by QtCreator 2019-02-13T13:03:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Qontainer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    View/arttypecombobox.cpp \
    View/categorycombobox.cpp \
    View/details.cpp \
    View/insert.cpp \
    View/list.cpp \
    View/literarytypecombobox.cpp \
    View/menu.cpp \
    View/modifies.cpp \
    View/searchcombobox.cpp \
    main.cpp \
    View/mainwindow.cpp \
    Model/listmodeladapter.cpp \
    Model/sortfilterproxymodel.cpp \
    Model/model.cpp \
    Model/filehandler.cpp \
    Model/date.cpp \
    Model/Hierarchy/material.cpp \
    Model/Hierarchy/artwork.cpp \
    Model/Hierarchy/literarywork.cpp \
    Model/Hierarchy/sculpture.cpp \
    Model/Hierarchy/picture.cpp \
    Model/Hierarchy/act.cpp \
    Model/Hierarchy/letter.cpp

HEADERS += \
    View/arttypecombobox.h \
    View/categorycombobox.h \
    View/details.h \
    View/insert.h \
    View/list.h \
    View/literarytypecombobox.h \
    View/mainwindow.h \
    Model/listmodeladapter.h \
    Model/sortfilterproxymodel.h \
    Model/container.h \
    Model/deeppointer.h \
    Model/model.h \
    Model/filehandler.h \
    Model/date.h \
    Model/Hierarchy/material.h \
    Model/Hierarchy/artwork.h \
    Model/Hierarchy/literarywork.h \
    Model/Hierarchy/sculpture.h \
    Model/Hierarchy/picture.h \
    Model/Hierarchy/act.h \
    Model/Hierarchy/letter.h \
    View/menu.h \
    View/modifies.h \
    View/searchcombobox.h

INCLUDEPATH += \
    Model/Hierarchy/ \
    Model/ \
    View/

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
