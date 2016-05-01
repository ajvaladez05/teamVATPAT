#ifndef JOB_TO_ADD_H
#define JOB_TO_ADD_H

#include <QString>



class Job_to_Add
{

public:


    Job_to_Add();
    int assemblyLevel;
    QString instrument;
    QString tube_pn;
    QString MWI_step;
    QString material;
    double length;
    int vatpatPartNum;
    int desiredNumber;
    bool isValid;




    QString getTube_pn() const;

    QString getMWI_step() const;

    QString getMaterial() const;

    int getDesiredNumber() const;

    QString tableValue(int selection); // Return string value of the job_to_add member

    double getLength() const;

    int getVatpatPartNum() const;

private:
    // Don't know if need anything here yet
    void checkValidity(); // Check if the tube can be produced.




};

#endif // JOB_TO_ADD_H
