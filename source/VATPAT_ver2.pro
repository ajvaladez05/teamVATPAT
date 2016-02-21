#-------------------------------------------------
#
# Project created by QtCreator 2016-02-18T23:13:06
#
#-------------------------------------------------

QT       += core gui serialport
LIBS     += "C:\Users\Anthony\Desktop\School\SeniorDesign\VATPAT\build-ArduinoConnectionLib-Desktop_Qt_5_5_1_MinGW_32bit-Debug\debug\ArduinoConnectionLib.dll"
LIBS     += "C:\Users\Anthony\Desktop\School\SeniorDesign\VATPAT\build-ArduinoConnectionLib-Desktop_Qt_5_5_1_MinGW_32bit-Release\release\ArduinoConnectionLib.dll"
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VATPAT_ver2
TEMPLATE = app

CONFIG += extserialport

SOURCES += main.cpp\
        mainwindow.cpp \
    inventorymanagement.cpp \
    jobpage.cpp \
    maintenance.cpp \
    job_to_add.cpp


HEADERS  += mainwindow.h \
    inventorymanagement.h \
    jobpage.h \
    maintenance.h \
    arduinoconnectionlib.h \
    arduinoconnectionlib_global.h \
    job_to_add.h


FORMS    += mainwindow.ui \
    inventorymanagement.ui \
    jobpage.ui \
    maintenance.ui
