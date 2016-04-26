#include "linearaxiscontroller.h"
#include <QDebug>

linearAxisController::linearAxisController(QObject *parent) : QObject(parent)
{

}

bool linearAxisController::findMotor()
{
    /***********************************
     *
     * Use this function to determine if the motor
     * (through RS422 controller)is available to
     * the computer.
     *
     * *********************************/

    //Init the vars
   motorAvailable = false;
   motor_port_name = "";
   linearAxisMotor = new QSerialPort;

   qDebug() << "Number of available ports: " << QSerialPortInfo::availablePorts().length();

   // Loop through each port and get the info.
   foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts())
   {
       qDebug() << "For port: " << serialPortInfo.portName();
       if(serialPortInfo.hasProductIdentifier() && serialPortInfo.hasVendorIdentifier()){
           if(serialPortInfo.vendorIdentifier() == CONVERTER_VENDOR_ID){
               // Vendor ID matches
               qDebug() << "Vendor ID matches: " << serialPortInfo.vendorIdentifier();
               if(serialPortInfo.productIdentifier() == CONVERTER_PRODUCT_ID){
                   //Product ID matches
                   qDebug() << "Found the " << serialPortInfo.description() << " connector!";
                   motor_port_name = serialPortInfo.portName();
                   motorAvailable = true;
               }
           }
       }
   }
   if(motorAvailable){
       //Motor connection found
       qDebug() << "Linear axis motor found. Turning on linear axis checkbox on Main page...";
       emit(turnOnAxisCheckbox(motorAvailable));
   }
   return motorAvailable;
}

