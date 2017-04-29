#include "dialognovamaquina.h"
#include "ui_dialognovamaquina.h"

#include <QMessageBox>
#include <QDebug>

#include "auxiliar_bbdd.h"

int valor313 = 35;
int valor413 = 35;
int valor463 = 35;
int valor563 = 35;

int NombreColumnes_taulaOF = 6;

DialogNovaMaquina::DialogNovaMaquina(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogNovaMaquina)
{
    ui->setupUi(this);

    QStringList llista_Paisos;
    llista_Paisos = paisos_BBDD();

    ui->listWidget_Paisos->addItems(llista_Paisos);  //La llista_Paisos es creada al "dialognovamaquina.h" al private en el QStringList
    ui->listWidget_Cargols->addItems(llista_Cargols);  //La llista_Cargols es creada al "dialognovamaquina.h" al private en el QStringList
    ui->listWidget_llancadora->addItems(llista_Llancadora);  //La llista_Llancadora es creada al "dialognovamaquina.h" al private en el QStringList
}

DialogNovaMaquina::~DialogNovaMaquina()
{
    delete ui;
}

void DialogNovaMaquina::on_listWidget_Paisos_itemActivated()
{
    if (QString(ui->listWidget_Paisos->currentItem()->text()) == "Argentina" || QString(ui->listWidget_Paisos->currentItem()->text()) == "Mèxic" || QString(ui->listWidget_Paisos->currentItem()->text()) == "Ecuador")
    {
        ui->radioButton_50->setEnabled(false); // Fem que el Radio Button de 50 Hz no estigui actiu
        ui->radioButton_60->setEnabled(true);  // Fem que el Radio Button de 60 Hz estigui actiu
        ui->radioButton_60->setChecked(true);  // Posem el Radio Button de 60 Hz clicat
    }
    else
    {
        ui->radioButton_60->setEnabled(false); // Fem que el Radio Button de 60 Hz no estigui actiu
        ui->radioButton_50->setEnabled(true);  // Fem que el Radio Button de 50 Hz estigui actiu
        ui->radioButton_50->setChecked(true);  // Posem el Radio Button de 50 Hz clicat
    }
}

void DialogNovaMaquina::on_pushButton_clicked()
{
    short controlPais = 0;
    short controlCargols = 0;
    short controlLlanca = 0;

    if (ui->listWidget_Paisos->selectedItems().count() == 0)  // Funcio que alerta si no hem seleccionat a quin pais anirà la màquina
    {
        QMessageBox::warning(this, "Alerta pais", "Has de seleccionar país!");
        controlPais = 0;
    }
    else controlPais = 1;
    if (ui->listWidget_Cargols->selectedItems().count() == 0)
    {
        QMessageBox::warning(this, "Alerta", "Has de seleccionar Cargols o Femelles");
        controlCargols = 0;
    }
    else controlCargols = 1;
    if (ui->listWidget_llancadora->selectedItems().count() == 0)
    {
        QMessageBox::warning(this, "Alerta tipus", "Has de seleccionar el tipus de llançadora");
        controlLlanca = 0;
    }
    else controlLlanca = 1;

    if (controlCargols == 1 && controlLlanca == 1 && controlPais == 1)
    {
        ui->taulaOF->setColumnCount(NombreColumnes_taulaOF);
        ui->taulaOF->setHorizontalHeaderLabels(identificador_Columna_TableWidgets);

        QTableWidgetItem* llista_llancadora_WI = new QTableWidgetItem(ui->listWidget_llancadora->currentItem()->text());
        llista_llancadora_WI->setTextAlignment(Qt::AlignCenter);

        QTableWidgetItem* llista_Paisos_WI = new QTableWidgetItem(ui->listWidget_Paisos->currentItem()->text());
        llista_Paisos_WI->setTextAlignment(Qt::AlignCenter);

        QTableWidgetItem* llista_Cargols_WI = new QTableWidgetItem(ui->listWidget_Cargols->currentItem()->text());
        llista_Cargols_WI->setTextAlignment(Qt::AlignCenter);

        ui->taulaOF->insertRow(ui->taulaOF->rowCount());
        ui->taulaOF->setItem(ui->taulaOF->rowCount() - 1, 0, llista_Paisos_WI);
        ui->taulaOF->setItem(ui->taulaOF->rowCount() - 1, 1, llista_Cargols_WI);

        if (ui->listWidget_llancadora->currentItem()->text() == "313 mm")
        {
            int temporal = comptadorLlancadora(valor313);
            valor313 = temporal;

            if (valor313 <= 30)
            {
                ui->taulaOF->setItem(ui->taulaOF->rowCount() - 1, 2, llista_llancadora_WI);
                avis_Barres(0);
            }
            else
            {
                ui->taulaOF->setItem(ui->taulaOF->rowCount() - 1, 2, llista_llancadora_WI);
            }
        }
        else if (ui->listWidget_llancadora->currentItem()->text() == "413 mm")
        {
            int temporal = comptadorLlancadora(valor413);
            valor413 = temporal;

            if (valor413 <= 30)
            {
                ui->taulaOF->setItem(ui->taulaOF->rowCount() - 1, 2, llista_llancadora_WI);
                avis_Barres(1);
            }
            else
            {
                ui->taulaOF->setItem(ui->taulaOF->rowCount() - 1, 2, llista_llancadora_WI);
            }
        }
        else if (ui->listWidget_llancadora->currentItem()->text() == "463 mm")
        {
            int temporal = comptadorLlancadora(valor463);
            valor463 = temporal;

            if (valor463 <= 30)
            {
                ui->taulaOF->setItem(ui->taulaOF->rowCount() - 1, 2, llista_llancadora_WI);
                avis_Barres(2);
            }
            else
            {
                ui->taulaOF->setItem(ui->taulaOF->rowCount() - 1, 2, llista_llancadora_WI);
            }
        }
        else if (ui->listWidget_llancadora->currentItem()->text() == "563 mm")
        {
            int temporal = comptadorLlancadora(valor563);
            valor563 = temporal;

            if (valor563 <= 30)
            {
                ui->taulaOF->setItem(ui->taulaOF->rowCount() - 1, 2, llista_llancadora_WI);
                avis_Barres(3);
            }
            else
            {
                ui->taulaOF->setItem(ui->taulaOF->rowCount() - 1, 2, llista_llancadora_WI);
            }
        }
        else
        {
            ui->taulaOF->setItem(ui->taulaOF->rowCount() - 1, 2, llista_llancadora_WI);
        }
        crearCampana(1); //creem campana amb logo
        crearTolva();
        crearBancada(1,1);
    }
}

int DialogNovaMaquina::comptadorLlancadora(int numero)
{
    int rr = numero - 1;
    return rr;
}

void DialogNovaMaquina::avis_Barres(int numero)
{
    if (numero == 0) // 313 mm
    {
        ui->taulaOF->item(ui->taulaOF->rowCount() -1 , 2)->setBackgroundColor(Qt::red);
    }
    else if (numero == 1) // 413 mm
    {
        ui->taulaOF->item(ui->taulaOF->rowCount() -1 , 2)->setBackgroundColor(Qt::yellow);
    }
    else if (numero == 2) // 463 mm
    {
        ui->taulaOF->item(ui->taulaOF->rowCount() -1 , 2)->setBackgroundColor(Qt::cyan);
    }
    else if (numero == 3) // 563 mm
    {
        ui->taulaOF->item(ui->taulaOF->rowCount() -1 , 2)->setBackgroundColor(Qt::green);
    }
    ui->taulaOF->item(ui->taulaOF->rowCount() -1 , 2)->setToolTip("Queden menys de 30 barres");
}

void DialogNovaMaquina::columna_Bancada(int controlBancada)
{
    QTableWidgetItem* bancada_Widget = new QTableWidgetItem("Bancada");
    bancada_Widget->setTextAlignment(Qt::AlignCenter);

    ui->taulaOF->setItem(ui->taulaOF->rowCount() - 1, 3, bancada_Widget);
    if (controlBancada == 1)
        ui->taulaOF->item(ui->taulaOF->rowCount() - 1, 3)->setBackgroundColor(Qt::green);
    else if (controlBancada == 0)
        ui->taulaOF->item(ui->taulaOF->rowCount() - 1, 3)->setBackgroundColor(Qt::red);
}

void DialogNovaMaquina::columna_Tolva(int controlTolva)
{
    QTableWidgetItem* tolva_Widget = new QTableWidgetItem("Tolva");
    tolva_Widget->setTextAlignment(Qt::AlignCenter);

    ui->taulaOF->setItem(ui->taulaOF->rowCount() - 1, 4, tolva_Widget);
    if (controlTolva == 1)
        ui->taulaOF->item(ui->taulaOF->rowCount() - 1, 4)->setBackgroundColor(Qt::green);
    else if (controlTolva == 0)
        ui->taulaOF->item(ui->taulaOF->rowCount() - 1, 4)->setBackgroundColor(Qt::red);
}

void DialogNovaMaquina::columna_Campana(int controlCampana)
{
    QTableWidgetItem* campana_Widget = new QTableWidgetItem("Campana");
    campana_Widget->setTextAlignment(Qt::AlignCenter);

    ui->taulaOF->setItem(ui->taulaOF->rowCount() - 1, 5, campana_Widget);
    if (controlCampana == 1)
        ui->taulaOF->item(ui->taulaOF->rowCount() - 1, 5)->setBackgroundColor(Qt::green);
    else if (controlCampana == 0)
        ui->taulaOF->item(ui->taulaOF->rowCount() - 1, 5)->setBackgroundColor(Qt::red);
}

void DialogNovaMaquina::crearCampana(int controlLogo)
{
    Campana campana;
    campana = funcio_NovaCampana();

    int control_Fabricacio = 0;

    campana.campana >= 1 ? control_Fabricacio += 1 : control_Fabricacio += 0;
    campana.cargols_c514 >= 8 ? control_Fabricacio += 1 : control_Fabricacio += 0;
    campana.cargols_c516 >= 4 ? control_Fabricacio += 1 : control_Fabricacio += 0;
    campana.cargols_c616 >= 2 ? control_Fabricacio += 1 : control_Fabricacio += 0;
    campana.cargols_frontals >= 8 ? control_Fabricacio += 1 : control_Fabricacio += 0;
    campana.cinta_espuma >= 45 ? control_Fabricacio += 1 : control_Fabricacio += 0;
    campana.cordo_negre >= 40 ? control_Fabricacio += 1 : control_Fabricacio += 0;
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
            columna_Campana(1);
        }
        else
        {
            columna_Campana(0);
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
            columna_Campana(1);
        }
        else
        {
            columna_Campana(0);
        }
    }
}

void DialogNovaMaquina::crearTolva()
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
        columna_Tolva(1);
    }
    else if (controlFabricacio != 34)
    {
        columna_Tolva(0);
    }
}

void DialogNovaMaquina::crearBancada(int ControlCuba, int controlCordill)
{
    Bancada bancada;
    bancada = funcio_NovaBancada();
    int controlFabricacio = 0;

    bancada.bancada >= 1 ? controlFabricacio += 1 : controlFabricacio += 0;
    /* Aquests cargols són per apretar la campana a la bancada */
    bancada.cargols_810 >= 4 ? controlFabricacio += 1 : controlFabricacio += 0;
    bancada.cuba.cargols_logo_cuba >= 4 ? controlFabricacio += 1 : controlFabricacio += 0;
    /* La longitud del cordill de la cuba dependrà de si és per femelles o per cargols */
    if (controlCordill == 0) // Cordill Femelles
    {
        bancada.cuba.cordill_cuba >= 90 ? controlFabricacio += 1 : controlFabricacio += 0;
    }
    else if (controlCordill == 1) //Cordill_cargols
    {
        bancada.cuba.cordill_cuba >= 30 ? controlFabricacio += 1 : controlFabricacio += 0;
    }
    /* Dependrà de si li diem diametre gran o petit */
    /*   Passar parametre de control */
    if (ControlCuba == 0) // Cuba petita
    {
        bancada.cuba.cuba_petita >= 1 ? controlFabricacio += 1 : controlFabricacio += 0;
    }
    else if (ControlCuba == 1) // Cuba gran
    {
        bancada.cuba.cuba_gran >= 1 ? controlFabricacio += 1 : controlFabricacio += 0;
    }
    bancada.cuba.logo_petit >= 1 ? controlFabricacio += 1 : controlFabricacio += 0;

    bancada.porta.cinta_espuma >= 120 ? controlFabricacio += 1 : controlFabricacio += 0;
    bancada.porta.frontisses >= 2 ? controlFabricacio += 1 : controlFabricacio += 0;
    bancada.porta.logo_gran >= 1 ? controlFabricacio += 1 : controlFabricacio += 0;
    bancada.porta.pestell_porta.pestell_antic >= 1 ? controlFabricacio += 1 : controlFabricacio += 0;
    bancada.porta.pestell_porta.pestell_nou >= 1 ? controlFabricacio += 1 : controlFabricacio += 0;
    bancada.porta._porta >= 1 ? controlFabricacio += 1 : controlFabricacio += 0;

    bancada.potes.femelles_frm10 >= 4 ? controlFabricacio += 1 : controlFabricacio += 0;
    bancada.potes.potes >= 4 ? controlFabricacio += 1 : controlFabricacio += 0;

    bancada.subjector_quadre_electric >= 4 ? controlFabricacio += 1 : controlFabricacio += 0;
    bancada.vibrador >= 1 ? controlFabricacio += 1 : controlFabricacio += 0;
    bancada.cargols_816_vibrador >= 2 ? controlFabricacio += 1 : controlFabricacio += 0;
    bancada.cargols_820_vibrador >= 2 ? controlFabricacio += 1 : controlFabricacio += 0;
    bancada.volanderes_rm8 >= 4 ? controlFabricacio += 1 : controlFabricacio += 0;
    //bancada.cargols_812_tolva >= 3 ? controlFabricacio += 1 : controlFabricacio += 0;

    if (controlFabricacio == 19)
    {
        columna_Bancada(1);
    }
    else if (controlFabricacio != 19)
    {
        columna_Bancada(0);
    }
}
