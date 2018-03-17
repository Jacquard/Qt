#ifndef DISTANCIADIALOG_H
#define DISTANCIADIALOG_H

#include <QDialog>

namespace Ui {
class DistanciaDialog;
}

class DistanciaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DistanciaDialog(QWidget *parent = 0);
    ~DistanciaDialog();
    int distancia();

private:
    Ui::DistanciaDialog *ui;
};

#endif // DISTANCIADIALOG_H
