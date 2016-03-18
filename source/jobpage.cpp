#include "jobpage.h"
#include "ui_jobpage.h"
#include "job_to_add.h"
#include <QVector>
#include <QMessageBox>

jobpage::jobpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::jobpage)
{
    ui->setupUi(this);
    tempJob = new Job_to_Add; // Initialize the temp job (new job) variable.



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
    this->tempJob->tube_pn = ui->Tube_pn_input->displayText().toInt();
//    tempJob->MWI_step = ui->MWI_step_input->displayText();
    this-> tempJob->material = ui->Material_input->displayText();
    this->tempJob->length_assy = ui->Length_assy_input->displayText().toDouble();
    this-> tempJob->length_atlas = ui->Length_atlas_input->displayText().toDouble();

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

void jobpage::on_Remove_job_button_clicked()
{

    // Open new page to read jobsToDo vector and allow the user to remove one.
}

void jobpage::on_Cancel_button_clicked()
{

    // Cancel the process, close window.
    this->close();
}


void jobpage::on_pnSearchBttn_clicked()
{

}
