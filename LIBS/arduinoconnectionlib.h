#ifndef ARDUINOCONNECTIONLIB_H
#define ARDUINOCONNECTIONLIB_H

#include "arduinoconnectionlib_global.h"
#include <QSerialPort>
#include <QString>

class ARDUINOCONNECTIONLIBSHARED_EXPORT ArduinoConnectionLib
{

public:
    ArduinoConnectionLib();
    void searchForArduino();
    bool arduinoConnect();
    void arduinoScan(); //This is a debug search for the arduino. Consider removing
    void writeToArduino(QString command);
private:
    QSerialPort *arduino;
    static const quint16 arduino_Mega_vendor_id = 9025;
    static const quint16 arduino_Mega_product_id = 66;
    QString arduino_port_name;
    bool arduino_available;

};

#endif // ARDUINOCONNECTIONLIB_H
