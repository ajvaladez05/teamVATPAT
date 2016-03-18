#ifndef JOB_TO_ADD_H
#define JOB_TO_ADD_H

#include <QString>



class Job_to_Add
{

public:


    Job_to_Add();
    int assemblyLevel;
    QString instrument;
    long int tube_pn;
    double MWI_step;
    QString material;
    double length_assy; // Assembly length
    double length_atlas; // Atlas length
    int desiredNumber;
    bool isValid;


private:
    // Don't know if need anything here yet
    void checkValidity(); // Check if the tube can be produced.




};

#endif // JOB_TO_ADD_H
