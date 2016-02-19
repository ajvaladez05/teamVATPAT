#ifndef INVENTORYMANAGEMENT_H
#define INVENTORYMANAGEMENT_H

#include <QDialog>

namespace Ui {
class inventorymanagement;
}

class inventorymanagement : public QDialog
{
    Q_OBJECT

public:
    explicit inventorymanagement(QWidget *parent = 0);
    ~inventorymanagement();

private:
    Ui::inventorymanagement *ui;
};

#endif // INVENTORYMANAGEMENT_H
