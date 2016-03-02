#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "maintenance.h"
#include "jobpage.h"
#include "inventorymanagement.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
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

    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(buttonClick()));





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

    jobpage jobpageScreen;
    jobpageScreen.setModal(true);
    jobpageScreen.exec();
}

void MainWindow::on_actionMaintenance_triggered()
{
    maintenance maintenanceScreen;
    maintenanceScreen.setModal(true);
    maintenanceScreen.exec();
}

void MainWindow::newJob(Job_to_Add nJob)
{

}

void MainWindow::buttonClick()
{
    if(ui->arduinoCheckBox->isChecked()){
        ui->arduinoCheckBox->setChecked(false);
    }
    else{
        ui->arduinoCheckBox->setChecked(true);
    }
}

void MainWindow::on_addJobBtn_clicked()
{

}

void MainWindow::on_removeJobBttn_clicked()
{

}

void MainWindow::on_pushButton_clicked()
{

}
