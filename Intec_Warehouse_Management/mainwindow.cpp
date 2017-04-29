#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_nova_clicked()
{
    novaDialog = new DialogNovaMaquina(this);
    novaDialog->show();
    novaDialog->setWindowTitle("Nova màquina");
}

void MainWindow::on_pushButton_consulta_clicked()
{
    consultaDialog = new DialogConsultaMaquines(this);
    consultaDialog->show();
    consultaDialog->setWindowTitle("Consulta màquina");
}

void MainWindow::on_actionConsulta_triggered()
{
    consultaMagatzem = new DialogActualitzaMagatzem(0, this);
    consultaMagatzem->show();
    consultaMagatzem->setWindowTitle("Dades magatzem");
}

void MainWindow::on_actionEntrada_dades_triggered()
{
    actualitzaMagatzem = new DialogActualitzaMagatzem(1, this);
    actualitzaMagatzem->show();
    actualitzaMagatzem->setWindowTitle("Actualitza dades magatzem");
}

void MainWindow::on_pushButton_previsio_clicked()
{
    previsioDialogMagatzem = new DialogPrevisioMagatzem(this);
    previsioDialogMagatzem->show();
    previsioDialogMagatzem->setWindowTitle("Previsió de màquines");
}
