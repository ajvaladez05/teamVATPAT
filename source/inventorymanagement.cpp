#include "inventorymanagement.h"
#include "ui_inventorymanagement.h"

inventorymanagement::inventorymanagement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inventorymanagement)
{
    ui->setupUi(this);
}

inventorymanagement::~inventorymanagement()
{
    delete ui;
}
