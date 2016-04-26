#include "removejobdialog.h"
#include "ui_removejobdialog.h"
#include "job_to_add.h"
#include <QDebug>

removeJobDialog::removeJobDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::removeJobDialog)
{
    ui->setupUi(this);

}

removeJobDialog::~removeJobDialog()
{
    delete ui;
}

void removeJobDialog::receiveJobToRemove(Job_to_Add *jobToRemove, int jobNumber)
{
    /*************************
     * This function receives the job to be removed from
     * main window and deconstructs it into a string which
     * is then displayed in the line edit.
     * **********************/


    // Create output string:
    QString jobToRemoveString = "";

    jobToRemoveString = "Job Number: " + QString::number(jobNumber+1) + " Tube P/N: " + jobToRemove->getTube_pn();
    ui->jobToRemoveLine->setText(jobToRemoveString);
}


