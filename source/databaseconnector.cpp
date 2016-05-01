#include "databaseconnector.h"
#include "job_to_add.h"
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QDebug>

DataBaseConnector::DataBaseConnector(QObject *parent) : QObject(parent)
{
    // Constructor for database connection without loading
    this->databaseName = "";
    this->dsnString = "";
    this->serverName = "";
    this->password = "";
    this->username = "";


}




QSqlDatabase DataBaseConnector::openDataBase(const QString &dbName)
{
bool ok = false;
  qDebug() << QSqlDatabase::drivers();

  QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","MYSQL");
  db.setHostName("localhost");
  db.setDatabaseName(dbName);
  db.setUserName("root");
  db.setPassword("ant10055");


  ok = db.open();
  if(ok)
  {
      qDebug() << "Database opened!";
      qDebug() << "Tables: " << db.tables();
      QSqlQuery query;
      query.exec("SELECT instrument FROM vatpat1.part");

      while(query.next()){
          QString name = query.value(0).toString();
          qDebug() << "Instrument: " << name;
      }
  }
  else
  {
      qDebug() << db.lastError().text();
  }
  db.close();
  return db;
}

Job_to_Add *DataBaseConnector::vatpatPartNumberQuery(int vatpatPartNum)
{
    Job_to_Add *tempJob = new Job_to_Add;
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL", "Part");
    db.setHostName("localhost");
    db.setDatabaseName("vatpat1");
    db.setUserName("root");
    db.setPassword("ant10055");
    QString queryString = QString("SELECT * FROM part WHERE vatpat_part_num = %1").arg(vatpatPartNum);
    if(db.open())
    {
        QSqlQuery query(db);
        qDebug() << "Db opened.";
        qDebug() << db.tables();
        query.exec(queryString);
        while(query.next()){
            qDebug() << "Copy the information from SQL query to tempJob";
            tempJob->MWI_step = query.value(0).toString();
            tempJob->tube_pn = query.value(1).toString();
            tempJob->length = query.value(2).toDouble();
            tempJob->assemblyLevel = query.value(4).toInt();
            tempJob->vatpatPartNum = query.value(5).toInt();
        }
        // Get Material type from inventory DB
        qDebug()<< "Searching inventory for material name.";
        queryString = QString("SELECT * FROM inventory WHERE tube_pn = %1").arg(tempJob->tube_pn);
        QSqlQuery query2(db);
        query2.exec(queryString);
        while(query2.next())
        {
            // Get the material information
            qDebug() << "Getting material information for tube p/n: " << tempJob->tube_pn;
            qDebug() << "Material is: " << query2.value(1).toString();
            tempJob->material = query2.value(1).toString();
        }
    }
    else
    {
        qDebug() << "Database not opened!";
        qDebug() << db.lastError().text();
    }
    db.close();
    return tempJob;
}

Job_to_Add *DataBaseConnector::inventoryMaterialQuery(Job_to_Add *tempJob, int tube_pn)
{
    Job_to_Add *returnJob = new Job_to_Add;
    returnJob = tempJob;
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","inventory");
    db.setHostName("localhost");
    db.setDatabaseName("vatpat1");
    db.setUserName("root");
    db.setPassword("ant10055");

    QString queryString = QString("SELECT * FROM inventory WHERE tube_pn = %1").arg(tube_pn);
    if(db.open())
    {
        QSqlQuery query(db);
        qDebug() << "Inventory Db opened.";
        qDebug () << "Tables: " << db.tables();
        query.exec(queryString);
        while(query.next()){
            qDebug() << "Copy the information from inventory SQL query to find tube material";
            returnJob->material = query.value(1).toString();
        }
    }
    else
    {
        // DB not open
        qDebug() << "Inventory Db not opened!";
        qDebug() << db.lastError().text();
    }
    db.close();
    return returnJob;
}

bool DataBaseConnector::checkInventoryDB()
{
    bool inventoryConnected = false;

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL", "inventory");
    db.setHostName("localhost");
    db.setDatabaseName("vatpat1.");
    db.setUserName("root");
    db.setPassword("ant10055");

    inventoryConnected = db.open();
    if(inventoryConnected)
    {
        qDebug() << db.tables();
        if(db.tables().contains( QLatin1String("inventory")))
        {
            // Inventory DB found
            qDebug() << "Inventory database found!!";

        }
        else{
           qDebug() << "Inventory database not connected!";
           inventoryConnected = false;

        }
    }
    db.close();
    return inventoryConnected;
}

bool DataBaseConnector::checkPartDB()
{
    bool partDBConnected = false;

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL", "MYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("vatpat1");
    db.setUserName("root");
    db.setPassword("ant10055");

    partDBConnected = db.open();
    if(partDBConnected)
    {
        qDebug() << db.tables();
        if(db.tables().contains( QLatin1String("part")))
        {
            // Inventory DB found
            qDebug() << "Part database found!!";

        }
        else{
           qDebug() << "Part database not connected!";
           partDBConnected = false;

        }
    }
    db.close();
    return partDBConnected;
}


