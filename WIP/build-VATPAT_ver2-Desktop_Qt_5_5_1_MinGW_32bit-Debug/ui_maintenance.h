/********************************************************************************
** Form generated from reading UI file 'maintenance.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINTENANCE_H
#define UI_MAINTENANCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_maintenance
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *maintenance)
    {
        if (maintenance->objectName().isEmpty())
            maintenance->setObjectName(QStringLiteral("maintenance"));
        maintenance->resize(400, 300);
        buttonBox = new QDialogButtonBox(maintenance);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(maintenance);
        QObject::connect(buttonBox, SIGNAL(accepted()), maintenance, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), maintenance, SLOT(reject()));

        QMetaObject::connectSlotsByName(maintenance);
    } // setupUi

    void retranslateUi(QDialog *maintenance)
    {
        maintenance->setWindowTitle(QApplication::translate("maintenance", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class maintenance: public Ui_maintenance {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINTENANCE_H
