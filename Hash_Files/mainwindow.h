#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCryptographicHash>

/* Entrada dades */
#include <QFileDialog>
#include <QString>
#include <QChar>
#include <QFile>
#include <QFileInfo>
#include <string.h>

/* Missatges de sortida */
#include <QMessageBox>

/* Per poder esperar 1s */
#include <QThread>

/* Per mostrar el Dialog de Info */
#include "dialog.h"
#include "dialog2.h"

namespace Ui {
class MainWindow;
class Dialog;
class Dialog2;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    QString on_pushButton1_clicked();
    QString on_pushButton2_clicked();

    void on_pushButton_clicked();

    int Calcula(QString string1, QString string2);
    int AcceptaPeticio(int valorControl, QString cadena);
    void pintar(int color);

    QByteArray MD4_sum(QString nomFitxer);
    QByteArray MD5_sum(QString nomFitxer);

private:
    Ui::MainWindow *ui;
    Dialog *mDialog;
    Dialog2 *mDialog2;
};

#endif // MAINWINDOW_H
