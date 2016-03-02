#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

    void on_pushButton_clicked();

signals:
    void on_close();
public slots:
    void newJob(Job_to_Add nJob);
    void buttonClick();

private:
    Ui::MainWindow *ui;
    bool arduinoConnected;
    Job_to_Add jobToAdd;
    ArduinoConnectionLib *arduinoMega;

};

#endif // MAINWINDOW_H
