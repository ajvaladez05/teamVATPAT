#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QAbstractTableModel>
#include "jobpage.h"
#include "job_to_add.h"
#include "arduinoconnectionlib.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



private slots:
    void on_actionInventory_Management_triggered();

    void on_actionAdd_Job_triggered();

    void on_actionMaintenance_triggered();

    void on_addJobBtn_clicked();

    void on_removeJobBttn_clicked();



signals:
    void on_close();
public slots:
    void receiveNewJob (Job_to_Add *newJob);


private:
    Ui::MainWindow *ui;
    bool arduinoConnected;
    jobpage *addJobDialog;
    ArduinoConnectionLib *arduinoMega;
    QList<Job_to_Add*> jobList;
    QAbstractItemModel *tableModel;
    QList<QString> jobHeaderList;
    void setJobHeaderList(QAbstractItemModel* table);
    QAbstractItemModel* initTableModel();


};

#endif // MAINWINDOW_H
