#include "jobpage.h"
#include "ui_jobpage.h"
#include "job_to_add.h"
#include <QVector>
#include <QMessageBox>
#include <QValidator>
#include <QtSql>
#include "databaseconnector.h"
#include "barcodehandler.h"

jobpage::jobpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::jobpage)
{
    ui->setupUi(this);
    tempJob = new Job_to_Add; // Initialize the temp job (new job) variable.

//    // Setting the length atlas double validator (only doubles)
//    QDoubleValidator *length = new QDoubleValidator(0.0,1000.0,2,this);
//    ui->Length_input->setValidator(length);

//    QIntValidator *vatpat_part_num_validator = new QIntValidator(0,2000,this);
//    ui->vatpat_part_num_input->setValidator(vatpat_part_num_validator);

//    // Seeting the material input validator (only letters)
//    QRegExp materialExpression("[A-z]+");
//    ui->Material_input->setValidator(new QRegExpValidator(materialExpression,this));

//    // Setting the MWI Step input validator


//    // Setting the Tube P/N validator (characters and digits)
//    QRegExp tubePNExpression ("[A-z]+[0-9]+");
//    ui->Tube_pn_input->setValidator(new QRegExpValidator(tubePNExpression,this));

    // Init the database connectors
    partConnection = new DataBaseConnector;
    inventoryConnection = new DataBaseConnector;
    partConnection->openDataBase("part");

    //init the barcode connection
    barcodeConnection = new BarcodeHandler;
    barcodeConnection->barcodeScanner->setPortName("COM1");
    barcodeConnection->barcodeScanner->setBaudRate(QSerialPort::Baud9600);
    barcodeConnection->barcodeScanner->setDataBits(QSerialPort::Data8);
    barcodeConnection->barcodeScanner->setParity(QSerialPort::NoParity);
    barcodeConnection->barcodeScanner->setStopBits(QSerialPort::OneStop);
    barcodeConnection->barcodeScanner->setFlowControl(QSerialPort::NoFlowControl);

    if(barcodeConnection->barcodeScanner->open(QIODevice::ReadWrite))
    {
        qDebug() << "Barcode Scanner is ready for use!";
        qDebug() << "Connect barcode scanner for use.";
        connect(barcodeConnection->barcodeScanner,SIGNAL(readyRead()),this,SLOT(readBarcodeData()));

    }
    else
    {
        qDebug() << "Error opening barcode serial port." << barcodeConnection->barcodeScanner->errorString();

    }



}

jobpage::~jobpage()
{
    //delete this->tempJob; // Free memory on close.
    barcodeConnection->barcodeScanner->close();


    delete ui;
}



void jobpage::on_Add_job_button_clicked()
{



    this->tempJob->assemblyLevel = ui->assemblyLevel_input->displayText().toInt();
    this->tempJob->tube_pn = ui->Tube_pn_input->displayText();
    this->tempJob->MWI_step = ui->MWI_input->displayText();
    this->tempJob->material = ui->Material_input->displayText();
    this->tempJob->length = ui->Length_input->displayText().toDouble();
    this->tempJob->vatpatPartNum = ui->vatpat_part_num_input->displayText().toInt();
    this->tempJob->isValid = true; //CHANGE ME!!!

    if (tempJob->isValid){
    emit sendJob(tempJob);

    this->~jobpage();
    }
    else{
        QMessageBox notValidBox;
        notValidBox.setText("The Job cannot be completed!");
        notValidBox.exec();
    }

}


void jobpage::on_Cancel_button_clicked()
{

    // Cancel the process, close window.
    this->~jobpage();
}

void jobpage::readBarcodeData()
{
   qDebug() << "Barcode data received.";
    QByteArray receivedData;
    receivedData.append(barcodeConnection->barcodeScanner->readAll());

    if(receivedData.count()>0){
        // Use Data to fill in search field
        qDebug() << "barcode data input data found: " << receivedData;
        ui->vatpat_part_num_input->setText(receivedData);
        emit(on_pnSearchBttn_clicked());
        receivedData.clear();


    }
}


void jobpage::on_pnSearchBttn_clicked()
{
    // Search the connected DB to find thetube matching the search string. Need to parse this string into seperate parts.
    // Connect to db

    if(ui->vatpat_part_num_input->text().isEmpty())
    {
        qDebug() << "Vatpat part number field is empty, no query made";
        QMessageBox emptyVatpat;
        emptyVatpat.setText("Please enter a valid Vatpat part number before searching");
        emptyVatpat.exec();
    }
    else{
        Job_to_Add *tempJob1 = new Job_to_Add;
        tempJob1 = partConnection->vatpatPartNumberQuery(ui->vatpat_part_num_input->displayText().toInt());
        qDebug() << "Tempjob1 vatpat part number is: " << tempJob1->vatpatPartNum;


        if(tempJob1->length != 0){
        ui->MWI_input->setText(tempJob1->MWI_step);
        ui->Tube_pn_input->setText(tempJob1->tube_pn);
        ui->Length_input->setText(QString::number(tempJob1->length));
        ui->assemblyLevel_input->setText(QString::number(tempJob1->assemblyLevel));
        ui->vatpat_part_num_input->setText(QString::number(tempJob1->vatpatPartNum));
        ui->Material_input->setText(tempJob1->material);
        }

        else{
            QMessageBox invalidVapatNumber;
            invalidVapatNumber.setText("The Vatpat Part Number is invalid. Please try again.");
            ui->vatpat_part_num_input->clear();
            invalidVapatNumber.exec();
        }
    }


}


