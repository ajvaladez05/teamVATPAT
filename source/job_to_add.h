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
    double diameter; // This may not be needed.
    QString color; // This may not be needed
    double length_assy; // Assembly length
    double length_atlas; // Atlas length
    int desiredNumber;


private:
    // Don't know if need anything here yet




};

#endif // JOB_TO_ADD_H
