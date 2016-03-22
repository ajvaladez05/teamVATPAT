#include "databaseconnector.h"
#include <QtSql>

DataBaseConnector::DataBaseConnector(QObject *parent) : QObject(parent)
{
    // Constructor for database connection

    this->setDbHostHame("");
    this->setDbID("");
    this->setDbName("");
    this->setDbPassword("");
    this->setDbUserName("");

}

void DataBaseConnector::configureDataBase()
{
    this->db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(this->getDbHostHame());
    db.setDatabaseName(this->getDbName());
    db.setUserName(this->getDbUserName());
    db.setPassword(this->getDbPassword());


}

bool DataBaseConnector::openDataBase()
{
    bool isValid = false;
    if (this->db.open()){
        // Print that database was opened
        isValid = true;
    }
    return isValid;
}

QString DataBaseConnector::getDbID() const
{
    return dbID;
}

void DataBaseConnector::setDbID(const QString &value)
{
    dbID = value;
}

QString DataBaseConnector::getDbHostHame() const
{
    return dbHostHame;
}

void DataBaseConnector::setDbHostHame(const QString &value)
{
    dbHostHame = value;
}

QString DataBaseConnector::getDbName() const
{
    return dbName;
}

void DataBaseConnector::setDbName(const QString &value)
{
    dbName = value;
}

QString DataBaseConnector::getDbUserName() const
{
    return dbUserName;
}

void DataBaseConnector::setDbUserName(const QString &value)
{
    dbUserName = value;
}

QString DataBaseConnector::getDbPassword() const
{
    return dbPassword;
}

void DataBaseConnector::setDbPassword(const QString &value)
{
    dbPassword = value;
}

