#include "dialogactualitzamagatzem.h"
#include "ui_dialogactualitzamagatzem.h"

DialogActualitzaMagatzem::DialogActualitzaMagatzem(int actiu, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogActualitzaMagatzem)
{
    ui->setupUi(this);

    QStringList resultat_Bancada;
    QStringList resultat_Electricitat;

    resultat_Bancada = cos_BBDD();
    resultat_Electricitat = electricitat_BBDD();


    if (actiu == 1)
    {
        ui->lineEdit_Bancades->setText(resultat_Bancada.at(0));
        ui->lineEdit_Tolves->setText(resultat_Bancada.at(1));
        ui->lineEdit_Campanes->setText(resultat_Bancada.at(2));
        ui->lineEdit_Portes->setText(resultat_Bancada.at(3));
        ui->lineEdit_topePotes->setText(resultat_Bancada.at(4));

        ui->lineEdit_Plastic30->setText(resultat_Electricitat.at(0));
        ui->lineEdit_Plastic40->setText(resultat_Electricitat.at(1));
        ui->lineEdit_Metall->setText(resultat_Electricitat.at(2));
        ui->lineEdit_Transformadors->setText(resultat_Electricitat.at(3));
        ui->lineEdit_Planxes->setText(resultat_Electricitat.at(4));
        ui->lineEdit_Motor_cinta->setText(resultat_Electricitat.at(5));
        ui->lineEdit_Motor_vibrador->setText(resultat_Electricitat.at(6));

        /*
         * Per guardar els valors a la estructura:
         *  u1.cagonto = resultat_Bancada.at(0).toLatin1().toShort();    // o .toInt();
         */
    }
    else if (actiu == 0)
    {
        ui->lineEdit_Bancades->setText(resultat_Bancada.at(0));
        ui->lineEdit_Tolves->setText(resultat_Bancada.at(1));
        ui->lineEdit_Campanes->setText(resultat_Bancada.at(2));
        ui->lineEdit_Portes->setText(resultat_Bancada.at(3));
        ui->lineEdit_topePotes->setText(resultat_Bancada.at(4));

        ui->lineEdit_Plastic30->setText(resultat_Electricitat.at(0));
        ui->lineEdit_Plastic40->setText(resultat_Electricitat.at(1));
        ui->lineEdit_Metall->setText(resultat_Electricitat.at(2));
        ui->lineEdit_Transformadors->setText(resultat_Electricitat.at(3));
        ui->lineEdit_Planxes->setText(resultat_Electricitat.at(4));
        ui->lineEdit_Motor_cinta->setText(resultat_Electricitat.at(5));
        ui->lineEdit_Motor_vibrador->setText(resultat_Electricitat.at(6));

        ui->lineEdit_Bancades->setEnabled(false);
        ui->lineEdit_Campanes->setEnabled(false);
        ui->lineEdit_Metall->setEnabled(false);
        ui->lineEdit_Planxes->setEnabled(false);
        ui->lineEdit_Plastic30->setEnabled(false);
        ui->lineEdit_Plastic40->setEnabled(false);
        ui->lineEdit_Portes->setEnabled(false);
        ui->lineEdit_Tolves->setEnabled(false);
        ui->lineEdit_topePotes->setEnabled(false);
        ui->lineEdit_Transformadors->setEnabled(false);
        ui->lineEdit_Motor_cinta->setEnabled(false);
        ui->lineEdit_Motor_vibrador->setEnabled(false);

        QStringList resultat_Paisos;
        resultat_Paisos = paisos_BBDD();
    }
}

DialogActualitzaMagatzem::~DialogActualitzaMagatzem()
{
    delete ui;
}

void DialogActualitzaMagatzem::on_buttonBox_accepted()
{

}

void DialogActualitzaMagatzem::on_buttonBox_rejected()
{
    close();
}
