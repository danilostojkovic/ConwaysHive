#ifndef RULESDIALOG_H
#define RULESDIALOG_H

#include <QDialog>
#include <QPushButton>

namespace Ui {
class RulesDialog;
}

class RulesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RulesDialog(QWidget *parent = nullptr);
    ~RulesDialog();

private:
    Ui::RulesDialog *ui;

private slots:
    void closeIsClicked();
};

#endif // RULESDIALOG_H
