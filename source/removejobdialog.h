#ifndef REMOVEJOBDIALOG_H
#define REMOVEJOBDIALOG_H

#include "job_to_add.h"

#include <QDialog>

namespace Ui {
class removeJobDialog;
}

class removeJobDialog : public QDialog
{
    Q_OBJECT

public:
    explicit removeJobDialog(QWidget *parent = 0);
    ~removeJobDialog();

public slots:
    void receiveJobToRemove(Job_to_Add *jobToRemove, int jobNumber);


private slots:


private:
    Ui::removeJobDialog *ui;
};

#endif // REMOVEJOBDIALOG_H
