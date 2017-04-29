#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QtCharts/QtCharts>

#include "dialognovamaquina.h"
#include "dialogconsultamaquines.h"
#include "dialogactualitzamagatzem.h"
#include "dialogprevisiomagatzem.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_nova_clicked();
    void on_pushButton_consulta_clicked();
    void on_pushButton_previsio_clicked();

    void on_actionConsulta_triggered();

    void on_actionEntrada_dades_triggered();

private:
    Ui::MainWindow *ui;
    DialogNovaMaquina *novaDialog;

    DialogConsultaMaquines *consultaDialog;

    DialogActualitzaMagatzem *consultaMagatzem;
    DialogActualitzaMagatzem *actualitzaMagatzem;

    DialogPrevisioMagatzem *previsioDialogMagatzem;
};

#endif // MAINWINDOW_H
