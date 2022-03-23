/********************************************************************************
** Form generated from reading UI file 'rulesdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RULESDIALOG_H
#define UI_RULESDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_RulesDialog
{
public:

    void setupUi(QDialog *RulesDialog)
    {
        if (RulesDialog->objectName().isEmpty())
            RulesDialog->setObjectName(QString::fromUtf8("RulesDialog"));
        RulesDialog->resize(400, 300);

        retranslateUi(RulesDialog);

        QMetaObject::connectSlotsByName(RulesDialog);
    } // setupUi

    void retranslateUi(QDialog *RulesDialog)
    {
        RulesDialog->setWindowTitle(QCoreApplication::translate("RulesDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RulesDialog: public Ui_RulesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RULESDIALOG_H
