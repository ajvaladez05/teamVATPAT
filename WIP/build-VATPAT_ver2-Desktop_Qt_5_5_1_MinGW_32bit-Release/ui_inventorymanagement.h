/********************************************************************************
** Form generated from reading UI file 'inventorymanagement.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVENTORYMANAGEMENT_H
#define UI_INVENTORYMANAGEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_inventorymanagement
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *inventorymanagement)
    {
        if (inventorymanagement->objectName().isEmpty())
            inventorymanagement->setObjectName(QStringLiteral("inventorymanagement"));
        inventorymanagement->resize(400, 300);
        buttonBox = new QDialogButtonBox(inventorymanagement);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(inventorymanagement);
        QObject::connect(buttonBox, SIGNAL(accepted()), inventorymanagement, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), inventorymanagement, SLOT(reject()));

        QMetaObject::connectSlotsByName(inventorymanagement);
    } // setupUi

    void retranslateUi(QDialog *inventorymanagement)
    {
        inventorymanagement->setWindowTitle(QApplication::translate("inventorymanagement", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class inventorymanagement: public Ui_inventorymanagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVENTORYMANAGEMENT_H
