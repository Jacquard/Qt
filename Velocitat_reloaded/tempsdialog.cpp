#include "tempsdialog.h"
#include "ui_tempsdialog.h"

TempsDialog::TempsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TempsDialog)
{
    ui->setupUi(this);
    /*
     * Temps màxim per a córrer:
     *  72 h
     *  59 min
     *  59 seg
     */
    ui->lineEdit->setValidator( new QIntValidator(0, 72, this) );
    ui->lineEdit_2->setValidator( new QIntValidator(0, 59, this) );
    ui->lineEdit_3->setValidator( new QIntValidator(0, 59, this) );
}

TempsDialog::~TempsDialog()
{
    delete ui;
}

float TempsDialog::on_buttonBox_accepted()
{

}

void TempsDialog::on_buttonBox_rejected()
{

}

int TempsDialog::hola()
{
    if ( ui->lineEdit->text().isEmpty() || ui->lineEdit_2->text().isEmpty() || ui->lineEdit_3->text().isEmpty() )
    {
        QMessageBox *alertaCampsBuits = new QMessageBox(this);
        alertaCampsBuits->setIcon(QMessageBox::Warning);
        alertaCampsBuits->setWindowTitle("Error");
        alertaCampsBuits->setText("Els camps no poden estar buits");
        alertaCampsBuits->show();
    }
    else if ( (ui->lineEdit->text().toInt() == 0) && (ui->lineEdit_2->text().toInt() == 0) && (ui->lineEdit_3->text().toInt() == 0))
    {
        QMessageBox *alertaCampsNuls = new QMessageBox(this);
        alertaCampsNuls->setIcon(QMessageBox::Warning);
        alertaCampsNuls->setWindowTitle("Error");
        alertaCampsNuls->setText("Els camps no poden ser nul·ls");
        alertaCampsNuls->show();
    }
    else
    {
        return (ui->lineEdit->text().toInt() * 60*60 + ui->lineEdit_2->text().toInt() * 60 + ui->lineEdit_3->text().toInt());
    }
}
