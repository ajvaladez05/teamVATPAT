#include "arduinoconnectionlib.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>



ArduinoConnectionLib::ArduinoConnectionLib()
{
    // Initialize the class variables in constructor

    this->arduino = new QSerialPort;
    this->arduino_port_name = "";
    this->arduino_available = false;

}

/*******************************************
 *
 * The following function determines if the
 * Arduino Mega can be found. This is done by
 * knowing the Arduino mega's product id and
 * vendor id previously. Hardcoded at this point
 *
 * *****************************************/

void ArduinoConnectionLib::searchForArduino()
{


    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        if (serialPortInfo.hasVendorIdentifier()&& serialPortInfo.hasProductIdentifier()){
            if (serialPortInfo.vendorIdentifier() == arduino_Mega_vendor_id){
                if(serialPortInfo.productIdentifier()==arduino_Mega_product_id){
                    arduino_port_name = serialPortInfo.portName();
                   this->arduino_available = true;
                }
            }
        }
    }
    return;
}

/******************************************
 *
 * The following is the initialization of the
 * serial connection for the arduino.
 *
 * ***************************************/

bool ArduinoConnectionLib::arduinoConnect()
{


    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        if (serialPortInfo.hasVendorIdentifier()&& serialPortInfo.hasProductIdentifier()){
            if (serialPortInfo.vendorIdentifier() == arduino_Mega_vendor_id){
                if(serialPortInfo.productIdentifier()==arduino_Mega_product_id){
                   this -> arduino_port_name = serialPortInfo.portName();
                   this-> arduino_available = true;
                }
            }
        }
    }

    bool arduinoConnected = false; // Use for error checking
    if(this->arduino_available){
        // Open and configure the port
        arduino->setPortName(arduino_port_name);
        arduino->open(QIODevice::ReadWrite);
        arduino->setBaudRate(QSerialPort::Baud9600); // Set this on arduino
        arduino->setDataBits(QSerialPort::Data8); // Size of a byte
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
        arduinoConnected = true; // May need to do error anaylsis.

        // Do some determination that the arduino is connected at this point.
    }else{
        // Give error message
        arduinoConnected = false;
    }
    return arduinoConnected;
}

/***************************************
 *
 * This is the debugging scan to see the
 * product and vendor ID of the arduino mega
 * initially. May not be used in release
 *
 * ************************************/

void ArduinoConnectionLib::arduinoScan()
{

    qDebug() << "Number of available ports: " << QSerialPortInfo::availablePorts().length();
       foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
           qDebug() << "Has vendor ID: " << serialPortInfo.hasVendorIdentifier();
           if(serialPortInfo.hasVendorIdentifier()){
               qDebug() << "Vendor ID: " << serialPortInfo.vendorIdentifier();
           }
           qDebug() << "Has Product ID: " << serialPortInfo.hasProductIdentifier();
           if(serialPortInfo.hasProductIdentifier()){
               qDebug() << "Product ID: " << serialPortInfo.productIdentifier();
           }
       }
       return;
}

void ArduinoConnectionLib::writeToArduino(QString command)
{
    if (arduino->isWritable()){
        qDebug() << "This thing can be written to!!";
    }
    else{
        qDebug() << "Couldn't write to serial";
    }
}


