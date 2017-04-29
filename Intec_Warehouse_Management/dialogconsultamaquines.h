#ifndef DIALOGCONSULTAMAQUINES_H
#define DIALOGCONSULTAMAQUINES_H

#include <QDialog>
#include "dialogactualitzamagatzem.h"

#include <QMessageBox>

namespace Ui {
class DialogConsultaMaquines;
}

class DialogConsultaMaquines : public QDialog
{
    Q_OBJECT

public:
    explicit DialogConsultaMaquines(QWidget *parent = 0);
    ~DialogConsultaMaquines();

    int Bancades;
    int Campanes;
    int Tolves;
    int Portes;

private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogConsultaMaquines *ui;
};

#endif // DIALOGCONSULTAMAQUINES_H
