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


    ui->jobTableView->setStyleSheet("QHeaderView::section {background-color:grey }");
    ui->jobTableView->setModel(initTableModel());



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
    this->addJobDialog = new jobpage(this);

    connect(addJobDialog,SIGNAL(sendJob(Job_to_Add*)),this,SLOT(receiveNewJob(Job_to_Add*)));


    addJobDialog->exec();
}

void MainWindow::on_removeJobBttn_clicked()
{
    QModelIndex currentIndex = ui->jobTableView->selectionModel()->currentIndex();
    tableModel->removeRow(currentIndex.row());

    int i = currentIndex.row();
    this->jobList.removeAt(i);
    ui->queueNumberLCD->display(jobList.count());
    qDebug() << "I is " << i;
    //this->jobList.erase(currentIndex.internalPointer());
}

void MainWindow::receiveNewJob(Job_to_Add *newJob)
{
     // Assume validation has been completed on the add job page. Add the new job to the vector of jobs in queue.
     this->jobList.append(newJob);

    // Reload the table view widget to show new job in queue.
     ui->jobTableView->setModel(initTableModel());

     // Reload the jobs in queue widget to reflect number of jobs
     ui->queueNumberLCD->display(jobList.count());
}

void MainWindow::setJobHeaderList(QAbstractItemModel *table)
{

    // Set up the headers for the Job display table.

    table->setHeaderData(0,Qt::Horizontal,QObject::tr("Tube P/N"));
    table->setHeaderData(1,Qt::Horizontal,QObject::tr("MWI"));
    table->setHeaderData(2,Qt::Horizontal,QObject::tr("Material"));
    table->setHeaderData(3,Qt::Horizontal,QObject::tr("Length/Assy"));
    table->setHeaderData(4,Qt::Horizontal,QObject::tr("Length/Atlas"));
    table->setHeaderData(5,Qt::Horizontal,QObject::tr("Quantity"));



}



QAbstractItemModel *MainWindow::initTableModel()
{
    int rowCount = 0;
    int colCount = 6;

    rowCount = this->jobList.count();

    tableModel = new QStandardItemModel(rowCount,colCount,this); // Construct table model
    setJobHeaderList(tableModel); // Set the Headers

    if(rowCount != 0){
        // There are jobs to be done.
        for (int row=0; row < rowCount; ++row){
            for (int col=0; col < colCount; ++col){
                QModelIndex index = tableModel->index(row,col,QModelIndex()); // Grabbing the index
                tableModel->setData(index,jobList.at(row)->tableValue(col));
            }
        }
    }


    return tableModel;
}



