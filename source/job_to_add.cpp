#include "job_to_add.h"
#include <QString>
#include <QtSql>
#include "databaseconnector.h"
#define DBHOSTNAME "HOSTNAME"
#define DBNAME "DBNAME"
#define USERNAME "USERNAME"
#define PASSWORD "PASSWORD"

Job_to_Add::Job_to_Add()
{
    // Init the class

    this->assemblyLevel = 0;
    this->instrument = "";
    this->tube_pn = 0;
    this->MWI_step = 0.0;
    this->material = "";
    this->length_assy = 0.0;
    this->length_atlas = 0.0;
    this->isValid = false;
}

int Job_to_Add::getDesiredNumber() const
{
    return desiredNumber;
}

double Job_to_Add::getLength_atlas() const
{
    return length_atlas;
}

double Job_to_Add::getLength_assy() const
{
    return length_assy;
}

QString Job_to_Add::getMaterial() const
{
    return material;
}

double Job_to_Add::getMWI_step() const
{
    return MWI_step;
}

long Job_to_Add::getTube_pn() const
{
    return tube_pn;
}

void Job_to_Add::checkValidity()
{
    // Connect to data base and run determination if the tube can be produced
    DataBaseConnector db;
    db.setDbHostHame(DBNAME);
    db.setDbName(DBNAME);
    db.setDbUserName(USERNAME);
    db.setDbPassword(PASSWORD);

    db.configureDataBase();

    if(db.openDataBase()){
        //Database can be opened. Queuery if there is enough product to produce tube

    }
}

QString Job_to_Add::tableValue(int selection)
{
    // Get a integer value and use it to determine what value of the the job_to_add to return as a QString
    QString stringReturn = "";

    switch (selection){
    case 0:
        // Return Tube P/N
        stringReturn = QString::number(this->getTube_pn());
        break;
    case 1:
        // Return MWI
        stringReturn = QString::number(this->getMWI_step());
        break;
    case 2:
        // Return Material
        stringReturn = this->getMaterial();
        break;
    case 3:
        // Return Length_assy
        stringReturn = QString::number(this->getLength_assy());
        break;
    case 4:
        // Return Length_atlas
        stringReturn = QString::number(this->getLength_atlas());
        break;
    case 5:
        // Quantity
        stringReturn = QString::number(this->getDesiredNumber());
        break;
    }

    return stringReturn;
}



