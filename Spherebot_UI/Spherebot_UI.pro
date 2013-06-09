#-------------------------------------------------
#
# Project created by QtCreator 2013-05-30T07:01:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Spherebot_UI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    spherebot.cpp \
    txthread.cpp

include(3rdparty/qextserialport/src/qextserialport.pri)

HEADERS  += mainwindow.h \
    spherebot.h \
    txthread.h

FORMS    += mainwindow.ui

CONFIG += static
