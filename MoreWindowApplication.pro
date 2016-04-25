#-------------------------------------------------
#
# Project created by QtCreator 2016-03-22T11:22:12
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MoreWindowApplication
TEMPLATE = app
CONFIG += c++11

SOURCES += \
    controlviewwidget.cpp \
    generalwidget.cpp \
    main.cpp \
    mainmenu.cpp \
    secondwidget.cpp \
    thirdwidget.cpp

HEADERS  += \
    controlviewwidget.h \
    generalwidget.h \
    mainmenu.h \
    secondwidget.h \
    thirdwidget.h

FORMS    += \
    generalwidget.ui \
    mainmenu.ui \
    secondwidget.ui \
    thirdwidget.ui
