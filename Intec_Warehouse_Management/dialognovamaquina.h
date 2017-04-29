#ifndef DIALOGNOVAMAQUINA_H
#define DIALOGNOVAMAQUINA_H

#include <QDialog>              // Per a mostrar la pantalla emergent
#include <QListWidgetItem>      // Per a mostrar la llista d'elements
#include <QTableWidgetItem>     // Per a mostrar en el groupbox
#include <QString>

#include "auxiliar_bbdd.h"

namespace Ui {
class DialogNovaMaquina;
}

class DialogNovaMaquina : public QDialog
{
    Q_OBJECT

public:
    explicit DialogNovaMaquina(QWidget *parent = 0);
    ~DialogNovaMaquina();

private:
    Ui::DialogNovaMaquina *ui;

    QStringList identificador_Columna_TableWidgets = {"Pais", "Tipus", "Llarg", "Bancada", "Tolva", "Campana"};
    QStringList llista_Cargols = {"Cargols", "Femelles"};
    QStringList llista_Llancadora = {"313 mm", "413 mm", "463 mm", "563 mm"};

private slots:
    void on_listWidget_Paisos_itemActivated();
    void on_pushButton_clicked();
    int comptadorLlancadora(int numero);
    void avis_Barres(int numero);

    void columna_Bancada(int controlBancada);
    void columna_Tolva(int controlTolva);
    void columna_Campana(int controlCampana);

    void crearCampana(int controlLogo);
    void crearTolva();
    void crearBancada(int ControlCuba, int controlCordill);

};

#endif // DIALOGNOVAMAQUINA_H
