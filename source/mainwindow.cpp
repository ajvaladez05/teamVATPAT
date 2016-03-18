#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "maintenance.h"
#include "jobpage.h"
#include "inventorymanagement.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QList>
#include "arduinoconnectionlib.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->arduinoConnected = false;
    this->arduinoMega = new ArduinoConnectionLib;
    this->arduinoConnected = arduinoMega->arduinoConnect();

    // Create setup funcitons for these...
    ui->arduinoCheckBox->setStyleSheet("QCheckBox { font: bold 12px  }");
    ui->feedersCheckBox->setStyleSheet("QCheckBox { font: bold 12px  }");
    ui->invDoorCheckBox->setStyleSheet("QCheckBox { font: bold 12px  }");
    ui->motionSystemCheckBox->setStyleSheet("QCheckBox { font: bold 12px  }");
    ui->arduinoCheckBox->setDisabled(true);
    ui->feedersCheckBox->setDisabled(true);
    ui->invDoorCheckBox->setDisabled(true);
    ui->motionSystemCheckBox->setDisabled(true);





}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionInventory_Management_triggered()
{
    inventorymanagement inventoryScreen;
    inventoryScreen.setModal(true);
    inventoryScreen.exec();

}

void MainWindow::on_actionAdd_Job_triggered()
{


    this->addJobDialog = new jobpage(this);

//    jobpage jobpageScreen;
//    jobpageScreen.setModal(true);
//    jobpageScreen.exec();


    connect(addJobDialog,SIGNAL(sendJob(Job_to_Add*)),this,SLOT(receiveNewJob(Job_to_Add*)));

    addJobDialog->exec();
}

void MainWindow::on_actionMaintenance_triggered()
{
    maintenance maintenanceScreen;
    maintenanceScreen.setModal(true);
    maintenanceScreen.exec();
}




void MainWindow::on_addJobBtn_clicked()
{

}

void MainWindow::on_removeJobBttn_clicked()
{

}

void MainWindow::receiveNewJob(Job_to_Add *newJob)
{
  // Assume validation has been completed on the add job page. Add the new job to the vector of jobs in queue.
  this->jobList.append(newJob);
    // Reload the text view widget to show new job in queue.
}



