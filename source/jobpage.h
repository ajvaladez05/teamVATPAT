#ifndef JOBPAGE_H
#define JOBPAGE_H

#include <QDialog>
#include <QList>
#include "job_to_add.h"

namespace Ui {
class jobpage;
}

class jobpage : public QDialog
{
    Q_OBJECT

public:
    explicit jobpage(QWidget *parent = 0);
    ~jobpage();

private slots:
    void on_Add_job_button_clicked();

    void on_Remove_job_button_clicked();

    void on_Cancel_button_clicked();

private:
    Ui::jobpage *ui;
    QList<Job_to_Add*> jobsTocomplete;


};

#endif // JOBPAGE_H
