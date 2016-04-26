#include "databaseconnector.h"
#include <QtSql>

DataBaseConnector::DataBaseConnector(QObject *parent) : QObject(parent)
{
    // Constructor for database connection without loading
    this->databaseName = "";
    this->dsnString = "";
    this->serverName = "";
    this->password = "";
    this->username = "";


}




bool DataBaseConnector::openDataBase(const QString &servername)
{
    bool isOpen = false;
    this->serverName = "LOCALHOST\\SQLEXPRESS";

    if (servername == "INVENTORY SERVER"){
        // Create connection string for inventory server
        this->dsnString = "FINISH THIS CONNECTION STRING";
    }

    else if(servername == "TUBE SERVER"){
        this->dsnString = "FINISH THIS CONNECTION STRING";
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC"); // Universal drive for SQL
    db.setConnectOptions();
    db.setDatabaseName(this->dsnString);

    if (db.open())
    {
        // Database can be opened for business
        isOpen = true;
    }

    else
    {
        // PRINT ERROR STRING TO LOGGER
        isOpen = false;
    }

    return isOpen;
}
