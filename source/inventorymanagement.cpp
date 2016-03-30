#include "inventorymanagement.h"
#include "ui_inventorymanagement.h"
#include "arduinoconnectionlib.h"
#include "spooltoadd.h"
#include <QStandardItemModel>

inventorymanagement::inventorymanagement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inventorymanagement)
{
    ui->setupUi(this);
    this->db = QSqlDatabase::addDatabase("QODBC"); // Universal driver
    db.setConnectOptions();

    //QString dsn FINISH THIS

//    db.setDatabaseName(dsn);

//    if(db.open()){
//        qDebug() << "Opened";
//        db.close();
//    }

//    else{
//        qDebug () << "Error = " << db.lastError().text();
//    }

      QStandardItemModel *model = new QStandardItemModel(19,2,this);
      model->setHorizontalHeaderItem(0,new QStandardItem(QString("Spool Installed")));
      model->setHorizontalHeaderItem(1,new QStandardItem(QString("Tube Type")));
      model->setHorizontalHeaderItem(2,new QStandardItem(QString("Length")));
      this->createRowHeaders(model);

      ui->inventoryTable->setStyleSheet("QHeaderView::section { background-color:grey }");
      ui->inventoryTable->setStyleSheet("QHeaderView { font-size: 10pt;");
      ui->inventoryTable->setModel(model);




}

inventorymanagement::~inventorymanagement()
{
    delete ui;
}

void inventorymanagement::on_saveButton_clicked()
{
    // Check if safety door opened. This is not implemented but should be used later.
    // Need the arduino connected and request a call to see if inventory door is opened. Should probably only want the user to be able to add spools when door is open to avoid mistakes.

    // bool doorOpened = false;
    // Create arduino connection here
    // doorOpened = some function call to see if safety door is opened
    // if safety door is opened, continue with save inventory function else, bring up pop up that safety door has not yet been opened and that no inventory can be added at this time.

    // Init temp spool
    this->tempSpool = new spoolToAdd;

    //VERIFY THE VALUES!!!
    /***************************
     * FINISH ME!!!
     * *************************/


    // If values verified, fetch values from input
    /**************************
     * FINISH ME!!
     * ************************/

    tempSpool->setLength(ui->lengthLineEdit->text().toDouble());
    tempSpool->setSpoolLocation(ui->spoolLocationLineEdit->text().toInt());
    tempSpool->setTubePN(ui->tubeNumberLineEdit->text());
    tempSpool->setTubeType(ui->tubeTypeLineEdit->text());

    /***************************************************
     * PASS THIS OBJECT INTO THE DATABASE ADD STRING
     * UPDATE THE MODEL FOR THE TABLE TO REFLECT CHANGES
     * *************************************************/



}

void inventorymanagement::createRowHeaders(QStandardItemModel *model)
{
    for (int i =0; i < 19; ++i){
        model->setVerticalHeaderItem(i,new QStandardItem(QString("Spool: %1").arg(i)));
    }
}


