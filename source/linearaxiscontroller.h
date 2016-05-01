#ifndef LINEARAXISCONTROLLER_H
#define LINEARAXISCONTROLLER_H


#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>

class linearAxisController : public QObject
{
    Q_OBJECT
public:
    explicit linearAxisController(QObject *parent = 0);
    bool findMotor();

private:

    void connectMotor(QSerialPort linearMotor);
    void writeData(const QByteArray &data);

private:
    bool motorAvailable;
    static const quint16 CONVERTER_VENDOR_ID = 4292;
    static const quint16 CONVERTER_PRODUCT_ID = 60000;
    QString motor_port_name;
    QSerialPort *linearAxisMotor;
    QString linearAxisMotorDescription;



signals:
    void turnOnAxisCheckbox(bool axis_state);

public slots:
};

#endif // LINEARAXISCONTROLLER_H
