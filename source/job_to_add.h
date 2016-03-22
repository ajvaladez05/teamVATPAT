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




    long getTube_pn() const;

    double getMWI_step() const;

    QString getMaterial() const;

    double getLength_assy() const;

    double getLength_atlas() const;

    int getDesiredNumber() const;

    QString tableValue(int selection); // Return string value of the job_to_add member



private:
    // Don't know if need anything here yet
    void checkValidity(); // Check if the tube can be produced.




};

#endif // JOB_TO_ADD_H
