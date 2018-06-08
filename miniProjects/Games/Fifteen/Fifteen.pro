#-------------------------------------------------
#
# Project created by QtCreator 2017-01-16T20:40:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Fifteen
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    start.cpp \
    win.cpp

HEADERS  += mainwindow.h \
    start.h \
    win.h

FORMS    += mainwindow.ui \
    start.ui \
    win.ui

RESOURCES += \
    res.qrc
