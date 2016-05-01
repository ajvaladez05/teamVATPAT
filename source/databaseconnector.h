#ifndef DATABASECONNECTOR_H
#define DATABASECONNECTOR_H

#include <QObject>
#include <QString>
#include <QtSql>
#include "job_to_add.h"


class DataBaseConnector : public QObject
{
    Q_OBJECT
public:
    explicit DataBaseConnector(QObject *parent = 0);

    QSqlDatabase openDataBase(const QString &dbName); // Try to open database and return true if it can be opened.

    Job_to_Add* vatpatPartNumberQuery ( int vatpatPartNum);

    Job_to_Add* inventoryMaterialQuery ( Job_to_Add* tempJob, int tube_pn);

    bool checkInventoryDB();

    bool checkPartDB();

signals:

public slots:

private:
   QString driverName;
   QString databaseName;
   QString serverName;
   QString dsnString;
   QString password; // May not need this
   QString username; // May not need this



    };

#endif // DATABASECONNECTOR_H
