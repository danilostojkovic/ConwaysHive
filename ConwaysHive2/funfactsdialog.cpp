#include "funfactsdialog.h"
#include "ui_funfactsdialog.h"

FunFactsDialog::FunFactsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FunFactsDialog)
{
    ui->setupUi(this);QPixmap bkgnd(":/Images/funfacts.jpg");
    bkgnd=bkgnd.scaled(1200, 675);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    QPushButton* close=new QPushButton(this);
    close->setGeometry((QRect(1080, 0, 120, 120)));
    close->setIcon(QPixmap(":/Images/cross.png"));
    close->setIconSize(QSize(200, 66));
    close->setStyleSheet("border: 0");
    connect(close, SIGNAL(clicked()), this, SLOT(closeIsClicked()));
}

FunFactsDialog::~FunFactsDialog()
{
    delete ui;
}

void FunFactsDialog::closeIsClicked()
{
    FunFactsDialog::close();
}
