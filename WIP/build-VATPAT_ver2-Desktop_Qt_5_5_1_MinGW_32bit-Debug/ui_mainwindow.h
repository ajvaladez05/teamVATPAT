/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionInventory_Management;
    QAction *actionAdd_Job;
    QAction *actionMaintenance;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuChange_Windows;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        actionInventory_Management = new QAction(MainWindow);
        actionInventory_Management->setObjectName(QStringLiteral("actionInventory_Management"));
        actionAdd_Job = new QAction(MainWindow);
        actionAdd_Job->setObjectName(QStringLiteral("actionAdd_Job"));
        actionMaintenance = new QAction(MainWindow);
        actionMaintenance->setObjectName(QStringLiteral("actionMaintenance"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuChange_Windows = new QMenu(menuFile);
        menuChange_Windows->setObjectName(QStringLiteral("menuChange_Windows"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(menuChange_Windows->menuAction());
        menuChange_Windows->addAction(actionInventory_Management);
        menuChange_Windows->addAction(actionAdd_Job);
        menuChange_Windows->addAction(actionMaintenance);
        mainToolBar->addAction(actionInventory_Management);
        mainToolBar->addAction(actionAdd_Job);
        mainToolBar->addAction(actionMaintenance);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionInventory_Management->setText(QApplication::translate("MainWindow", "Inventory Management", 0));
        actionAdd_Job->setText(QApplication::translate("MainWindow", "Add Job", 0));
        actionMaintenance->setText(QApplication::translate("MainWindow", "Maintenance", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuChange_Windows->setTitle(QApplication::translate("MainWindow", "Change Windows", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
