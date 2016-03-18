#include "inventorymanagement.h"
#include "ui_inventorymanagement.h"
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

}

void inventorymanagement::createRowHeaders(QStandardItemModel *model)
{
    for (int i =0; i < 19; ++i){
        model->setVerticalHeaderItem(i,new QStandardItem(QString("Spool: %1").arg(i)));
    }
}


