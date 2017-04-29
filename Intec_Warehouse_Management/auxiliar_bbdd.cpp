#include "auxiliar_bbdd.h"

void missatges_qmessagebox(QString titol, QString missatge, QString aux)
{
    QMessageBox error_Obrint;
    error_Obrint.setWindowTitle(titol);
    error_Obrint.setIcon(QMessageBox::Warning);
    error_Obrint.setText(missatge +  aux);
    error_Obrint.setStandardButtons(QMessageBox::Ok);
    error_Obrint.exec();
}

QSqlDatabase base_BBDD()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("127.0.0.1");
    db.setPort(5432);
    db.setDatabaseName("db");
    db.setUserName("psql");

    if (!db.open())
    {
        missatges_qmessagebox("Alerta FALLO!", db.lastError().text(), "");
        exit(1);
    }
    else
    {
        return db;
    }
    db.close();
}

QStringList cos_BBDD()
{
    QStringList retorn_Cos;
    QSqlDatabase db = base_BBDD();

    QSqlQuery* queryID = new QSqlQuery(db);
    queryID->setForwardOnly(true);

    if(!queryID->prepare("SELECT COUNT(id) FROM intec.cos WHERE id=\'1\'"))
    {
        missatges_qmessagebox("Alerta FALLO!", "Fallo:  ", db.lastError().text());
    }
    else
    {
        bool queryRes = queryID->exec();
        if (!queryRes)
        {
            missatges_qmessagebox("Alerta!", "No processat", "");
        }
        else
        {
            if(queryID->next())
            {
                if (queryID->value(0).toString().toInt() > 0)
                {
                    QSqlQuery* queryGeneral = new QSqlQuery(db);
                    queryGeneral->setForwardOnly(true);

                    queryGeneral->exec("SELECT bancades,tolves,campanes,portes,topepotes,travesser FROM intec.cos WHERE id=\'1\'");
                    while(queryGeneral->next())
                    {
                        retorn_Cos.append(queryGeneral->value(0).toString()); //bancades
                        retorn_Cos.append(queryGeneral->value(1).toString()); //tolves
                        retorn_Cos.append(queryGeneral->value(2).toString()); //campanes
                        retorn_Cos.append(queryGeneral->value(3).toString()); //portes
                        retorn_Cos.append(queryGeneral->value(4).toString()); //topeportes
                        retorn_Cos.append(queryGeneral->value(5).toString()); //travesser
                    }
                }
                else
                {
                    missatges_qmessagebox("Alerta!", "Carrega alguna cosa a la BBDD!","");
                }
            }
        }
    }
    db.close();

    return retorn_Cos;
}

QStringList electricitat_BBDD()
{
    QStringList retorn_Elec;
    QSqlDatabase db = base_BBDD();

    QSqlQuery* queryID = new QSqlQuery(db);
    queryID->setForwardOnly(true);

    if(!queryID->prepare("SELECT COUNT(id) FROM intec.electricitat WHERE id=\'1\'"))
    {
        missatges_qmessagebox("Alerta FALLO!", "Fallo:  ", db.lastError().text());
    }
    else
    {
        bool queryRes = queryID->exec();
        if (!queryRes)
        {
            missatges_qmessagebox("Alerta!", "No processat", "");
        }
        else
        {
            if(queryID->next())
            {
                if (queryID->value(0).toString().toInt() > 0)
                {
                    QSqlQuery* queryGeneral = new QSqlQuery(db);
                    queryGeneral->setForwardOnly(true);

                    queryGeneral->exec("SELECT guia_30,guia_40,guia_met,transformadors,planxes,motor_cinta,motor_vibrador FROM intec.electricitat WHERE id=\'1\'");
                    while(queryGeneral->next())
                    {
                        retorn_Elec.append(queryGeneral->value(0).toString()); //guia_30
                        retorn_Elec.append(queryGeneral->value(1).toString()); //guia_40
                        retorn_Elec.append(queryGeneral->value(2).toString()); //guia_met
                        retorn_Elec.append(queryGeneral->value(3).toString()); //transformadors
                        retorn_Elec.append(queryGeneral->value(4).toString()); //planxes
                        retorn_Elec.append(queryGeneral->value(5).toString()); //motor_cinta
                        retorn_Elec.append(queryGeneral->value(6).toString()); //motor_vibrador
                    }
                }
            }
        }
    }
    db.close();

    return retorn_Elec;
}

QStringList paisos_BBDD()
{
    QStringList retorn_Paisos;
    QSqlDatabase db = base_BBDD();

    QSqlQuery* queryID = new QSqlQuery(db);
    queryID->setForwardOnly(true);
    if(!queryID->prepare(QString("SELECT nom FROM intec.paisos ORDER BY id ASC")) )
    {
        missatges_qmessagebox("Alerta FALLO!", db.lastError().text(), "");
    }
    else
    {
        bool queryRes = queryID->exec();
        if (queryID->lastError().type() != QSqlError::NoError || !queryRes)
        {
            qDebug() << queryID->lastError().text();
        }

        while (queryID->next())
        {
            retorn_Paisos.append(queryID->value(0).toString());
        }
    }
    db.close();

    return retorn_Paisos;
}

QStringList cargols_BBDD()
{
    QStringList retorn_cargols;
    QSqlDatabase db = base_BBDD();

    QSqlQuery* queryID = new QSqlQuery(db);
    queryID->setForwardOnly(true);

    if(!queryID->prepare("SELECT COUNT(id) FROM intec.cargols WHERE id=1"))
    {
        missatges_qmessagebox("Alerta FALLO!", "Fallo:  ", db.lastError().text());
    }
    else
    {
        bool queryRes = queryID->exec();
        if (!queryRes)
        {
            missatges_qmessagebox("Alerta!", "No processat", "");
        }
        else
        {
            if(queryID->next())
            {
                if (queryID->value(0).toString().toInt() > 0)
                {
                    QSqlQuery* queryGeneral = new QSqlQuery(db);
                    queryGeneral->setForwardOnly(true);

                    queryGeneral->exec("SELECT reblons30, reblons40, c414_allen, c512_allen, c512_gota, c514_ave, c515_allen, c516_gota, c525_allen, c610_ave, c616_gota, c640_hexa, c810_allen, c812_allen, p525, frm4, frm5, frm6, frm10, vrm4, vrm5_estriades, c48_allen, car_logo_cuba, p32, c425_inox, c816_allen, c820_allen, vrm8 FROM intec.cargols WHERE id=1");
                    while(queryGeneral->next())
                    {
                        retorn_cargols.append(queryGeneral->value(0).toString()); //reblons30
                        retorn_cargols.append(queryGeneral->value(1).toString()); //reblons40
                        retorn_cargols.append(queryGeneral->value(2).toString()); //c414_allen
                        retorn_cargols.append(queryGeneral->value(3).toString()); //c512_allen
                        retorn_cargols.append(queryGeneral->value(4).toString()); //c512_gota
                        retorn_cargols.append(queryGeneral->value(5).toString()); //c514_ave
                        retorn_cargols.append(queryGeneral->value(6).toString()); //c515_allen
                        retorn_cargols.append(queryGeneral->value(7).toString()); //c516_gota
                        retorn_cargols.append(queryGeneral->value(8).toString()); //c525_allen
                        retorn_cargols.append(queryGeneral->value(9).toString()); //c610_ave
                        retorn_cargols.append(queryGeneral->value(10).toString()); //c616_gota
                        retorn_cargols.append(queryGeneral->value(11).toString()); //c640_hexa
                        retorn_cargols.append(queryGeneral->value(12).toString()); //c810_allen
                        retorn_cargols.append(queryGeneral->value(13).toString()); //c812_allen
                        retorn_cargols.append(queryGeneral->value(14).toString()); //p525
                        retorn_cargols.append(queryGeneral->value(15).toString()); //frm4
                        retorn_cargols.append(queryGeneral->value(16).toString()); //frm5
                        retorn_cargols.append(queryGeneral->value(17).toString()); //frm6
                        retorn_cargols.append(queryGeneral->value(18).toString()); //frm10
                        retorn_cargols.append(queryGeneral->value(19).toString()); //vrm4
                        retorn_cargols.append(queryGeneral->value(20).toString()); //vrm5_estriades
                        retorn_cargols.append(queryGeneral->value(21).toString()); //c48_allen
                        retorn_cargols.append(queryGeneral->value(22).toString()); //car_logo_cuba
                        retorn_cargols.append(queryGeneral->value(23).toString()); //p32
                        retorn_cargols.append(queryGeneral->value(24).toString()); //c425_inox
                        retorn_cargols.append(queryGeneral->value(25).toString()); //c816_allen
                        retorn_cargols.append(queryGeneral->value(26).toString()); //c820_allen
                        retorn_cargols.append(queryGeneral->value(27).toString()); //vrm8
                    }
                    /*
                     *  0 - reblons30
                     *  1 - reblons40
                     *  2 - c414_allen
                     *  3 - c512_allen
                     *  4 - c512_gota
                     *  5 - c514_ave
                     *  6 - c515_allen
                     *  7 - c516_gota
                     *  8 - c525_allen
                     *  9 - c610_ave
                     * 10 - c616_gota
                     * 11 - c640_hexa
                     * 12 - c810_allen
                     * 13 - c812_allen
                     * 14 - p525
                     * 15 - frm4
                     * 16 - frm5
                     * 17 - frm6
                     * 18 - frm10
                     * 19 - vrm4
                     * 20 - vrm5_estriades
                     * 21 - c48_allen
                     * 22 - car_logo_cuba
                     * 23 - p32
                     * 24 - c425_inox
                     * 25 - c816_allen
                     * 26 - c820_allen
                     * 27 - vrm8
                     */
                }
            }
        }
    }
    db.close();

    return retorn_cargols;
}

QStringList components_BBDD()
{
    QStringList retorn_components;
    QSqlDatabase db = base_BBDD();

    QSqlQuery* queryID = new QSqlQuery(db);
    queryID->setForwardOnly(true);

    if(!queryID->prepare("SELECT COUNT(id) FROM intec.cargols WHERE id=1"))
    {
        missatges_qmessagebox("Alerta FALLO!", "Fallo:  ", db.lastError().text());
    }
    else
    {
        bool queryRes = queryID->exec();
        if (!queryRes)
        {
            missatges_qmessagebox("Alerta!", "No processat", "");
        }
        else
        {
            if(queryID->next())
            {
                if (queryID->value(0).toString().toInt() > 0)
                {
                    QSqlQuery* queryGeneral = new QSqlQuery(db);
                    queryGeneral->setForwardOnly(true);

                    queryGeneral->exec("SELECT cam_guies, cos_tensor, tensor, dentada_gran, dentada_petita, pasador_elastic_d5, pasador_elastic_d3, funda_motor, cinta_americana, lateral_esquerra, lateral_motor, cilindre_frontal, cilindre_motor, autolubricats, cinta, funda_metallica_motor, pg9, pinta, glaseadora, logo_gran, logo_petit, tapa_frontal, tapa_superior, cordo_negre, nances, cinta_espuma, tope_tapa_frontal, pestell_antic, pestell_nou, frontisses, cuba_gran, cuba_petita, cordill_cuba, subjector_quadre_electric, brida_motor, cos_detector, piu_detector_nivell, barra_detector, tapa_detector, suport_detector FROM intec.components WHERE id=1");
                    while(queryGeneral->next())
                    {
                        retorn_components.append(queryGeneral->value(0).toString()); //cam_guies
                        retorn_components.append(queryGeneral->value(1).toString()); //cos_tensor
                        retorn_components.append(queryGeneral->value(2).toString()); //tensor
                        retorn_components.append(queryGeneral->value(3).toString()); //dentada_gran
                        retorn_components.append(queryGeneral->value(4).toString()); //dentada_petita
                        retorn_components.append(queryGeneral->value(5).toString()); //pasador_elastic_d5
                        retorn_components.append(queryGeneral->value(6).toString()); //pasador_elastic_d3
                        retorn_components.append(queryGeneral->value(7).toString()); //funda_motor
                        retorn_components.append(queryGeneral->value(8).toString()); //cinta_americana
                        retorn_components.append(queryGeneral->value(9).toString()); //lateral_esquerra
                        retorn_components.append(queryGeneral->value(10).toString()); //lateral_motor
                        retorn_components.append(queryGeneral->value(11).toString()); //cilindre_frontal
                        retorn_components.append(queryGeneral->value(12).toString()); //cilindre_motor
                        retorn_components.append(queryGeneral->value(13).toString()); //autolubricats
                        retorn_components.append(queryGeneral->value(14).toString()); //cinta
                        retorn_components.append(queryGeneral->value(15).toString()); //funda_metallica_motor
                        retorn_components.append(queryGeneral->value(16).toString()); //pg9
                        retorn_components.append(queryGeneral->value(17).toString()); //pinta
                        retorn_components.append(queryGeneral->value(18).toString()); //glaseadora
                        retorn_components.append(queryGeneral->value(19).toString()); //logo_gran
                        retorn_components.append(queryGeneral->value(20).toString()); //logo_petit
                        retorn_components.append(queryGeneral->value(21).toString()); //tapa_frontal
                        retorn_components.append(queryGeneral->value(22).toString()); //tapa_superior
                        retorn_components.append(queryGeneral->value(23).toString()); //cordo_negre
                        retorn_components.append(queryGeneral->value(24).toString()); //nances
                        retorn_components.append(queryGeneral->value(25).toString()); //cinta_espuma
                        retorn_components.append(queryGeneral->value(26).toString()); //tope_tapa_frontal
                        retorn_components.append(queryGeneral->value(27).toString()); //pestell_antic
                        retorn_components.append(queryGeneral->value(28).toString()); //pestell_nou
                        retorn_components.append(queryGeneral->value(29).toString()); //frontisses
                        retorn_components.append(queryGeneral->value(30).toString()); //cuba_gran
                        retorn_components.append(queryGeneral->value(31).toString()); //cuba_petita
                        retorn_components.append(queryGeneral->value(32).toString()); //cordill_cuba
                        retorn_components.append(queryGeneral->value(33).toString()); //subjector_quadre_electric
                        retorn_components.append(queryGeneral->value(34).toString()); //brida_motor
                        retorn_components.append(queryGeneral->value(35).toString()); //cos_detector
                        retorn_components.append(queryGeneral->value(36).toString()); //piu_detector_nivell
                        retorn_components.append(queryGeneral->value(37).toString()); //barra_detector
                        retorn_components.append(queryGeneral->value(38).toString()); //tapa_detector
                        retorn_components.append(queryGeneral->value(39).toString()); //suport_detector
                    }
                    /*  0 - cam_guies
                     *  1 - cos_tensor
                     *  2 - tensor
                     *  3 - dentada_gran
                     *  4 - dentada_petita
                     *  5 - pasador_elastic_d5
                     *  6 - pasador_elastic_d3
                     *  7 - funda_motor
                     *  8 - cinta_americana
                     *  9 - lateral_esquerra
                     *  10- lateral_motor
                     *  11- cilindre_frontal
                     *  12- cilindre_motor
                     *  13- autolubricats
                     *  14- cinta
                     *  15- funda_metallica_motor
                     *  16- pg9
                     *  17- pinta
                     *  18- glaseadora
                     *  19- logo_gran
                     *  20- logo_petit
                     *  21- tapa_frontal
                     *  22- tapa_superior
                     *  23- cordo_negre
                     *  24- nances
                     *  25- cinta_espuma
                     *  26- tope_tapa_frontal
                     *  27- pestell_antic
                     *  28- pestell_nou
                     *  29- frontisses
                     *  30- cuba_gran
                     *  31- cuba_petita
                     *  32- cordill_cuba
                     *  33- subjector_quadre_electric
                     *  34- brida_motor
                     *  35- cos_detector
                     *  36- piu_detector_nivell
                     *  37- barra_detector
                     *  38- tapa_detector
                     *  39- suport_detector
                     */
                }
            }
        }
    }
    db.close();

    return retorn_components;
}

Campana funcio_NovaCampana()
{
    /* Ara per ara, només hi ha
     * material per a campanes
     */
    Campana campana;

    /*
     * Conexió BBDD?
     *
     * 1. Si és previsió -> no descomptar res de la BBDD
     * 2. Si és nova màquina DESCOMPTAR
     */
    QStringList campanes_Components_AUX;
    QStringList campanes_Cargols_AUX;
    QStringList campanes_Cos_AUX;

    campanes_Cargols_AUX = cargols_BBDD();
    campanes_Components_AUX = components_BBDD();
    campanes_Cos_AUX = cos_BBDD();

    campana.campana = campanes_Cos_AUX.at(1).toShort();
    campana.logo_gran = campanes_Components_AUX.at(18).toShort();
    campana.reblons_30 = campanes_Cargols_AUX.at(0).toShort();
    campana.guies_laterals = campanes_Components_AUX.at(0).toShort();
    campana.tapa_frontal = campanes_Components_AUX.at(20).toShort();
    campana.tapa_superior = campanes_Components_AUX.at(21).toShort();
    campana.cargols_frontals = 8;
    campana.cordo_negre = campanes_Components_AUX.at(23).toShort();
    campana.travesser = campanes_Cos_AUX.at(5).toShort();
    campana.cargols_c616 = campanes_Cargols_AUX.at(10).toShort();
    campana.femelles_frm6 = campanes_Cargols_AUX.at(17).toShort();
    campana.cargols_c514 = campanes_Cargols_AUX.at(5).toShort();
    campana.volanderes_rm5 = campanes_Cargols_AUX.at(20).toShort();
    campana.femelles_frm5 = campanes_Cargols_AUX.at(16).toShort();
    campana.nances = campanes_Components_AUX.at(24).toShort();
    campana.cinta_espuma = campanes_Components_AUX.at(25).toShort();
    campana.tope_tapa_frontal = campanes_Components_AUX.at(26).toShort();
    campana.cargols_c516 = campanes_Cargols_AUX.at(7).toShort();

    return campana;
}

Cinta funcio_NovaCinta()
{
    Cinta cinta;

    QStringList cinta_Cargols_BBDD;
    QStringList cinta_Components_BBDD;
    QStringList cinta_Electricitat_BBDD;

    cinta_Cargols_BBDD = cargols_BBDD();
    cinta_Components_BBDD = components_BBDD();
    cinta_Electricitat_BBDD = electricitat_BBDD();

    cinta.lateral_esquerra = cinta_Components_BBDD.at(9).toShort();
    cinta.lateral_Motor = cinta_Components_BBDD.at(10).toShort();
    cinta.cilindre_frontal = cinta_Components_BBDD.at(11).toShort();
    cinta.cilindre_Motor = cinta_Components_BBDD.at(12).toShort();
    cinta.autolubricats = cinta_Components_BBDD.at(13).toShort();
    cinta.cinta = cinta_Components_BBDD.at(14).toShort();
    cinta.cargols_laterals_avellanado = cinta_Cargols_BBDD.at(9).toShort();
    cinta.funda_metallica_motor = cinta_Components_BBDD.at(15).toShort();
    cinta.pg9 = cinta_Components_BBDD.at(16).toShort();
    cinta.cargols_c48_funda_metallica = cinta_Cargols_BBDD.at(21).toShort();

    cinta.tensor.cos_tensor = cinta_Components_BBDD.at(1).toShort();
    cinta.tensor.tensor = cinta_Components_BBDD.at(2).toShort();
    cinta.tensor.cargols_lateral = cinta_Cargols_BBDD.at(6).toShort();
    cinta.tensor.cargol_tensor = cinta_Cargols_BBDD.at(11).toShort();
    cinta.tensor.femella_tensor = cinta_Cargols_BBDD.at(17).toShort();

    cinta.motor.motor_cinta = cinta_Electricitat_BBDD.at(5).toShort();
    cinta.motor.cargols_c512_motor = cinta_Cargols_BBDD.at(3).toShort();
    cinta.motor.dentada_gran = cinta_Components_BBDD.at(3).toShort();
    cinta.motor.dentada_petita = cinta_Components_BBDD.at(4).toShort();
    cinta.motor.pasador_elastic_d5 = cinta_Components_BBDD.at(5).toShort();
    cinta.motor.pasador_elastic_d3 = cinta_Components_BBDD.at(6).toShort();
    cinta.motor.brida_motor =  cinta_Components_BBDD.at(34).toShort();
    cinta.motor.funda_motor = cinta_Components_BBDD.at(7).toShort();
    cinta.motor.cinta_americana = cinta_Components_BBDD.at(8).toShort();

    cinta.detector_nivell.barra = cinta_Components_BBDD.at(36).toShort();
    cinta.detector_nivell.cargols_c48 = cinta_Cargols_BBDD.at(21).toShort();
    cinta.detector_nivell.cargols_subjeccio_tapa = cinta_Cargols_BBDD.at(24).toShort();
    cinta.detector_nivell.cos_detector = cinta_Components_BBDD.at(35).toShort();
    cinta.detector_nivell.piu_detector_nivell = cinta_Components_BBDD.at(36).toShort();
    cinta.detector_nivell.presoner_rm3 = cinta_Cargols_BBDD.at(23).toShort();
    cinta.detector_nivell.suport = cinta_Components_BBDD.at(39).toShort();
    cinta.detector_nivell.tapa = cinta_Components_BBDD.at(38).toShort();
    cinta.detector_nivell.volanderes_vrm4 = cinta_Cargols_BBDD.at(19).toShort();

    return cinta;
}

Tolva funcio_NovaTolva()
{
    Tolva tolva;
    Cinta cinta_creada;

    QStringList tolva_Cargols_BBDD;
    QStringList tolva_Components_BBDD;
    QStringList tolva_Cos_BBDD;

    tolva_Cargols_BBDD = cargols_BBDD();
    tolva_Components_BBDD = components_BBDD();
    tolva_Cos_BBDD = cos_BBDD();

    cinta_creada = funcio_NovaCinta();

    tolva.cinta = cinta_creada;
    tolva.tolva = tolva_Cos_BBDD.at(1).toShort();
    tolva.pinta.cargols_c512_gotasebo = tolva_Cargols_BBDD.at(4).toShort();
    tolva.cargols_c525_allen = tolva_Cargols_BBDD.at(8).toShort();
    tolva.cargols_c812_allen = tolva_Cargols_BBDD.at(13).toShort();
    tolva.pinta.glaseadora = tolva_Components_BBDD.at(18).toShort();
    tolva.pinta.pinta = tolva_Components_BBDD.at(17).toShort();

    return tolva;
}

Bancada funcio_NovaBancada()
{
    Bancada bancada;

    QStringList bancada_Cargols_BBDD;
    QStringList bancada_Components_BBDD;
    QStringList bancada_Cos_BBDD;
    QStringList bancada_Electricitat_BBDD;

    bancada_Cargols_BBDD = cargols_BBDD();
    bancada_Components_BBDD = components_BBDD();
    bancada_Cos_BBDD = cos_BBDD();
    bancada_Electricitat_BBDD = electricitat_BBDD();

    bancada.cuba.cuba_gran = bancada_Components_BBDD.at(30).toShort();
    bancada.cuba.cuba_petita = bancada_Components_BBDD.at(31).toShort();
    bancada.cuba.cordill_cuba = bancada_Components_BBDD.at(32).toShort();
    bancada.cuba.logo_petit = bancada_Components_BBDD.at(20).toShort();
    bancada.cuba.cargols_logo_cuba = bancada_Cargols_BBDD.at(22).toShort();

    bancada.potes.potes = bancada_Cos_BBDD.at(4).toShort();
    bancada.potes.femelles_frm10 = bancada_Cargols_BBDD.at(18).toShort();;

    bancada.porta.cinta_espuma = bancada_Components_BBDD.at(25).toShort();
    bancada.porta.frontisses = bancada_Components_BBDD.at(29).toShort();
    bancada.porta.logo_gran = bancada_Components_BBDD.at(19).toShort();
    bancada.porta._porta = bancada_Cos_BBDD.at(3).toShort();
    bancada.porta.pestell_porta.pestell_antic = bancada_Components_BBDD.at(27).toShort();
    bancada.porta.pestell_porta.pestell_nou = bancada_Components_BBDD.at(28).toShort();

    bancada.bancada = bancada_Cos_BBDD.at(0).toShort();
    bancada.cargols_810 = bancada_Cargols_BBDD.at(12).toShort();
    //bancada.cargols_812_tolva = bancada_Cargols_BBDD.at(13).toShort();
    bancada.cargols_816_vibrador = bancada_Cargols_BBDD.at(25).toShort();
    bancada.cargols_820_vibrador = bancada_Cargols_BBDD.at(26).toShort();
    bancada.volanderes_rm8 = bancada_Cargols_BBDD.at(27).toShort();
    bancada.subjector_quadre_electric = bancada_Components_BBDD.at(33).toShort();
    bancada.vibrador = bancada_Electricitat_BBDD.at(6).toShort();

    return bancada;
}
