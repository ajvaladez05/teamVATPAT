#-------------------------------------------------
#
# Project created by QtCreator 2016-02-18T14:19:10
#
#-------------------------------------------------

QT       -= gui
QT       += serialport core


TARGET = ArduinoConnectionLib
TEMPLATE = lib

DEFINES += ARDUINOCONNECTIONLIB_LIBRARY

SOURCES += arduinoconnectionlib.cpp

HEADERS += arduinoconnectionlib.h\
        arduinoconnectionlib_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
