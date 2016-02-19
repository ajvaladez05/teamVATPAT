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
    this->arduinoMega->writeToArduino();





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
