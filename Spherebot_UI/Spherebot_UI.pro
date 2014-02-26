#-------------------------------------------------
#
# Project created by QtCreator 2013-05-30T07:01:31
#
#-------------------------------------------------
#
#This work is licensed under the Creative Commons Attribution-NonCommercial 4.0 International License.
#To view a copy of this license, visit http://creativecommons.org/licenses/by-nc/4.0/.
#

QT       += core gui\
            serialport

QT      += svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Spherebot_UI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    spherebot.cpp \
    txthread.cpp

HEADERS  += mainwindow.h \
    spherebot.h \
    txthread.h \
    stylesheet.h

FORMS    += mainwindow.ui

#CONFIG += static

RESOURCES += \
    res.qrc

OTHER_FILES += \
    stylesheet.txt

CONFIG += static
