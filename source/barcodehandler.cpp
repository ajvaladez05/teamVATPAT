#include "barcodehandler.h"
#include <QDebug>
#include <QtSerialPort/QSerialPort>

BarcodeHandler::BarcodeHandler(QObject *parent) : QObject(parent)
{
    this->barcodeScanner = new QSerialPort;
}

bool BarcodeHandler::connectScanner()
{
    bool barcodeFound = false;
    qDebug() << "Connecting the barcode scanner.";

    this->barcodeScanner->setPortName("COM21");
    this->barcodeScanner->setBaudRate(QSerialPort::Baud9600);
    this->barcodeScanner->setDataBits(QSerialPort::Data8);
    this->barcodeScanner->setParity(QSerialPort::NoParity);
    this->barcodeScanner->setStopBits(QSerialPort::OneStop);
    this->barcodeScanner->setFlowControl(QSerialPort::NoFlowControl);

    if(this->barcodeScanner->open(QIODevice::ReadWrite))
    {
        qDebug() << "Barcode Scanner is ready for use!";
        barcodeFound = true;
    }
    else
    {
        qDebug() << "Error opening barcode serial port." << barcodeScanner->errorString();
        barcodeFound = false;
    }
    return barcodeFound;
}


