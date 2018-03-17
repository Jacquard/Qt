#include "distanciadialog.h"
#include "ui_distanciadialog.h"

DistanciaDialog::DistanciaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DistanciaDialog)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator( new QIntValidator(1,500000, this));

    if (ui->radioButton->isChecked())
    {
        ui->lineEdit->setEnabled(false);
    }
    else if (ui->radioButton_2->isChecked())
    {
        ui->lineEdit->setEnabled(false);
    }
    else if (ui->radioButton_3->isChecked())
    {
        ui->lineEdit->setEnabled(false);
    }
    else if (ui->radioButton_4->isChecked())
    {
        ui->lineEdit->setEnabled(false);
    }
    else if (ui->radioButton_5->isChecked())
    {
        ui->lineEdit->setEnabled(false);
    }
    else
    {
        ui->lineEdit->setEnabled(true);
    }
}

DistanciaDialog::~DistanciaDialog()
{
    delete ui;
}

int DistanciaDialog::distancia()
{
    if (ui->radioButton->isChecked())
    {
        ui->lineEdit->setEnabled(false);
        return 42195;
    }
    else if (ui->radioButton_2->isChecked())
    {
        ui->lineEdit->setEnabled(false);
        return 21097;
    }
    else if (ui->radioButton_3->isChecked())
    {
        ui->lineEdit->setEnabled(false);
        return 15000;
    }
    else if (ui->radioButton_4->isChecked())
    {
        ui->lineEdit->setEnabled(false);
        return 10000;
    }
    else if (ui->radioButton_5->isChecked())
    {
        ui->lineEdit->setEnabled(false);
        return 5000;
    }
    else
    {
        return ui->lineEdit->text().toInt();
    }
}
