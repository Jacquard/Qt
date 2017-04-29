#include "dialogprevisiomagatzem.h"
#include "ui_dialogprevisiomagatzem.h"

#include <QMessageBox>

DialogPrevisioMagatzem::DialogPrevisioMagatzem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPrevisioMagatzem)
{
    ui->setupUi(this);

    QString textAlarmes = "Establir les alarmes per a la fabricació. Útil per a saber quantes parts es poden fabricar.";
    ui->label_IntroAlarmes->setWordWrap(true);
    ui->label_IntroAlarmes->setText(textAlarmes);

    ui->lineEdit_Bancades->setValidator( new QIntValidator(0, 20, this) );
    ui->lineEdit_Campanes->setValidator( new QIntValidator(0, 20, this) );
    ui->lineEdit_Tolves->setValidator( new QIntValidator(0, 20, this) );
    ui->lineEdit_Cintes->setValidator( new QIntValidator(0, 20, this) );
}

DialogPrevisioMagatzem::~DialogPrevisioMagatzem()
{
    delete ui;
}

/*
 * Per canviar el color de la barra:
 *
 *     QPalette p = this->palette();
 *     p.setColor(QPalette::Highlight, QColor(Qt::red));
 *     this->setPalette(p);
 */

void DialogPrevisioMagatzem::on_pushButton_clicked()
{
    short num_bancades;
    short num_campanes;
    short num_tolves;
    short num_cintes;

    if (ui->lineEdit_Bancades->text().toLatin1() == "")
    {
        QMessageBox::warning(this, "Error dades", "Has d'escriure alguna cosa a bancades");
    }
    else if (ui->lineEdit_Campanes->text().toLatin1() == "")
    {
        QMessageBox::warning(this, "Error dades", "Has d'escriure un nombre a campanes");
    }
    else if (ui->lineEdit_Cintes->text().toLatin1() == "")
    {
        QMessageBox::warning(this, "Error dades", "Has d'escriure un nombre a cintes");
    }
    else if (ui->lineEdit_Tolves->text().toLatin1() == "")
    {
        QMessageBox::warning(this, "Error dades", "Has d'escriure un nombre a tolves");
    }
    else
    {
        num_bancades = ui->lineEdit_Bancades->text().toLatin1().toShort();
        num_campanes = ui->lineEdit_Campanes->text().toLatin1().toShort();
        num_tolves = ui->lineEdit_Tolves->text().toLatin1().toShort();
        num_cintes = ui->lineEdit_Cintes->text().toLatin1().toShort();

        crearBancada();
    }
}

void DialogPrevisioMagatzem::crearCampana(int controlLogo)
{
    Campana campana;
    campana = funcio_NovaCampana();

    int control_Fabricacio = 0;

    campana.campana;
    campana.cargols_c514;
    campana.cargols_c516;
    campana.cargols_c616;
    campana.cargols_frontals;
    campana.cinta_espuma;
    campana.cordo_negre;
    campana.femelles_frm5 >= 8 ? control_Fabricacio += 1 : control_Fabricacio += 0;
    campana.femelles_frm6 >= 4 ? control_Fabricacio += 1 : control_Fabricacio += 0;
    campana.guies_laterals >= 2 ? control_Fabricacio += 1 : control_Fabricacio += 0;
    /* S'ha de tenir en compte que algunes campanes no porten logo
     * També s'haurà de tenir en compte pels reblons
     * Introduir un valor extern de control control */
    campana.logo_gran >= 1 ? control_Fabricacio += 1 : control_Fabricacio += 0;
    campana.reblons_30 >= 4 ? control_Fabricacio += 1 : control_Fabricacio += 0;
    campana.nances >= 2 ? control_Fabricacio += 1: control_Fabricacio += 0;
    campana.tapa_frontal >= 1 ? control_Fabricacio += 1 : control_Fabricacio += 0;
    campana.tapa_superior >= 1 ? control_Fabricacio += 1 : control_Fabricacio += 0;
    campana.tope_tapa_frontal >= 2 ? control_Fabricacio += 1 : control_Fabricacio += 0;
    campana.travesser >= 1 ? control_Fabricacio += 1 : control_Fabricacio += 0;
    campana.volanderes_rm5 >= 4 ?  control_Fabricacio += 1 : control_Fabricacio += 0;

    if (controlLogo == 0)
    {
        if (control_Fabricacio >= 16)
        {
            /* Crear crida a funció que RESTI de la BBDD els components de la campana */
            //funcio_nova
            /* La següent funció crida a la funció que imprimeix a la OF si hi ha
             * Per campanes (verd) (1)
             * O no n'hi ha (vermell) (0) */
            //columna_Campana(1);
        }
        else
        {
            //columna_Campana(0);
        }
    }
    else if (controlLogo == 1)
    {
        if (control_Fabricacio >= 18)
        {
            /* Crear crida a funció que RESTI de la BBDD els components de la campana */
            //funcio_nova
            /* La següent funció crida a la funció que imprimeix a la OF si hi ha
             * Per campanes (verd) (1)
             * O no n'hi ha (vermell) (0) */
            //columna_Campana(1);
        }
        else
        {
            //columna_Campana(0);
        }
    }
}

void DialogPrevisioMagatzem::crearTolva()
{
    Tolva tolva;
    tolva = funcio_NovaTolva();

    int controlFabricacio = 0;

    tolva.cinta.autolubricats ? controlFabricacio += 1 : controlFabricacio += 0;
    /* tolva.cinta.cargols_c48_funda_metallica i tolva.cinta.detector_nivell.cargols_c48 és el mateix */
    tolva.cinta.cargols_c48_funda_metallica >= 4 ? controlFabricacio += 1 : controlFabricacio += 0;
    tolva.cinta.cargols_laterals_avellanado >= 6 ? controlFabricacio += 1 : controlFabricacio += 0;
    tolva.cinta.cilindre_frontal >= 1 ? controlFabricacio += 1 : controlFabricacio += 0;
    tolva.cinta.cilindre_Motor >= 1 ? controlFabricacio += 1 : controlFabricacio += 0;
    tolva.cinta.cinta >= 1 ? controlFabricacio += 1 : controlFabricacio += 0;
    tolva.cinta.funda_metallica_motor >= 1 ? controlFabricacio += 1 : controlFabricacio += 0;
    tolva.cinta.lateral_esquerra >= 1 ? controlFabricacio += 1 : controlFabricacio += 0;
    tolva.cinta.lateral_Motor >= 1 ? controlFabricacio += 1 : controlFabricacio += 0;
    tolva.cinta.pg9 >= 1 ? controlFabricacio += 1 : controlFabricacio += 0;

    tolva.cinta.tensor.cargols_lateral >= 4 ? controlFabricacio += 1 : controlFabricacio += 0;
    tolva.cinta.tensor.cos_tensor >= 2 ? controlFabricacio += 1 : controlFabricacio += 0;
    tolva.cinta.tensor.tensor >= 2 ? controlFabricacio += 1 : controlFabricacio += 0;
    tolva.cinta.tensor.cargol_tensor >= 2 ? controlFabricacio += 1 : controlFabricacio += 0;
    tolva.cinta.tensor.femella_tensor >= 2 ? controlFabricacio += 1 : controlFabricacio += 0;

    tolva.cinta.motor.brida_motor >= 1 ? controlFabricacio += 1 : controlFabricacio += 0;
    tolva.cinta.motor.cargols_c512_motor >= 3 ? controlFabricacio += 1 : controlFabricacio += 0;
    tolva.cinta.motor.cinta_americana >= 50 ? controlFabricacio += 1 : controlFabricacio += 0;
    tolva.cinta.motor.dentada_gran >= 1 ? controlFabricacio += 1 : controlFabricacio += 0;
    tolva.cinta.motor.dentada_petita >= 1 ? controlFabricacio += 1 : controlFabricacio += 0;
    tolva.cinta.motor.funda_motor >= 1 ? controlFabricacio += 1 : controlFabricacio += 0;
    tolva.cinta.motor.motor_cinta >= 1 ? controlFabricacio += 1 : controlFabricacio += 0;
    tolva.cinta.motor.pasador_elastic_d3 >= 1 ? controlFabricacio += 1 : controlFabricacio += 0;
    tolva.cinta.motor.pasador_elastic_d5 >= 1 ? controlFabricacio += 1 : controlFabricacio += 0;

    tolva.cargols_c525_allen >= 2 ? controlFabricacio += 1 : controlFabricacio += 0;
    /* La Tolva utilitza 5 cargols 8x12 Allen, 2 per apretar el motor i
       3 per apretar la tolva a la bancada.
       La bancada no els utilitza */
    tolva.cargols_c812_allen >= 5 ? controlFabricacio += 1 : controlFabricacio += 0;

    tolva.cinta.detector_nivell.barra >= 1 ? controlFabricacio += 1 : controlFabricacio += 0;
    tolva.cinta.detector_nivell.cargols_subjeccio_tapa >= 2 ? controlFabricacio += 1 : controlFabricacio += 0;
    tolva.cinta.detector_nivell.cos_detector >= 1 ? controlFabricacio += 1 : controlFabricacio += 0;
    tolva.cinta.detector_nivell.piu_detector_nivell >= 1 ? controlFabricacio += 1 : controlFabricacio += 0;
    tolva.cinta.detector_nivell.presoner_rm3 >= 1 ? controlFabricacio += 1 : controlFabricacio += 0;
    tolva.cinta.detector_nivell.suport >= 1 ? controlFabricacio += 1 : controlFabricacio += 0;
    tolva.cinta.detector_nivell.tapa >= 1 ? controlFabricacio += 1 : controlFabricacio += 0;
    tolva.cinta.detector_nivell.volanderes_vrm4 >= 2 ? controlFabricacio += 1 : controlFabricacio += 0;

    if (controlFabricacio == 34)
    {
        //columna_Tolva(1);
    }
    else if (controlFabricacio != 34)
    {
        //columna_Tolva(0);
    }
}

void DialogPrevisioMagatzem::crearBancada()//int ControlCuba, int controlCordill)
{
    Bancada bancada;
    bancada = funcio_NovaBancada();

    float valueBancades = (float)bancada.bancada / 20 * 100;
    float valueCargols810 = (float)bancada.cargols_810 / 20 * 100;
    float valueCargolsLogoCuba = (float)bancada.cuba.cargols_logo_cuba / 20 * 100;
    /* La longitud del cordill de la cuba dependrà de si és per femelles o per cargols */
//    if (controlCordill == 0) // Cordill Femelles
//    {
//        bancada.cuba.cordill_cuba;
//    }
//    else if (controlCordill == 1) //Cordill_cargols
//    {
//        bancada.cuba.cordill_cuba;
//    }
    /* Dependrà de si li diem diametre gran o petit */
    /*   Passar parametre de control */
//    if (ControlCuba == 0) // Cuba petita
//    {
//        bancada.cuba.cuba_petita;
//    }
//    else if (ControlCuba == 1) // Cuba gran
//    {
//        bancada.cuba.cuba_gran;
//    }
    float valueLogoPetit = (float)bancada.cuba.logo_petit / 20 * 100;

    float valueCintaEspuma = (float)bancada.porta.cinta_espuma / 20 * 100;
    float valueFrontisses = (float)bancada.porta.frontisses / 20 * 100;
    float valueLogoGran = (float)bancada.porta.logo_gran / 20 * 100;
    float valuePestellAntic = (float)bancada.porta.pestell_porta.pestell_antic / 20 * 100;
    float valuePestellNou = (float)bancada.porta.pestell_porta.pestell_nou / 20 * 100;
    float valuePorta = (float)bancada.porta._porta / 20 * 100;

    float valueFemelles = (float)bancada.potes.femelles_frm10 / 20 * 100;
    float valuePotes = (float)bancada.potes.potes / 20 * 100;
    //qDebug() << "vv  " << bancada.potes.potes << "  " << valuePotes;

    float valueSubjector = (float)bancada.subjector_quadre_electric / 20 * 100;
    float valueVibrador = (float)bancada.vibrador / 20 * 100;
    float valueCargols816 = (float)bancada.cargols_816_vibrador / 20 * 100;
    float valueCargols820 = (float)bancada.cargols_820_vibrador / 20 * 100;
    float valueVolanderes = (float)bancada.volanderes_rm8 / 20 * 100;

    ui->label_NumeroBancades->setText(QString::number(bancada.bancada));
    ui->label_NumeroPotesBancada->setText(QString::number(bancada.potes.potes));
    ui->label_NumeroCargols810->setText(QString::number(bancada.cargols_810));
    ui->label_NumeroFemellesRM10->setText(QString::number(bancada.potes.femelles_frm10));
    ui->label_NumeroPortes->setText(QString::number(bancada.porta._porta));
    ui->label_NumeroPestellAntic->setText(QString::number(bancada.porta.pestell_porta.pestell_antic));
    ui->label_NumeroPestellNou->setText(QString::number(bancada.porta.pestell_porta.pestell_nou));
    ui->label_NumeroVibradors->setText(QString::number(bancada.vibrador));
    ui->label_NumeroCargols816->setText(QString::number(bancada.cargols_816_vibrador));
    ui->label_NumeroCargols820->setText(QString::number(bancada.cargols_820_vibrador));
    ui->label_NumeroVRM10->setText(QString::number(bancada.volanderes_rm8));
    ui->label_NumeroSubjectorQuadreElectric->setText(QString::number(bancada.subjector_quadre_electric));
    ui->label_NumeroCuba->setText(QString::number(bancada.cuba.cuba_gran));
    ui->label_NumeroCordillCuba->setText(QString::number(bancada.cuba.cordill_cuba));
    ui->label_NumeroLogoCuba->setText(QString::number(bancada.cuba.logo_petit));
    ui->label_NumeroCargolsLogo->setText(QString::number(bancada.cuba.cargols_logo_cuba));

    ui->progressBar_VolanderesRM10->setValue( valueVolanderes );
    ui->progressBar_Vibrador->setValue( valueVibrador );
    ui->progressBar_SubjectorQuadre->setValue( valueSubjector );
    ui->progressBar_PotesBancada->setValue( valuePotes );
    ui->progressBar_Portes->setValue( valuePorta );
    ui->progressBar_PestellsAntic->setValue( valuePestellAntic );
    ui->progressBar_PestellNou->setValue( valuePestellNou );
    ui->progressBar_LogoCuba->setValue( valueLogoPetit );
    ui->progressBar_FemellesRM10->setValue( valueFemelles );
    ui->progressBar_CargolsCuba->setValue( valueCargolsLogoCuba );
    ui->progressBar_Cargols820->setValue( valueCargols820 );
    ui->progressBar_Cargols816->setValue( valueCargols816 );
    ui->progressBar_Cargols810->setValue( valueCargols810 );
    ui->progressBar_Bancades->setValue( valueBancades );

}
