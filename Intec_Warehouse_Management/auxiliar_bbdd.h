#ifndef AUXILIAR_BBDD_H
#define AUXILIAR_BBDD_H

#include <QVariant>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

#include <QMessageBox>
#include <QStringList>

#include <QDebug>

void missatges_qmessagebox(QString titol, QString missatge, QString aux);

QSqlDatabase base_BBDD();

QStringList cargols_BBDD();
QStringList components_BBDD();
QStringList cos_BBDD();
QStringList electricitat_BBDD();
QStringList paisos_BBDD();

typedef struct tensor_1
{
    short cos_tensor;                   	//intec.components      (components.cos_tensor
    short tensor;                           //intec.components      (components.tensor
    short cargol_tensor;                    //intec.cargols         (cargols.c640_hexa
    short femella_tensor;                   //intec.cargols         (cargols.frm6
    short cargols_lateral;                  //intec.cargols         (cargols.c515_allen
}Tensor;

typedef struct motor_cinta_1
{
    short motor_cinta;                      //intec.electricitat	(electricitat.motor_cinta)
    short cargols_c512_motor;               //intec.cargols         (cargols.c512_allen
    short dentada_gran;                     //intec.components      (components.dentada_gran
    short dentada_petita;                   //intec.components      (components.dentada_petita
    short pasador_elastic_d5;               //intec.components      (components.pasador_elastic_d5
    short pasador_elastic_d3;               //intec.components      (components.pasador_elastic_d3
    short brida_motor;                      //intec.components      (components.brida_motor
    short funda_motor;                      //intec.components      (components.funda_motor
    short cinta_americana;                  //intec.components      (components.cinta_americana
}MotorCinta;

typedef struct detector_nivell_1
{
    short cos_detector;                     //intec.components      (components.cos_detector
    short piu_detector_nivell;              //intec.components      (components.piu_detector_nivell
    short volanderes_vrm4;                  //intec.cargols         (cargols.vrm4
    short barra;                            //intec.components      (components.barra_detector
    short presoner_rm3;                     //intec.components      (cargols.p32
    short tapa;                             //intec.components      (components.tapa_detector
    short suport;                           //intec.components      (components.suport_detector
    short cargols_subjeccio_tapa;           //intec.cargols         (cargols.c425_inox
    short cargols_c48;                      //intec.cargols         (cargols.c48_allen
}DetectorNivell;

typedef struct cinta_1
{
    short lateral_esquerra;         		//intec.components      (components.lateral_esquerra
    short lateral_Motor;                    //intec.components      (components.lateral_motor
    short cilindre_frontal;     			//intec.components      (components.cilindre_frontal
    short cilindre_Motor;               	//intec.components      (components.cilindre_motor
    short autolubricats;                    //intec.components      (components.autolubricats
    short cinta;                            //intec.components      (components.cinta
    short cargols_laterals_avellanado;		//intec.cargols         (cargols.c610_ave
    short funda_metallica_motor;            //intec.components      (components.funda_metallica_motor
    short pg9;                              //intec.components      (components.pg9
    short cargols_c48_funda_metallica;      //intec.cargols         (cargols.c48_allen
    Tensor tensor;
    MotorCinta motor;
    DetectorNivell detector_nivell;
}Cinta;

typedef struct pinta_1
{
    short pinta;                            //intec.components      (components.pinta
    short glaseadora;                       //intec.components      (components.glaseadora
    short cargols_c512_gotasebo;            //intec.cargols         (cargols.c512_gota
}Pinta;

typedef struct tolva_1
{
    short tolva;                            //intec.cos             (cos.tolves
    short cargols_c525_allen;               //intec.cargols         (cargols.c525_allen
    short cargols_c812_allen;               //intec.cargols         (cargols.c812_allen
    Pinta pinta;
    Cinta cinta;
}Tolva;

typedef struct campana_1
{
    short campana;                          //intec.cos             (cos.campanes
    short logo_gran;                        //intec.components      (components.logo_gran
    short reblons_30;                       //intec.cargols         (cargols.reblons30
    short guies_laterals;                   //intec.components      (components.cam_guies
    short tapa_frontal;                     //intec.components      (components.tapa_frontal
    short tapa_superior;                    //intec.components      (components.tapa_superior
    short cargols_frontals;                 //intec.cargols
    short cordo_negre;                      //intec.components      (components.cordo_negre
    short travesser;                        //intec.cos             (cos.travesser
    short cargols_c616;                     //intec.cargols         (cargols.c616_gota
    short femelles_frm6;                    //intec.cargols         (cargols.frm6
    short cargols_c514;                     //intec.cargols         (cargols.c514_ave
    short volanderes_rm5;                   //intec.cargols         (cargols.vrm5_estriades
    short femelles_frm5;                    //intec.cargols         (cargols.frm5
    short nances;                           //intec.components      (components.nances
    /* Els cargols de les nances estan inclosos a
     * cargols_c514
     */
    short cinta_espuma;                     //intec.components      (components.cinta_espuma
    short tope_tapa_frontal;                //intec.components      (components.tope_tapa_frontal
    short cargols_c516;                     //intec.cargols         (cargols.c516_gota
    /* Les femelles i les volanderes de la
     * peça tope tapa frontal estàn comptades a
     * volanderes_rm5
     * femelles_frm5
     */
}Campana;

typedef struct pestell_porta_1
{
    short pestell_antic;                    //intec.components      (components.pestell_antic
    short pestell_nou;                      //intec.components      (components.pestell_nou
}Pestell;

typedef struct portes_1
{
    short _porta;                           //intec.cos             (cos.portes
    /*
     * Aquest logo és el mateix que el de la campana
     */
    short logo_gran;                        //intec.components      (components.logo_gran
    short cinta_espuma;                     //intec.components      (components.cinta_espuma
    short frontisses;                       //intec.components      (components.frontisses
    Pestell pestell_porta;
}Porta;

typedef struct cuba_1
{
    short cuba_petita;                      //intec.components      (components.cuba_petita
    /* No està massa clar la cuba gran */
    short cuba_gran;                        //intec.components      (components.cuba_gran
    short cordill_cuba;                     //intec.components      (components.cordill_cuba
    /*
     * Aquest logo és més petit
     */
    short logo_petit;                       //intec.components      (components.logo_petit
    short cargols_logo_cuba;                //intec.cargols         (cargols.car_logo_cuba
}Cuba;

typedef struct potes_bancada
{
    short potes;                            //intec.cos             (cos.topepotes
    short femelles_frm10;                   //intec.cargols         (cargols.frm10
}Potes;

typedef struct bancada_1
{
    short bancada;                          //intec.cos             (cos.bancades
    // el vibrador serà de 50/60 Hz,
    //es carregarà quan veiem a
    //quin país va
    short vibrador;                         //intec.electricitat    (electricitat.motor_vibrador
    short subjector_quadre_electric;        //inte.components       (components.subjector_quadre_electric
    short cargols_810;                      //intec.cargols         (cargols.c810_allen
    //Els 3 cargols cargols_c812 que apreten la tolva, estàn comptats quan es crea la tolva.
    //short cargols_812_tolva;                //intec.cargols         (cargols.c812_allen
    short cargols_816_vibrador;             //intec.cargols         (cargols.c816_allen
    short cargols_820_vibrador;             //intec.cargols         (cargols.c820_allen
    short volanderes_rm8;                   //intec.cargols         (cargols.vrm8
    Cuba cuba;
    Porta porta;
    Potes potes;
}Bancada;

typedef struct maquina_1
{
    Tolva conjunt_Tolva;
    Bancada conjunt_Bancada;
    Campana conjunt_Campana;
}Maquina;

Campana funcio_NovaCampana();
Cinta funcio_NovaCinta();
Tolva funcio_NovaTolva();
Bancada funcio_NovaBancada();

#endif // AUXILIAR_BBDD_H
