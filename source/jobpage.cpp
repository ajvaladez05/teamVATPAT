#include "jobpage.h"
#include "ui_jobpage.h"

jobpage::jobpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::jobpage)
{
    ui->setupUi(this);
}

jobpage::~jobpage()
{
    delete ui;
}
