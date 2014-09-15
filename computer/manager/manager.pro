#-------------------------------------------------
#
# Project created by QtCreator 2014-09-12T10:12:17
#
#-------------------------------------------------

QT       += core gui
QT       += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = manager
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    comdialog.cpp \
    dronessetting.cpp \
    controlparser.cpp

HEADERS  += mainwindow.h \
    comdialog.h \
    dronessetting.h \
    controlparser.h

FORMS    += mainwindow.ui \
    comdialog.ui \
    dronessetting.ui
