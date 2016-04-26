#include "jobpage.h"
#include "ui_jobpage.h"
#include "job_to_add.h"
#include <QVector>
#include <QMessageBox>
#include <QValidator>

jobpage::jobpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::jobpage)
{
    ui->setupUi(this);
    tempJob = new Job_to_Add; // Initialize the temp job (new job) variable.

    // Setting the length assy double validator (only doubles)
    QDoubleValidator *length_assy = new QDoubleValidator(0.0,1000.0,2,this);
    ui->Length_assy_input->setValidator(length_assy);

    // Setting the length atlas double validator (only doubles)
    QDoubleValidator *length_atlas = new QDoubleValidator(0.0,1000.0,2,this);
    ui->Length_atlas_input->setValidator(length_atlas);

    // Seeting the material input validator (only letters)
    QRegExp materialExpression("[A-z]+");
    ui->Material_input->setValidator(new QRegExpValidator(materialExpression,this));

    // Setting the MWI Step input validator


    // Setting the Tube P/N validator (characters and digits)
    QRegExp tubePNExpression ("[A-z]+[0-9]+");
    ui->Tube_pn_input->setValidator(new QRegExpValidator(tubePNExpression,this));


}

jobpage::~jobpage()
{
    delete this->tempJob; // Free memory on close.
    delete ui;
}



void jobpage::on_Add_job_button_clicked()
{



    this->tempJob->assemblyLevel = ui->assemblyLevel_input->displayText().toInt();
//    tempJob->instrument = ui->instrument_label->displayText();
    this->tempJob->tube_pn = ui->Tube_pn_input->displayText();
    this->tempJob->MWI_step = ui->MWI_input->displayText().toInt();
    this->tempJob->material = ui->Material_input->displayText();
    this->tempJob->length_assy = ui->Length_assy_input->displayText().toDouble();
    this->tempJob->length_atlas = ui->Length_atlas_input->displayText().toDouble();
    this->tempJob->isValid = true; //CHANGE ME!!!

    if (tempJob->isValid){
    emit sendJob(tempJob);
    this->close();
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
    this->close();
}


void jobpage::on_pnSearchBttn_clicked()
{
    // Search the connected DB to find thetube matching the search string. Need to parse this string into seperate parts.


}


