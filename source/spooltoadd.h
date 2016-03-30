#ifndef SPOOLTOADD_H
#define SPOOLTOADD_H

#include <QObject>
#include <QString>
#include "databaseconnector.h"

class spoolToAdd : public QObject
{
    Q_OBJECT
public:
    explicit spoolToAdd(QObject *parent = 0);

    void setSpoolLocation(int value);

    void setTubePN(const QString &value);

    void setTubeType(const QString &value);

    void setLength(double value);

private:
    int spoolLocation;
    QString tubePN;
    QString tubeType;
    double length;

signals:

public slots:
};

#endif // SPOOLTOADD_H
