/********************************************************************************
** Form generated from reading UI file 'funfactsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FUNFACTSDIALOG_H
#define UI_FUNFACTSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_FunFactsDialog
{
public:

    void setupUi(QDialog *FunFactsDialog)
    {
        if (FunFactsDialog->objectName().isEmpty())
            FunFactsDialog->setObjectName(QString::fromUtf8("FunFactsDialog"));
        FunFactsDialog->resize(400, 300);

        retranslateUi(FunFactsDialog);

        QMetaObject::connectSlotsByName(FunFactsDialog);
    } // setupUi

    void retranslateUi(QDialog *FunFactsDialog)
    {
        FunFactsDialog->setWindowTitle(QCoreApplication::translate("FunFactsDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FunFactsDialog: public Ui_FunFactsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FUNFACTSDIALOG_H
