#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    imatges();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::imatges()
{
    QPixmap bkgnd("/home/jordi/Imatges/deviantart/Clint Eastwood/ClintManWithNoName-5x8print_thb.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}
