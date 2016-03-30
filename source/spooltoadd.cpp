#include "spooltoadd.h"

spoolToAdd::spoolToAdd(QObject *parent) : QObject(parent)
{
    // Init the constructor to all 0s and empty strings
    this->spoolLocation = 0;
    this->tubePN = "";
    this->tubeType = "";
    this->length = 0.0;

}

void spoolToAdd::setSpoolLocation(int value)
{
    spoolLocation = value;
}

void spoolToAdd::setTubePN(const QString &value)
{
    tubePN = value;
}

void spoolToAdd::setTubeType(const QString &value)
{
    tubeType = value;
}

void spoolToAdd::setLength(double value)
{
    length = value;
}

