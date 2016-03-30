#ifndef INVENTORYMANAGEMENT_H
#define INVENTORYMANAGEMENT_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QStandardItemModel>
#include "spooltoadd.h"

namespace Ui {
class inventorymanagement;
}

class inventorymanagement : public QDialog
{
    Q_OBJECT

public:
    explicit inventorymanagement(QWidget *parent = 0);


    ~inventorymanagement();

private slots:
    void on_saveButton_clicked();

private:
    Ui::inventorymanagement *ui;
    QSqlDatabase db;
    void createRowHeaders (QStandardItemModel *model);
    spoolToAdd *tempSpool;

};

#endif // INVENTORYMANAGEMENT_H
