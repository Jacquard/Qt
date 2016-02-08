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

void MainWindow::on_pushButton_clicked()
{
    qsrand(time(NULL));

    short longitudContrasenya = qrand() % 26 +1;
    while(longitudContrasenya < 8)
    {
        longitudContrasenya = qrand() % 26 + 1;
    }

    //QMessageBox::information(this, "Information", QString::number(longitudContrasenya));

    QString unga = cadena(longitudContrasenya);
    QByteArray array = unga.toLatin1();
    ui->label->setText(unga);
    ui->statusBar->showMessage("    SHA-1:  " + QString(QCryptographicHash::hash(array, QCryptographicHash::Sha1).toHex()));
}

QString MainWindow::cadena(const int longitud)
{
    QString cadena;
    short comptador;
    const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_.,;:+-*/!$%&()^=¡{}][@#");

    QString randomString;

    for(comptador=0; comptador<longitud; ++comptador)
    {
        int index = qrand() % possibleCharacters.length();
        QChar nextChar = possibleCharacters.at(index);
        cadena.append(nextChar);
    }
    return cadena;
}
