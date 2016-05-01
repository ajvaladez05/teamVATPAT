#ifndef JOBPAGE_H
#define JOBPAGE_H

#include <QDialog>
#include "databaseconnector.h"
#include "barcodehandler.h"
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

    void on_Cancel_button_clicked();

    void readBarcodeData();

    void on_pnSearchBttn_clicked();

signals:
    void sendJob (Job_to_Add *newJob);

public slots:


private:
    Ui::jobpage *ui;
    Job_to_Add *tempJob;
    DataBaseConnector *partConnection;
    DataBaseConnector *inventoryConnection;
    BarcodeHandler *barcodeConnection;





};

#endif // JOBPAGE_H
