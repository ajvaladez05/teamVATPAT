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



