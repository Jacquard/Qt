#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    time_t ara;
    struct tm *tm_ara;

    ara = time ( NULL );
    tm_ara = localtime ( &ara );

    if(tm_ara->tm_year > 115)
    {
        QMessageBox::information(this, "Error", "Aplicació massa antiga.");
        exit(0);
    }
    else
    {
        ui->setupUi(this);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString resultat_5k, resultat_10k, resultat_15k, resultat_21k, resultat_42k;

    int edat = ui->lineEdit->text().toInt();
    if(edat <= 0 || edat >=220)
    {
        QMessageBox::information(this, "QLineEdit Error", "L'edat entrada no es permesa.");
        ui->lineEdit->setText("");
    }
    else
    {
        int resultat = 220 - edat;
        ui->label_3->setText(QString::number(resultat));
    }

    float Minut = (float)ui->spinBox->text().toFloat();
    float Segon = (float)ui->spinBox_2->text().toFloat();
    float velocitat = (1000/(Minut*60+Segon))*3.6;
    ui->label_6->setText(QString::number(velocitat, 'g', 4) + " Km/h");

    float tempsHora5k = qFloor((5000 / (1000/(Minut*60+Segon)))/3600);
    float tempsMins5k = qFloor((5000 / (1000/(Minut*60+Segon)))/60);
    float tempsSeg5k =  qFloor(fmodf((5000 / (1000/(Minut*60+Segon))),60));
    if(tempsMins5k >= 60)
    {
        resultat_5k.append(QString::number(tempsHora5k));
        resultat_5k.append(" : ");
    }
    resultat_5k.append(QString::number(fmodf(tempsMins5k,60), 'g', 2));
    resultat_5k.append(" : ");
    resultat_5k.append(QString::number(tempsSeg5k, 'g', 2));
    ui->label_9->setText(resultat_5k);

    float tempsHora10k = qFloor((10000 / (1000/(Minut*60+Segon)))/3600);
    float tempsMins10k = qFloor((10000 / (1000/(Minut*60+Segon)))/60);
    float tempsSeg10k =  qFloor(fmodf((10000 / (1000/(Minut*60+Segon))),60));
    if(tempsMins10k>=60 && tempsMins10k < 240)
    {
        resultat_10k.append(QString::number(tempsHora10k, 'g', 2));
        resultat_10k.append(" : ");
        resultat_10k.append(QString::number(fmodf(tempsMins10k,60), 'g', 2));
    }
    else
    {
        resultat_10k.append(QString::number(fmodf(tempsMins10k,60), 'g', 2));
    }
    resultat_10k.append(" : ");
    resultat_10k.append(QString::number(tempsSeg10k, 'g', 2));
    ui->label_10->setText(resultat_10k);

    float tempsHora15k = qFloor((15000 / (1000/(Minut*60+Segon)))/3600);
    float tempsMins15k = qFloor((15000 / (1000/(Minut*60+Segon)))/60);
    float tempsSeg15k =  qFloor(fmodf((15000 / (1000/(Minut*60+Segon))),60));
    if(tempsMins15k>=60 && tempsMins15k < 240)
    {
        resultat_15k.append(QString::number(tempsHora15k, 'g', 2));
        resultat_15k.append(" : ");
        resultat_15k.append(QString::number(fmodf(tempsMins15k,60), 'g', 2));
    }
    else
    {
        resultat_15k.append(QString::number(tempsMins15k, 'g', 2));
    }
    resultat_15k.append(" : ");
    resultat_15k.append(QString::number(tempsSeg15k, 'g', 2));
    ui->label_11->setText(resultat_15k);

    float tempsHora21k = qFloor((21097 / (1000/(Minut*60+Segon)))/3600);
    float tempsMins21k = qFloor((21097 / (1000/(Minut*60+Segon)))/60);
    float tempsSeg21k =  qFloor(fmodf((21097 / (1000/(Minut*60+Segon))),60));
    if(tempsMins21k>=60 && tempsMins21k < 360)
    {
        resultat_21k.append(QString::number(tempsHora21k, 'g', 2));
        resultat_21k.append(" : ");
        resultat_21k.append(QString::number(fmodf(tempsMins21k,60), 'g', 2));
    }
    else
    {
        resultat_21k.append(QString::number(tempsMins21k, 'g', 2));
    }
    resultat_21k.append(" : ");
    resultat_21k.append(QString::number(tempsSeg21k, 'g', 2));
    ui->label_13->setText(resultat_21k);

    float tempsMaratoHora = qFloor(42195 / (1000/(Minut*60+Segon))/3600);
    float tempsMaratoMin = qFloor(fmodf(42195 / (1000/(Minut*60+Segon)),3600)/60);
    float tempsMaratoSeg =  qFloor(fmodf((42195 / (1000/(Minut*60+Segon))),60));
    resultat_42k.append(QString::number(tempsMaratoHora));
    resultat_42k.append(" : ");
    resultat_42k.append(QString::number(tempsMaratoMin, 'g', 2));
    resultat_42k.append(" : ");
    resultat_42k.append(QString::number(tempsMaratoSeg, 'g', 2));
    ui->label_14->setText(resultat_42k);
}

void MainWindow::on_actionQuant_a_triggered()
{
    mDialog = new Dialog(this);
    mDialog->show();
    mDialog->setWindowTitle("I mean our partnership is untied.");
    //mDialog->setWindowTitle("I have a feeling it's really gonna be a good, long battle.");
}
