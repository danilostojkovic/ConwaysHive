#ifndef FUNFACTSDIALOG_H
#define FUNFACTSDIALOG_H

#include <QDialog>
#include <QPushButton>

namespace Ui {
class FunFactsDialog;
}

class FunFactsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FunFactsDialog(QWidget *parent = nullptr);
    ~FunFactsDialog();

private:
    Ui::FunFactsDialog *ui;

private slots:
    void closeIsClicked();
};

#endif // FUNFACTSDIALOG_H
