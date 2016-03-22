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

    QString getDbID() const;
    void setDbID(const QString &value);

    QString getDbHostHame() const;
    void setDbHostHame(const QString &value);

    QString getDbName() const;
    void setDbName(const QString &value);

    QString getDbUserName() const;
    void setDbUserName(const QString &value);

    QString getDbPassword() const;
    void setDbPassword(const QString &value);

    void configureDataBase();
    bool openDataBase(); // Try to open database and return true if it can be opened.


signals:

public slots:

private:
    QString dbID;
    QString dbHostHame;
    QString dbName;
    QString dbUserName;
    QString dbPassword;
    QSqlDatabase db;


    };

#endif // DATABASECONNECTOR_H
