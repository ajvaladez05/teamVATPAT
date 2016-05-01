#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "maintenance.h"
#include "jobpage.h"
#include "inventorymanagement.h"
#include "arduinoconnectionlib.h"
#include "removejobdialog.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QList>
#include <QMessageBox>
#include "databaseconnector.h"




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->initialStartupCheck();

    if(this->initFailMessage != ""){
        // Bring up message box that shows missing items from init
        QMessageBox failStateMessageBox;
        failStateMessageBox.setText(this->initFailMessage);
        failStateMessageBox.exec();
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionInventory_Management_triggered()
{
    qDebug() << "Opening inventory screen";
    inventorymanagement inventoryScreen;
    inventoryScreen.setModal(true);
    inventoryScreen.exec();

}

void MainWindow::on_actionAdd_Job_triggered()
{

    qDebug() << "Opening the add job dialog window";

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
    qDebug() << "Opening the add job dialog window";
    this->addJobDialog = new jobpage(this);

    connect(addJobDialog,SIGNAL(sendJob(Job_to_Add*)),this,SLOT(receiveNewJob(Job_to_Add*)));


    addJobDialog->exec();
}

void MainWindow::on_removeJobBttn_clicked()
{
    QModelIndex currentIndex = ui->jobTableView->selectionModel()->currentIndex();
    int i = currentIndex.row();
    if (i == -1 ){
    // No Jobs to remove
    QMessageBox notValidBox;
    notValidBox.setText("No jobs to remove!!");
    notValidBox.exec();
    }
    if (i == 0){
    // Create function to kill the most current job
    QMessageBox currentJobBox;
    currentJobBox.setText("Cannot delete current job at this point!");
    currentJobBox.exec();
    }

    else{
    this->removeDialog = new removeJobDialog(this);

    connect(this,SIGNAL(sendJobToDelete(Job_to_Add*,int)),removeDialog,SLOT(receiveJobToRemove(Job_to_Add*,int)));

    emit(sendJobToDelete(jobList.at(i),i));

    removeDialog->exec();


    tableModel->removeRow(currentIndex.row());

    this->jobList.removeAt(i);
    ui->queueNumberLCD->display(jobList.count());
    qDebug() << "Job number to erase: " << i;
    //this->jobList.erase(currentIndex.internalPointer());
    }
}

void MainWindow::receiveNewJob(Job_to_Add *newJob)
{
    Job_to_Add *jobToAppend = new Job_to_Add;
    jobToAppend = newJob;
    // Assume validation has been completed on the add job page. Add the new job to the vector of jobs in queue.
     this->jobList.append(jobToAppend);

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
    table->setHeaderData(3,Qt::Horizontal,QObject::tr("Length"));
    table->setHeaderData(4,Qt::Horizontal,QObject::tr("VATPAT Number"));



}



QAbstractItemModel *MainWindow::initTableModel()
{
    int rowCount = 0;
    int colCount = 5;

    rowCount = this->jobList.count();

    tableModel = new QStandardItemModel(rowCount,colCount,this); // Construct table model
    setJobHeaderList(tableModel); // Set the Headers

    if(rowCount != 0){
        qDebug() << "Jobs to be completed. Fill in the table model";
        // There are jobs to be done.
        for (int row=0; row < rowCount; ++row){
            for (int col=0; col < colCount; ++col){
                QModelIndex index = tableModel->index(row,col,QModelIndex()); // Grabbing the index
                qDebug() << index;
                qDebug() << tableModel->setData(index,jobList.at(row)->tableValue(col));
                tableModel->setData(index,jobList.at(row)->tableValue(col));
            }
        }
    }


    return tableModel;
}

void MainWindow::initialStartupCheck()
{
    /*************************************
     *
     * Run an initial check to determine the
     * state of the system before fully coming
     * up. The output of this init will determine
     * the state of the checkboxes.
     *
     *************************************/

    qDebug() << "Setting the initial check boxes...";
    ui->arduinoCheckBox->setStyleSheet("QCheckBox { font: bold 12px  }");
    ui->feedersCheckBox->setStyleSheet("QCheckBox { font: bold 12px  }");
    ui->invDoorCheckBox->setStyleSheet("QCheckBox { font: bold 12px  }");
    ui->tbeLstDBcheckbox->setStyleSheet("QCheckBox { font: bold 12px  }");
    ui->invDBcheckbox->setStyleSheet("QCheckBox { font: bold 12px  }");
    ui->motionSystemCheckBox->setStyleSheet("QCheckBox { font: bold 12px  }");
    ui->arduinoCheckBox->setDisabled(true);
    ui->arduinoCheckBox->setCheckable(true);
    ui->feedersCheckBox->setDisabled(true);
    ui->feedersCheckBox->setCheckable(true);
    ui->invDoorCheckBox->setDisabled(true);
    ui->invDoorCheckBox->setCheckable(true);
    ui->motionSystemCheckBox->setDisabled(true);
    ui->motionSystemCheckBox->setCheckable(true);
    ui->invDBcheckbox->setDisabled(true);
    ui->invDBcheckbox->setCheckable(true);
    ui->tbeLstDBcheckbox->setDisabled(true);
    ui->tbeLstDBcheckbox->setCheckable(true);


    qDebug() << "Setting the main table style (headers and views) and initializing table model";
    ui->jobTableView->setStyleSheet("QHeaderView::section {background-color:grey }");
    ui->jobTableView->setModel(initTableModel());


    // Init the variables
    this->arduinoConnected = false;
    this->tubeDBConnected =false;
    this->inventoryDBConnected = false;
    this->linearMotionConnected = false;
    // Check data base connections

    DataBaseConnector *checkInventoryDB = new DataBaseConnector;
    DataBaseConnector *checkTubeDB = new DataBaseConnector;

    this->inventoryDBConnected = checkInventoryDB->checkInventoryDB();
    this->tubeDBConnected = checkTubeDB->checkPartDB();

    if (inventoryDBConnected){
        ui->invDBcheckbox->setChecked(true);
    }
    else if(~inventoryDBConnected){
        this->initFailMessage = initFailMessage + "Inventory Database not connected.\n";
    }

    if(tubeDBConnected){
        ui->tbeLstDBcheckbox->setChecked(true);
    }
    else if(~tubeDBConnected){
        this->initFailMessage = initFailMessage + "Tube Output Database not connected.\n";
    }

   // Check arduino connection

    this->arduinoConnected = false;
    this->arduinoMega = new ArduinoConnectionLib;
    this->arduinoConnected = arduinoMega->arduinoConnect();

    if (arduinoConnected){
        ui->arduinoCheckBox->setChecked(true);
    }
    else if(~arduinoConnected){
        this->initFailMessage = initFailMessage + "Arduino Mega not connected.\n";
    }

    // Check feeders

    /*********************************
     * TODO: Somehow read the state of the feeders
     * *******************************/

    // Motion System

    /*********************************
     * Use the MDrive serial connection to check
     * state of the motion control system.
     * *******************************/

    this->linearAxisMotor = new linearAxisController;
    this->linearMotionConnected = linearAxisMotor->findMotor();

    if(linearMotionConnected)
    {
        ui->motionSystemCheckBox->setChecked(true);
    }
    else if(~linearMotionConnected){
        this->initFailMessage = initFailMessage + "Linear Motion System not connected.\n";
    }


}





