#ifndef BARCODEHANDLER_H
#define BARCODEHANDLER_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>

class BarcodeHandler : public QObject
{
    Q_OBJECT
public:
    explicit BarcodeHandler(QObject *parent = 0);
    bool connectScanner();
    QSerialPort *barcodeScanner;

private:
    bool barCode;
    QString barcode_port_name;

    QString barcodeDescription;

signals:

public slots:
};

#endif // BARCODEHANDLER_H
