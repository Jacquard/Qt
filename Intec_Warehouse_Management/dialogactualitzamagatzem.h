#ifndef DIALOGACTUALITZAMAGATZEM_H
#define DIALOGACTUALITZAMAGATZEM_H

#include <QDialog>
#include "auxiliar_bbdd.h"

namespace Ui {
class DialogActualitzaMagatzem;
}

class DialogActualitzaMagatzem : public QDialog
{
    Q_OBJECT

public:
    explicit DialogActualitzaMagatzem(int actiu, QWidget *parent = 0);
    ~DialogActualitzaMagatzem();

    int nombreBancades;
    int nombreTolves;
    int nombreCampanes;
    int nombrePortes;

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::DialogActualitzaMagatzem *ui;
};

#endif // DIALOGACTUALITZAMAGATZEM_H
