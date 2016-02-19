/********************************************************************************
** Form generated from reading UI file 'jobpage.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOBPAGE_H
#define UI_JOBPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_jobpage
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *jobpage)
    {
        if (jobpage->objectName().isEmpty())
            jobpage->setObjectName(QStringLiteral("jobpage"));
        jobpage->resize(400, 300);
        buttonBox = new QDialogButtonBox(jobpage);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(jobpage);
        QObject::connect(buttonBox, SIGNAL(accepted()), jobpage, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), jobpage, SLOT(reject()));

        QMetaObject::connectSlotsByName(jobpage);
    } // setupUi

    void retranslateUi(QDialog *jobpage)
    {
        jobpage->setWindowTitle(QApplication::translate("jobpage", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class jobpage: public Ui_jobpage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOBPAGE_H
