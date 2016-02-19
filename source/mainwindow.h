#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

private:
    Ui::MainWindow *ui;
    bool arduinoConnected;
    ArduinoConnectionLib *arduinoMega;

};

#endif // MAINWINDOW_H
