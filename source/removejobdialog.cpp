#include "removejobdialog.h"
#include "ui_removejobdialog.h"

removeJobDialog::removeJobDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::removeJobDialog)
{
    ui->setupUi(this);
}

removeJobDialog::~removeJobDialog()
{
    delete ui;
}
