#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_Sortida->setText("<center>");
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::on_pushButton1_clicked()
{
    QString arxiu1 = QFileDialog::getOpenFileName(this, tr("Open file #1"), "/", "All files (*.*);;Text files (*.txt);;ASCII Armoured file (*.asc);;C Source Code (other's stinks) (*.c)");
    ui->lineEdit1->setText(arxiu1);
    return arxiu1;
}

QString MainWindow::on_pushButton2_clicked()
{
    QString arxiu2 = QFileDialog::getOpenFileName(this, tr("Open file #2"), "/", "All files (*.*);;Text files (*.txt);;ASCII Armoured file (*.asc);;C Source Code (other's stinks) (*.c)");
    ui->lineEdit2->setText(arxiu2);
    return arxiu2;
}

void MainWindow::on_pushButton_clicked()
{
    if (ui->lineEdit1->text().isEmpty())
    {
        QMessageBox::information(this, "Information", "Select file #1");
    }
    else if (ui->lineEdit2->text().isEmpty())
    {
        QMessageBox::information(this, "Information", "Select file #2");
    }
    else
    {
        QString arxiu1 = ui->lineEdit1->text();
        QString arxiu2 = ui->lineEdit2->text();
        Calcula(arxiu1, arxiu2);
    }
}

int MainWindow::Calcula(QString string1, QString string2)
{
    ui->label_Sortida->setText("");

    QChar caracterInicial_string1 = string1.at(0);
    QChar caracterInicial_string2 = string2.at(0);

    if (caracterInicial_string1 == 66)
    {
        caracterInicial_string1 = string1.at(7);
    }
    if (caracterInicial_string2 == 66)
    {
        caracterInicial_string2 = string2.at(7);
    }

    if ((caracterInicial_string1 == 47) && (caracterInicial_string2 == 47))
    {
        ui->label_Fitxer_1->setText("File 1:");
        ui->label_Fitxer_2->setText("File 2:");

        QFile file1(string1);
        QFile file2(string2);
        if (file1.open(QIODevice::ReadOnly) && file2.open(QIODevice::ReadOnly))
        {
            QByteArray unga_sha3 = file1.readAll();
            QByteArray resultat_unga_sha3 = QCryptographicHash::hash(unga_sha3,QCryptographicHash::Sha3_512);
            QByteArray resultat_unga_sha2 = QCryptographicHash::hash(unga_sha3,QCryptographicHash::Sha512);

            QByteArray ungb_sha3 = file2.readAll();
            QByteArray resultat_ungb_sha3 = QCryptographicHash::hash(ungb_sha3,QCryptographicHash::Sha3_512);
            QByteArray resultat_ungb_sha2 = QCryptographicHash::hash(ungb_sha3,QCryptographicHash::Sha512);

            QString final_1_sha3 = QString(resultat_unga_sha3.toHex());
            QString final_1_sha2 = QString(resultat_unga_sha2.toHex());
            QString final_2_sha3 = QString(resultat_ungb_sha3.toHex());
            QString final_2_sha2 = QString(resultat_ungb_sha2.toHex());

            if (QString::compare(final_1_sha3, final_2_sha3, Qt::CaseInsensitive) == 0)
            {
                if (QString::compare(final_1_sha2, final_2_sha2, Qt::CaseInsensitive) == 0)
                {
                    if (ui->actionActivate->isChecked())
                    {
                        pintar(3);
                    }
                    else
                    {
                        pintar(1);
                    }
                    ui->statusBar->showMessage("MD5:  " + QString(QCryptographicHash::hash(unga_sha3, QCryptographicHash::Md5).toHex()));
                    QMessageBox::information(this, "Info", "File comparison made with SHA3_512.\nHere's only the MD5");
                    if (ui->actionShow_info->isChecked())
                    {
                        AcceptaPeticio(1, string1);
                    }
                    if (ui->actionThe_expert_hash->isChecked())
                    {
                        QThread::sleep(1);
                        mDialog2 = new Dialog2(this);
                        mDialog2->setWindowTitle("The 'Expert' hashes");
                        mDialog2->collision(string1, string2);
                        mDialog2->show();
                    }
                    return 1;
                }
            }
            else
            {
                if (ui->actionActivate->isChecked())
                {
                    pintar(4);
                }
                else
                {
                    pintar(2);
                }
                ui->statusBar->showMessage("    ¡Nchts Cagontó!  Files differ!");
                if (ui->actionThe_expert_hash->isChecked())
                {
                    QThread::sleep(1);
                    mDialog2 = new Dialog2(this);
                    mDialog2->setWindowTitle("The 'Expert' hashes");
                    mDialog2->collision(string1, string2);
                    mDialog2->show();
                }
                return 0;
            }
        }
    }
    else
    {
        /* Un arxiu i un hash */
        /*
         * programa
         */
        QChar lletra1 = string1.at(0);
        QChar lletra2 = string2.at(0);

        if ((((lletra1.unicode() >= 97) && (lletra1.unicode() <= 102)) || ((lletra1.unicode() >= 48) && (lletra1.unicode() <= 57))) && (lletra2.unicode() == 47))
        {
            ui->label_Fitxer_1->setText("Hash 1:");
            ui->label_Fitxer_2->setText("File 2:");

            QFile file2(string2);

            if (file2.open(QIODevice::ReadOnly))
            {
                if (string1.length() == 32)
                {/* md5 */
                    QByteArray ungb_md5 = file2.readAll();
                    QByteArray resultat_md5 = QCryptographicHash::hash(ungb_md5, QCryptographicHash::Md5);

                    QString final_md5 = QString(resultat_md5.toHex());

                    if (QString::compare(string1, final_md5, Qt::CaseInsensitive) == 0)
                    {
                        pintar(1);
                        ui->statusBar->showMessage(final_md5);
                    }
                    else
                    {
                        pintar(2);
                        ui->statusBar->showMessage("    ¡Nchts Cagontó!  Files differ!");
                    }
                }
                else if (string1.length() == 40)
                {/* 1 */
                    QByteArray ungb_sha1 = file2.readAll();
                    QByteArray resultat_sha1 = QCryptographicHash::hash(ungb_sha1, QCryptographicHash::Sha1);

                    QString final_sha1 = QString(resultat_sha1.toHex());

                    if (QString::compare(string1, final_sha1, Qt::CaseInsensitive) == 0)
                    {
                        pintar(1);
                        ui->statusBar->showMessage(final_sha1);
                    }
                    else
                    {
                        pintar(2);
                        ui->statusBar->showMessage("    ¡Nchts Cagontó!  Files differ!");
                    }
                }
                else if (string1.length() == 56)
                {/* 224 */
                    QByteArray ungb_sha224 = file2.readAll();
                    QByteArray resultat_sha224 = QCryptographicHash::hash(ungb_sha224, QCryptographicHash::Sha224);
                    QByteArray resultat_sha3224 = QCryptographicHash::hash(ungb_sha224, QCryptographicHash::Sha3_224);

                    QString final_sha224 = QString(resultat_sha224.toHex());
                    QString final_sha3224 = QString(resultat_sha3224.toHex());

                    if ((QString::compare(string1, final_sha224, Qt::CaseInsensitive) == 0) || (QString::compare(string1, final_sha3224, Qt::CaseInsensitive) == 0))
                    {
                        pintar(1);
                        ui->statusBar->showMessage(final_sha224);
                    }
                    else
                    {
                        pintar(2);
                        ui->statusBar->showMessage("    ¡Nchts Cagontó!  Files differ!");
                    }
                }
                else if (string1.length() == 64)
                {/* 256 */
                    QByteArray ungb_sha256 = file2.readAll();
                    QByteArray resultat_sha256 = QCryptographicHash::hash(ungb_sha256, QCryptographicHash::Sha256);
                    QByteArray resultat_sha3256 = QCryptographicHash::hash(ungb_sha256, QCryptographicHash::Sha3_256);


                    QString final_sha256 = QString(resultat_sha256.toHex());
                    QString final_sha3256 = QString(resultat_sha3256.toHex());

                    if ((QString::compare(string1, final_sha256, Qt::CaseInsensitive) == 0) || (QString::compare(string1, final_sha3256, Qt::CaseInsensitive) == 0))
                    {
                        pintar(1);
                        ui->statusBar->showMessage(final_sha256);
                    }
                    else
                    {
                        pintar(2);
                        ui->statusBar->showMessage("    ¡Nchts Cagontó!  Files differ!");
                    }
                }
                else if (string1.length() == 96)
                {/* 384 */
                    QByteArray ungb_sha384 = file2.readAll();
                    QByteArray resultat_sha384 = QCryptographicHash::hash(ungb_sha384, QCryptographicHash::Sha384);
                    QByteArray resultat_sha3384 = QCryptographicHash::hash(ungb_sha384, QCryptographicHash::Sha3_384);

                    QString final_sha384 = QString(resultat_sha384.toHex());
                    QString final_sha3384 = QString(resultat_sha3384.toHex());

                    if ((QString::compare(string1, final_sha384, Qt::CaseInsensitive) == 0) || (QString::compare(string1, final_sha3384, Qt::CaseInsensitive) == 0))
                    {
                        pintar(1);
                        ui->statusBar->showMessage(final_sha384);
                    }
                    else
                    {
                        pintar(2);
                        ui->statusBar->showMessage("    ¡Nchts Cagontó!  Files differ!");
                    }
                }
                else if (string1.length() == 128)
                {/* 512 */
                    QByteArray ungb_sha3 = file2.readAll();
                    QByteArray resultat_ungb_sha512 = QCryptographicHash::hash(ungb_sha3,QCryptographicHash::Sha512);
                    QByteArray resultat_ungb_sha3512 = QCryptographicHash::hash(ungb_sha3,QCryptographicHash::Sha3_512);

                    QString final_sha512 = QString(resultat_ungb_sha512.toHex());
                    QString final_sha3512 = QString(resultat_ungb_sha3512.toHex());

                    if ((QString::compare(string1, final_sha512, Qt::CaseInsensitive) == 0) || (QString::compare(string1, final_sha3512, Qt::CaseInsensitive) == 0))
                    {
                        pintar(1);
                        ui->statusBar->showMessage(final_sha512);
                    }
                    else
                    {
                        pintar(2);
                        ui->statusBar->showMessage("    ¡Nchts Cagontó!  Files differ!");
                    }
                }
            }
        }
        else if ((((lletra2.unicode() >= 97) && (lletra2.unicode() <= 102)) || ((lletra2.unicode() >= 48) && (lletra2.unicode() <= 57))) && (lletra1.unicode() == 47))
        {
            ui->label_Fitxer_1->setText("File 1:");
            ui->label_Fitxer_2->setText("Hash 2:");

            QFile file1(string1);

            if (file1.open(QIODevice::ReadOnly))
            {
                if (string2.length() == 32)
                {/* md5 */
                    QByteArray ungb_md5 = file1.readAll();
                    QByteArray resultat_md5 = QCryptographicHash::hash(ungb_md5, QCryptographicHash::Md5);

                    QString final_md5 = QString(resultat_md5.toHex());

                    if (QString::compare(string2, final_md5, Qt::CaseInsensitive) == 0)
                    {
                        pintar(1);
                        ui->statusBar->showMessage(final_md5);
                    }
                    else
                    {
                        pintar(2);
                        ui->statusBar->showMessage("    ¡Nchts Cagontó!  Files differ!");
                    }
                }
                else if (string2.length() == 40)
                {/* 1 */
                    QByteArray ungb_sha1 = file1.readAll();
                    QByteArray resultat_sha1 = QCryptographicHash::hash(ungb_sha1, QCryptographicHash::Sha1);

                    QString final_sha1 = QString(resultat_sha1.toHex());

                    if (QString::compare(string2, final_sha1, Qt::CaseInsensitive) == 0)
                    {
                        pintar(1);
                        ui->statusBar->showMessage(final_sha1);
                    }
                    else
                    {
                        pintar(2);
                        ui->statusBar->showMessage("    ¡Nchts Cagontó!  Files differ!");
                    }
                }
                else if (string2.length() == 56)
                {/* 224 */
                    QByteArray ungb_sha224 = file1.readAll();
                    QByteArray resultat_sha224 = QCryptographicHash::hash(ungb_sha224, QCryptographicHash::Sha224);
                    QByteArray resultat_sha3224 = QCryptographicHash::hash(ungb_sha224, QCryptographicHash::Sha3_224);

                    QString final_sha224 = QString(resultat_sha224.toHex());
                    QString final_sha3224 = QString(resultat_sha3224.toHex());

                    if ((QString::compare(string2, final_sha224, Qt::CaseInsensitive) == 0) || (QString::compare(string2, final_sha3224, Qt::CaseInsensitive) == 0))
                    {
                        pintar(1);
                        ui->statusBar->showMessage(final_sha224);
                    }
                    else
                    {
                        pintar(2);
                        ui->statusBar->showMessage("    ¡Nchts Cagontó!  Files differ!");
                    }
                }
                else if (string2.length() == 64)
                {/* 256 */
                    QByteArray ungb_sha256 = file1.readAll();
                    QByteArray resultat_sha256 = QCryptographicHash::hash(ungb_sha256, QCryptographicHash::Sha256);
                    QByteArray resultat_sha3256 = QCryptographicHash::hash(ungb_sha256, QCryptographicHash::Sha3_256);

                    QString final_sha256 = QString(resultat_sha256.toHex());
                    QString final_sha3256 = QString(resultat_sha3256.toHex());

                    if ((QString::compare(string2, final_sha256, Qt::CaseInsensitive) == 0) || (QString::compare(string2, final_sha3256, Qt::CaseInsensitive) == 0))
                    {
                        pintar(1);
                        ui->statusBar->showMessage(final_sha256);
                    }
                    else
                    {
                        pintar(2);
                        ui->statusBar->showMessage("    ¡Nchts Cagontó!  Files differ!");
                    }
                }
                else if (string2.length() == 96)
                {/* 384 */
                    QByteArray ungb_sha384 = file1.readAll();
                    QByteArray resultat_sha384 = QCryptographicHash::hash(ungb_sha384, QCryptographicHash::Sha384);
                    QByteArray resultat_sha3384 = QCryptographicHash::hash(ungb_sha384, QCryptographicHash::Sha3_384);

                    QString final_sha384 = QString(resultat_sha384.toHex());
                    QString final_sha3384 = QString(resultat_sha3384.toHex());

                    if ((QString::compare(string2, final_sha384, Qt::CaseInsensitive) == 0) || (QString::compare(string2, final_sha3384, Qt::CaseInsensitive) == 0))
                    {
                        pintar(1);
                        ui->statusBar->showMessage(final_sha384);
                    }
                    else
                    {
                        pintar(2);
                        ui->statusBar->showMessage("    ¡Nchts Cagontó!  Files differ!");
                    }
                }
                else if (string2.length() == 128)
                {/* 512 */
                    QByteArray ungb_sha3 = file1.readAll();
                    QByteArray resultat_ungb_sha2 = QCryptographicHash::hash(ungb_sha3,QCryptographicHash::Sha512);
                    QByteArray resultat_ungb_sha3 = QCryptographicHash::hash(ungb_sha3,QCryptographicHash::Sha3_512);

                    QString final_sha512 = QString(resultat_ungb_sha3.toHex());
                    QString final_sha3512 = QString(resultat_ungb_sha2.toHex());

                    if ((QString::compare(string2, final_sha512, Qt::CaseInsensitive) == 0) || (QString::compare(string2, final_sha3512, Qt::CaseInsensitive) == 0))
                    {
                        pintar(1);
                        ui->statusBar->showMessage(final_sha512);
                    }
                    else
                    {
                        pintar(2);
                        ui->statusBar->showMessage("    ¡Nchts Cagontó!  Files differ!");
                    }
                }
            }
        }
    }
    return 0;
}

int MainWindow::AcceptaPeticio(int valorControl, QString cadena)
{
    if (valorControl == 1)
    {
        QThread::sleep(1);
        mDialog = new Dialog(this);
        mDialog->setWindowTitle("File info");
        /*
         * Next line pass information to the "Dialog" class to show file info
         * The function "info" is a Public function of Dialog class.
         * So it could be called by other Classes.
         */
        mDialog->info(cadena);
        mDialog->show();
        return 0;
    }
    else if (valorControl == 0)
    {
        return 0;
    }
    return 0;
}

void MainWindow::pintar(int color)
{
    /* Colors:
     * 1 - Fons Verd
     * 2 - Fons Vermell
     * 3 - Fons Blau
     * 4 - Fons Negre
     */
    if (color == 1)
    {
        QPalette background(palette());
        background.setColor(QPalette::Background, Qt::green);
        ui->label_Sortida->setAutoFillBackground(true);
        ui->label_Sortida->setPalette(background);
        //ui->menuHash->setEnabled(true);
    }
    else if (color == 2)
    {
        QPalette background(palette());
        background.setColor(QPalette::Background, Qt::red);
        ui->label_Sortida->setAutoFillBackground(true);
        ui->label_Sortida->setPalette(background);
    }
    else if (color == 3)
    {
        QPalette background(palette());
        background.setColor(QPalette::Background, Qt::blue);
        ui->label_Sortida->setAutoFillBackground(true);
        ui->label_Sortida->setPalette(background);
        //ui->menuHash->setEnabled(true);
    }
    else if (color == 4)
    {
        QPalette background(palette());
        background.setColor(QPalette::Background, Qt::black);
        ui->label_Sortida->setAutoFillBackground(true);
        ui->label_Sortida->setPalette(background);
    }
}

QByteArray MainWindow::MD4_sum(QString nomFitxer)
{
    QFile file1(nomFitxer);
    QByteArray FitxerLlegit = file1.readAll();
    QByteArray resultat_FitxerLlegit = QCryptographicHash::hash(FitxerLlegit,QCryptographicHash::Md4);
    QMessageBox::information(this, "MD5 Hash", resultat_FitxerLlegit.toHex());

    return 0;
}

QByteArray MainWindow::MD5_sum(QString nomFitxer)
{
    QFile file1(nomFitxer);
    QByteArray FitxerLlegit = file1.readAll();
    QByteArray resultat_FitxerLlegit = QCryptographicHash::hash(FitxerLlegit,QCryptographicHash::Md5);
    QMessageBox::information(this, "MD5 Hash", resultat_FitxerLlegit.toHex());

    return 0;
}
