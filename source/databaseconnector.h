#ifndef DATABASECONNECTOR_H
#define DATABASECONNECTOR_H

#include <QObject>
#include <QString>
#include <QtSql>


class DataBaseConnector : public QObject
{
    Q_OBJECT
public:
    explicit DataBaseConnector(QObject *parent = 0);

    bool openDataBase(const QString &servername); // Try to open database and return true if it can be opened.


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
