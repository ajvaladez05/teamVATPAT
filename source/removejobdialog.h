#ifndef REMOVEJOBDIALOG_H
#define REMOVEJOBDIALOG_H

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

private:
    Ui::removeJobDialog *ui;
};

#endif // REMOVEJOBDIALOG_H
