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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_jobpage
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLineEdit *MWI_input;
    QLabel *Material_Lable;
    QLineEdit *Material_input;
    QLabel *Diameter_label;
    QLineEdit *Diameter_input;
    QLabel *Color_Label;
    QLineEdit *Color_input;
    QLabel *Lengt_assy_label;
    QLineEdit *Length_assy_input;
    QLabel *Length_atlas_label;
    QLineEdit *Length_atlas_input;
    QLabel *Quantity_label;
    QLineEdit *Quantity_input;
    QLabel *Tube_pn_label;
    QLineEdit *Tube_pn_input;
    QLabel *MWI_label;
    QLabel *assemblyLevel_label;
    QLineEdit *assemblyLevel_input;
    QPushButton *pushButton;
    QTextBrowser *textBrowser;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *Add_job_button;
    QSpacerItem *horizontalSpacer;
    QPushButton *Remove_job_button;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *Cancel_button;

    void setupUi(QDialog *jobpage)
    {
        if (jobpage->objectName().isEmpty())
            jobpage->setObjectName(QStringLiteral("jobpage"));
        jobpage->resize(510, 366);
        formLayoutWidget = new QWidget(jobpage);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(30, 40, 241, 251));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        MWI_input = new QLineEdit(formLayoutWidget);
        MWI_input->setObjectName(QStringLiteral("MWI_input"));

        formLayout->setWidget(2, QFormLayout::FieldRole, MWI_input);

        Material_Lable = new QLabel(formLayoutWidget);
        Material_Lable->setObjectName(QStringLiteral("Material_Lable"));

        formLayout->setWidget(4, QFormLayout::LabelRole, Material_Lable);

        Material_input = new QLineEdit(formLayoutWidget);
        Material_input->setObjectName(QStringLiteral("Material_input"));

        formLayout->setWidget(4, QFormLayout::FieldRole, Material_input);

        Diameter_label = new QLabel(formLayoutWidget);
        Diameter_label->setObjectName(QStringLiteral("Diameter_label"));

        formLayout->setWidget(5, QFormLayout::LabelRole, Diameter_label);

        Diameter_input = new QLineEdit(formLayoutWidget);
        Diameter_input->setObjectName(QStringLiteral("Diameter_input"));

        formLayout->setWidget(5, QFormLayout::FieldRole, Diameter_input);

        Color_Label = new QLabel(formLayoutWidget);
        Color_Label->setObjectName(QStringLiteral("Color_Label"));

        formLayout->setWidget(6, QFormLayout::LabelRole, Color_Label);

        Color_input = new QLineEdit(formLayoutWidget);
        Color_input->setObjectName(QStringLiteral("Color_input"));

        formLayout->setWidget(6, QFormLayout::FieldRole, Color_input);

        Lengt_assy_label = new QLabel(formLayoutWidget);
        Lengt_assy_label->setObjectName(QStringLiteral("Lengt_assy_label"));

        formLayout->setWidget(7, QFormLayout::LabelRole, Lengt_assy_label);

        Length_assy_input = new QLineEdit(formLayoutWidget);
        Length_assy_input->setObjectName(QStringLiteral("Length_assy_input"));

        formLayout->setWidget(7, QFormLayout::FieldRole, Length_assy_input);

        Length_atlas_label = new QLabel(formLayoutWidget);
        Length_atlas_label->setObjectName(QStringLiteral("Length_atlas_label"));

        formLayout->setWidget(8, QFormLayout::LabelRole, Length_atlas_label);

        Length_atlas_input = new QLineEdit(formLayoutWidget);
        Length_atlas_input->setObjectName(QStringLiteral("Length_atlas_input"));

        formLayout->setWidget(8, QFormLayout::FieldRole, Length_atlas_input);

        Quantity_label = new QLabel(formLayoutWidget);
        Quantity_label->setObjectName(QStringLiteral("Quantity_label"));

        formLayout->setWidget(9, QFormLayout::LabelRole, Quantity_label);

        Quantity_input = new QLineEdit(formLayoutWidget);
        Quantity_input->setObjectName(QStringLiteral("Quantity_input"));

        formLayout->setWidget(9, QFormLayout::FieldRole, Quantity_input);

        Tube_pn_label = new QLabel(formLayoutWidget);
        Tube_pn_label->setObjectName(QStringLiteral("Tube_pn_label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, Tube_pn_label);

        Tube_pn_input = new QLineEdit(formLayoutWidget);
        Tube_pn_input->setObjectName(QStringLiteral("Tube_pn_input"));

        formLayout->setWidget(1, QFormLayout::FieldRole, Tube_pn_input);

        MWI_label = new QLabel(formLayoutWidget);
        MWI_label->setObjectName(QStringLiteral("MWI_label"));

        formLayout->setWidget(2, QFormLayout::LabelRole, MWI_label);

        assemblyLevel_label = new QLabel(formLayoutWidget);
        assemblyLevel_label->setObjectName(QStringLiteral("assemblyLevel_label"));

        formLayout->setWidget(10, QFormLayout::LabelRole, assemblyLevel_label);

        assemblyLevel_input = new QLineEdit(formLayoutWidget);
        assemblyLevel_input->setObjectName(QStringLiteral("assemblyLevel_input"));

        formLayout->setWidget(10, QFormLayout::FieldRole, assemblyLevel_input);

        pushButton = new QPushButton(jobpage);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(290, 40, 75, 23));
        textBrowser = new QTextBrowser(jobpage);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(300, 90, 201, 181));
        widget = new QWidget(jobpage);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(110, 310, 307, 25));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Add_job_button = new QPushButton(widget);
        Add_job_button->setObjectName(QStringLiteral("Add_job_button"));

        horizontalLayout->addWidget(Add_job_button);

        horizontalSpacer = new QSpacerItem(28, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        Remove_job_button = new QPushButton(widget);
        Remove_job_button->setObjectName(QStringLiteral("Remove_job_button"));

        horizontalLayout->addWidget(Remove_job_button);

        horizontalSpacer_2 = new QSpacerItem(28, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        Cancel_button = new QPushButton(widget);
        Cancel_button->setObjectName(QStringLiteral("Cancel_button"));

        horizontalLayout->addWidget(Cancel_button);

        QWidget::setTabOrder(Tube_pn_input, MWI_input);
        QWidget::setTabOrder(MWI_input, Material_input);
        QWidget::setTabOrder(Material_input, Diameter_input);
        QWidget::setTabOrder(Diameter_input, Color_input);
        QWidget::setTabOrder(Color_input, Length_assy_input);
        QWidget::setTabOrder(Length_assy_input, Length_atlas_input);
        QWidget::setTabOrder(Length_atlas_input, Quantity_input);
        QWidget::setTabOrder(Quantity_input, assemblyLevel_input);
        QWidget::setTabOrder(assemblyLevel_input, pushButton);
        QWidget::setTabOrder(pushButton, Add_job_button);
        QWidget::setTabOrder(Add_job_button, Remove_job_button);
        QWidget::setTabOrder(Remove_job_button, Cancel_button);
        QWidget::setTabOrder(Cancel_button, textBrowser);

        retranslateUi(jobpage);

        QMetaObject::connectSlotsByName(jobpage);
    } // setupUi

    void retranslateUi(QDialog *jobpage)
    {
        jobpage->setWindowTitle(QApplication::translate("jobpage", "Add Job Page", 0));
        Material_Lable->setText(QApplication::translate("jobpage", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Material</span></p></body></html>", 0));
        Diameter_label->setText(QApplication::translate("jobpage", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Diameter</span></p></body></html>", 0));
        Color_Label->setText(QApplication::translate("jobpage", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Color</span></p></body></html>", 0));
        Lengt_assy_label->setText(QApplication::translate("jobpage", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Length/Assy</span></p></body></html>", 0));
        Length_atlas_label->setText(QApplication::translate("jobpage", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Length/Atlas</span></p></body></html>", 0));
        Quantity_label->setText(QApplication::translate("jobpage", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Quantity</span></p></body></html>", 0));
        Quantity_input->setText(QString());
        Quantity_input->setPlaceholderText(QString());
        Tube_pn_label->setText(QApplication::translate("jobpage", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Tube P/N</span></p></body></html>", 0));
        MWI_label->setText(QApplication::translate("jobpage", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">MWI</span></p></body></html>", 0));
        assemblyLevel_label->setText(QApplication::translate("jobpage", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Assembly Level</span></p></body></html>", 0));
        pushButton->setText(QApplication::translate("jobpage", "Search", 0));
        textBrowser->setHtml(QApplication::translate("jobpage", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600;\">How to use: </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">For automatic filling, use the barcode and scan the tube number to input into <span style=\" text-decoration: underline;\">Tube P/N</span>, then use the search button to autofill the data.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p "
                        "style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">For manual input, simply input the values as desired. </p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Press <span style=\" text-decoration: underline;\">Add Job</span> to add the job to the list of jobs to be completed.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Press <span style=\" text-decoration: underline;\">Remove Job</span> to change over to the the remove job screen.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Press <span style=\" text-decoration: underline;\">Cancel</span> to leav"
                        "e this page without adding a job.</p></body></html>", 0));
        Add_job_button->setText(QApplication::translate("jobpage", "Add Job", 0));
        Remove_job_button->setText(QApplication::translate("jobpage", "Remove Job", 0));
        Cancel_button->setText(QApplication::translate("jobpage", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class jobpage: public Ui_jobpage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOBPAGE_H
