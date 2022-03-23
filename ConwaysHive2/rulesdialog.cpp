#include "rulesdialog.h"
#include "ui_rulesdialog.h"

RulesDialog::RulesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RulesDialog)
{
    ui->setupUi(this);
    QPixmap bkgnd(":/Images/rules.jpg");
    bkgnd=bkgnd.scaled(1200, 675);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    QPushButton* close=new QPushButton(this);
    close->setGeometry((QRect(1100, -25, 120, 120)));
    close->setIcon(QPixmap(":/Images/cross.png"));
    close->setIconSize(QSize(150, 50));
    close->setStyleSheet("border: 0");
    connect(close, SIGNAL(clicked()), this, SLOT(closeIsClicked()));
}

RulesDialog::~RulesDialog()
{
    delete ui;
}

void RulesDialog::closeIsClicked()
{
    close();
}
