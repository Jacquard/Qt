#ifndef DIALOGPREVISIOMAGATZEM_H
#define DIALOGPREVISIOMAGATZEM_H

#include <QDialog>

#include <QtGui/QPalette>

#include "auxiliar_bbdd.h"

namespace Ui {
class DialogPrevisioMagatzem;
}

class DialogPrevisioMagatzem : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPrevisioMagatzem(QWidget *parent = 0);
    ~DialogPrevisioMagatzem();

private slots:
    void on_pushButton_clicked();

    void crearCampana(int controlLogo);
    void crearTolva();
    void crearBancada();//int ControlCuba, int controlCordill);


private:
    Ui::DialogPrevisioMagatzem *ui;
};

#endif // DIALOGPREVISIOMAGATZEM_H
