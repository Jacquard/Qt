#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ui->centralWidget->styleSheet("background-color: rgb(96, 96, 96);");

    ui->tabWidget->setCurrentIndex(0);
    /* 320000 = 320 Km */
    ui->lineEdit_3->setValidator( new QIntValidator(0, 320000, this) );
    /* 129600 = 36 hores */
    ui->lineEdit_4->setValidator( new QIntValidator(0, 129600, this) );

    ui->lineEdit_2->installEventFilter(this);
    ui->lineEdit_3->installEventFilter(this);
    ui->lineEdit_4->installEventFilter(this);

    //MainWindow::setupTabs();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupTabs()
{
    QStringList llista = {"Metres", "Milles"};
    int nombreTabs = QString::number(llista.length()).toInt();

    for (int comptadorTabs = 0; comptadorTabs < nombreTabs; comptadorTabs++)
    {
        QWidget * w = new QWidget;
        w->setLayout(new QHBoxLayout);
        ui->tabWidget->addTab(w, llista.at(comptadorTabs));
    }

//    QTabWidget *w = new QTabWidget;
  //  w->addTab(new MerdaTab, tr("Metres"));


    QLayout *layout = ui->tabWidget->widget(0)->layout();
    layout->removeWidget(ui->tabWidget->widget(0));
    delete layout;
    layout = new QVBoxLayout;

    connect(ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(onTabChanged(int)));
}

void MainWindow::onTabChanged(int index)
{
    qDebug() << "kjahsd" << index;

    QLayout * layout = ui->tabWidget->widget(index)->layout();
    layout->removeWidget(ui->tabWidget->widget(index));
    delete layout;

    layout = new QVBoxLayout;

    QLabel *temp = new QLabel;
    temp->setText("uasnfaksda");
    layout->addWidget(temp);
    ui->tabWidget->widget(index)->setLayout(layout);
}

void MainWindow::setLaiAut()
{
    /*
     * Aquest layout és el que m'ha de pintar a cada tab
     */
    QLabel *distancia = new QLabel;
    distancia->setText("Distancia:");
    distancia->setMinimumWidth(100);
    QLineEdit *entraDistancia = new QLineEdit;
    entraDistancia->setMinimumWidth(330);
    entraDistancia->setAlignment(Qt::AlignCenter);

    QLabel *temps = new QLabel;
    temps->setText("Temps:");
    temps->setMinimumWidth(100);
    QLineEdit *entraTemps = new QLineEdit;
    entraTemps->setMinimumWidth(330);
    entraTemps->setAlignment(Qt::AlignCenter);

    QPushButton *botoCalcula = new QPushButton("Calcula");
    botoCalcula->setMinimumWidth(170);
    botoCalcula->setMinimumHeight(50);
    QLabel *sortidaDades = new QLabel;
    sortidaDades->setText("asdasdaskjansdnasjdnaj,nd");
    sortidaDades->setAlignment(Qt::AlignCenter);
    sortidaDades->setStyleSheet("border: 2px solid orange; border-radius: 15px;");

    QHBoxLayout *hlayDistancia = new QHBoxLayout;
    hlayDistancia->addWidget(distancia);
    hlayDistancia->addWidget(entraDistancia);

    QHBoxLayout *hlayTemps = new QHBoxLayout;
    hlayTemps->addWidget(temps);
    hlayTemps->addWidget(entraTemps);

    QVBoxLayout *vlay = new QVBoxLayout;
    vlay->addLayout(hlayDistancia);
    vlay->addLayout(hlayTemps);

    QHBoxLayout *entradaDades = new QHBoxLayout;
    entradaDades->addLayout(vlay);
    entradaDades->addWidget(botoCalcula);

    QVBoxLayout *final = new QVBoxLayout;
    final->addLayout(entradaDades);
    final->addWidget(sortidaDades);

    setLayout(final);
}

void MainWindow::on_pushButton_2_clicked()
{
    /*
     * Calcula en metres
     */
    if (ui->lineEdit_3->text().isEmpty() && ui->lineEdit_4->text().isEmpty())
    {
        QMessageBox *alertaGeneral = new QMessageBox;
        alertaGeneral->setIcon(QMessageBox::Warning);
        alertaGeneral->setWindowTitle("Alerta general");
        alertaGeneral->setText("Error!\nHas d'entrar distància i temps");
        alertaGeneral->show();
    }
    else if (ui->lineEdit_3->text().isEmpty())
    {
        QMessageBox *alertaMetres = new QMessageBox;
        alertaMetres->setIcon(QMessageBox::Warning);
        alertaMetres->setWindowTitle("Alerta!");
        alertaMetres->setText("Error!\nLa distància no pot ser nul·la!!");
        alertaMetres->show();
    }
    else if (ui->lineEdit_4->text().isEmpty())
    {
        QMessageBox *alertaTemps = new QMessageBox;
        alertaTemps->setIcon(QMessageBox::Warning);
        alertaTemps->setWindowTitle("Alerta!");
        alertaTemps->setText("Error!\nSense temps no es pot calcular!!");
        alertaTemps->show();
    }
    else
    {
        if (!ui->lineEdit_3->text().isEmpty() && !ui->lineEdit_4->text().isEmpty())
        {
            float distancia = ui->lineEdit_3->text().toFloat();
            float resultatTemps = ui->lineEdit_4->text().toFloat();
            float velocitat_ms = distancia / resultatTemps;

            float velocitatKmH = velocitat_ms * (float)3.6;

            float temps1000m = (float)1000 / velocitat_ms;
            int ritmeMinuts = temps1000m / 60;
            int ritmeSegons = fmod(temps1000m,60);
            //qDebug() << "Minuts:\t" << ritmeMinuts << "Segons:\t" << ritmeSegons;

            ui->label_6->setText("Velocitat:\t" + QString::number(velocitatKmH) + " Km/h" +
                                 "\nRitme 1000m:\t\t" + QString::number(ritmeMinuts) + "mins " + QString::number(ritmeSegons) + "s"
                                 );
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    /*
     * Calcula en milles
     */
    if (ui->lineEdit->text().isEmpty())
    {
        QMessageBox *alertaMilles = new QMessageBox;
        alertaMilles->setIcon(QMessageBox::Warning);
        alertaMilles->setWindowTitle("Alerta!");
        alertaMilles->setText("Error!\nEscriu alguna cosa");
        alertaMilles->show();
    }
    else
    {
        if (!ui->lineEdit->text().isEmpty() && !ui->lineEdit_2->text().isEmpty())
        {
            float distancia = ui->lineEdit->text().toFloat() * 1609.3439999930949397822;
            float resultatTemps = ui->lineEdit_2->text().toFloat();
            float velocitat_ms = distancia / resultatTemps;

            float velocitatKmH = velocitat_ms * (float)3.6;

            float temps1000m = (float)1000 / velocitat_ms;
            int ritmeMinuts = temps1000m / 60;
            int ritmeSegons = fmod(temps1000m,60);
            //qDebug() << ritmeSegons;

            ui->label_3->setText("Velocitat:\t" + QString::number(velocitatKmH) + " Km/h" +
                                 "\nRitme 1000m:\t\t" + QString::number(ritmeMinuts) + "mins " + QString::number(ritmeSegons) + "s"
                                 );
        }
    }
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->lineEdit_4 && event->type() == QEvent::MouseButtonPress)
    {
        dialogTemps = new TempsDialog(this);
        dialogTemps->setWindowTitle("Entra el temps");
        dialogTemps->exec();
        int num = dialogTemps->hola();

        if (num == 0)
        {
            QMessageBox *alertaTempsNul = new QMessageBox;
            alertaTempsNul->setIcon(QMessageBox::Warning);
            alertaTempsNul->setWindowTitle("Error!");
            alertaTempsNul->setText("Error! El temps no pot ser nul.\nTorna a clicar per entrar el temps");
            alertaTempsNul->show();
        }
        else if (num > 0)
        {
            ui->lineEdit_4->setText(QString::number(num));
        }
        return true;
    }
    else if (watched == ui->lineEdit_2 && event->type() == QEvent::MouseButtonPress)
    {
        //qDebug() << "QLineEdit Milles apretat";
        dialogTemps = new TempsDialog(this);
        dialogTemps->setWindowTitle("Entra el temps");
        dialogTemps->exec();
        int num = dialogTemps->hola();

        if (num == 0)
        {
            QMessageBox *alertaTempsNul = new QMessageBox;
            alertaTempsNul->setIcon(QMessageBox::Warning);
            alertaTempsNul->setWindowTitle("Error!");
            alertaTempsNul->setText("Error! El temps no pot ser nul.\nTorna a clicar per entrar el temps");
            alertaTempsNul->show();
        }
        else if (num > 0)
        {
            ui->lineEdit_2->setText(QString::number(num));
        }
        return true;
    }
    else if (watched == ui->lineEdit_3 && event->type() == QEvent::MouseButtonPress)
    {
        dialogDistancia = new DistanciaDialog(this);
        dialogDistancia->setWindowTitle("Selecciona distància");
        dialogDistancia->exec();

        int distanciaNum = dialogDistancia->distancia();

        ui->lineEdit_3->setText(QString::number(distanciaNum));
    }
    return false;
}
