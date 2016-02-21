#include "jobpage.h"
#include "ui_jobpage.h"
#include "job_to_add.h"
#include <QVector>

jobpage::jobpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::jobpage)
{
    ui->setupUi(this);
    ui->assemblyLevel_input->setValidator(new QIntValidator(0,999,this));
    ui->Tube_pn_input->setValidator(new QIntValidator(this));
    ui->MWI_input->setValidator(new QDoubleValidator(0.5,9999.9,2,this));
    //Need to create rest of validators.




}

jobpage::~jobpage()
{
    delete ui;
}



void jobpage::on_Add_job_button_clicked()
{
    // Create new job class
    Job_to_Add *tempJob;
    tempJob = new Job_to_Add;
    tempJob->assemblyLevel = ui->assemblyLevel_input->displayText().toInt();
//    tempJob->instrument = ui->instrument_label->displayText();
    tempJob->tube_pn = ui->Tube_pn_input->displayText().toInt();
//    tempJob->MWI_step = ui->MWI_step_input->displayText();
    tempJob->material = ui->Material_input->displayText();
    tempJob->diameter = ui->Diameter_input->displayText().toDouble();
    tempJob->color = ui->Color_input->displayText(); // May get deprecated
    tempJob->length_assy = ui->Length_assy_input->displayText().toDouble();
    tempJob->length_atlas = ui->Length_atlas_input->displayText().toDouble();
    this->jobsTocomplete.append(tempJob);
    delete tempJob;


}

void jobpage::on_Remove_job_button_clicked()
{

}

void jobpage::on_Cancel_button_clicked()
{

}
