#include "dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::info(QString data)
{
    Dialog::InfoArxiu(data);
    Dialog::Hashes(data);
}

void Dialog::InfoArxiu(QString data)
{
    QFileInfo arxiu(data);

    QStringList titols;

    ui->tableWidget->setColumnCount(2);
    titols << "Info" << "Valor";
    ui->tableWidget->setHorizontalHeaderLabels(titols);

    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, Info, new QTableWidgetItem("File name"));
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, Valor, new QTableWidgetItem(arxiu.fileName()));

    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, Info, new QTableWidgetItem("Owner"));
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, Valor, new QTableWidgetItem(arxiu.owner()));

    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, Info, new QTableWidgetItem("Owner ID"));
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, Valor, new QTableWidgetItem(arxiu.ownerId()));

    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, Info, new QTableWidgetItem("Created"));
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, Valor, new QTableWidgetItem(arxiu.created().toString("dd/MM/yyyy")));

    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, Info, new QTableWidgetItem("Modified"));
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, Valor, new QTableWidgetItem(arxiu.lastModified().toString("dd/MM/yyyy")));

    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, Info, new QTableWidgetItem("Last read"));
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, Valor, new QTableWidgetItem(arxiu.lastRead().toString("dd/MM/yyyy")));
}

void Dialog::Hashes(QString Data)
{
    QFile arxiu(Data);
    QStringList titols2;

    if (arxiu.open(QIODevice::ReadOnly))
    {
        QByteArray arxiuLectura = arxiu.readAll();
        QByteArray MD4 = QCryptographicHash::hash(arxiuLectura, QCryptographicHash::Md4).toHex();
        QByteArray MD5 = QCryptographicHash::hash(arxiuLectura, QCryptographicHash::Md5).toHex();
        QByteArray SHA1 = QCryptographicHash::hash(arxiuLectura, QCryptographicHash::Sha1).toHex();
        QByteArray SHA2_224 = QCryptographicHash::hash(arxiuLectura, QCryptographicHash::Sha224).toHex();
        QByteArray SHA2_256 = QCryptographicHash::hash(arxiuLectura, QCryptographicHash::Sha256).toHex();
        QByteArray SHA2_384 = QCryptographicHash::hash(arxiuLectura, QCryptographicHash::Sha384).toHex();
        QByteArray SHA2_512 = QCryptographicHash::hash(arxiuLectura, QCryptographicHash::Sha512).toHex();
        QByteArray SHA3_224 = QCryptographicHash::hash(arxiuLectura, QCryptographicHash::Sha3_224).toHex();
        QByteArray SHA3_256 = QCryptographicHash::hash(arxiuLectura, QCryptographicHash::Sha3_256).toHex();
        QByteArray SHA3_384 = QCryptographicHash::hash(arxiuLectura, QCryptographicHash::Sha3_384).toHex();
        QByteArray SHA3_512 = QCryptographicHash::hash(arxiuLectura, QCryptographicHash::Sha3_512).toHex();

        ui->tableWidget_1->setColumnCount(2);
        titols2 << "Info" << "Valor";
        ui->tableWidget_1->setHorizontalHeaderLabels(titols2);
        ui->tableWidget_1->horizontalHeader()->setStretchLastSection(true);

        ui->tableWidget_1->insertRow(ui->tableWidget_1->rowCount());
        ui->tableWidget_1->setItem(ui->tableWidget_1->rowCount() -1, Info, new QTableWidgetItem("MD4"));
        ui->tableWidget_1->setItem(ui->tableWidget_1->rowCount() -1, Valor, new QTableWidgetItem(QString(MD4)));

        ui->tableWidget_1->insertRow(ui->tableWidget_1->rowCount());
        ui->tableWidget_1->setItem(ui->tableWidget_1->rowCount() -1, Info, new QTableWidgetItem("MD5"));
        ui->tableWidget_1->setItem(ui->tableWidget_1->rowCount() -1, Valor, new QTableWidgetItem(QString(MD5)));

        ui->tableWidget_1->insertRow(ui->tableWidget_1->rowCount());
        ui->tableWidget_1->setItem(ui->tableWidget_1->rowCount() -1, Info, new QTableWidgetItem("SHA1"));
        ui->tableWidget_1->setItem(ui->tableWidget_1->rowCount() -1, Valor, new QTableWidgetItem(QString(SHA1)));

        ui->tableWidget_1->insertRow(ui->tableWidget_1->rowCount());
        ui->tableWidget_1->setItem(ui->tableWidget_1->rowCount() -1, Info, new QTableWidgetItem("SHA 224"));
        ui->tableWidget_1->setItem(ui->tableWidget_1->rowCount() -1, Valor, new QTableWidgetItem(QString(SHA2_224)));

        ui->tableWidget_1->insertRow(ui->tableWidget_1->rowCount());
        ui->tableWidget_1->setItem(ui->tableWidget_1->rowCount() -1, Info, new QTableWidgetItem("SHA 256"));
        ui->tableWidget_1->setItem(ui->tableWidget_1->rowCount() -1, Valor, new QTableWidgetItem(QString(SHA2_256)));

        ui->tableWidget_1->insertRow(ui->tableWidget_1->rowCount());
        ui->tableWidget_1->setItem(ui->tableWidget_1->rowCount() -1, Info, new QTableWidgetItem("SHA 384"));
        ui->tableWidget_1->setItem(ui->tableWidget_1->rowCount() -1, Valor, new QTableWidgetItem(QString(SHA2_384)));

        ui->tableWidget_1->insertRow(ui->tableWidget_1->rowCount());
        ui->tableWidget_1->setItem(ui->tableWidget_1->rowCount() -1, Info, new QTableWidgetItem("SHA 512"));
        ui->tableWidget_1->setItem(ui->tableWidget_1->rowCount() -1, Valor, new QTableWidgetItem(QString(SHA2_512)));

        ui->tableWidget_1->insertRow(ui->tableWidget_1->rowCount());
        ui->tableWidget_1->setItem(ui->tableWidget_1->rowCount() -1, Info, new QTableWidgetItem("Keccak 224"));
        ui->tableWidget_1->setToolTip("Keccak is the winner of SHA3 new standard");
        ui->tableWidget_1->setItem(ui->tableWidget_1->rowCount() -1, Valor, new QTableWidgetItem(QString(SHA3_224)));

        ui->tableWidget_1->insertRow(ui->tableWidget_1->rowCount());
        ui->tableWidget_1->setItem(ui->tableWidget_1->rowCount() -1, Info, new QTableWidgetItem("Keccak 256"));
        ui->tableWidget_1->setItem(ui->tableWidget_1->rowCount() -1, Valor, new QTableWidgetItem(QString(SHA3_256)));

        ui->tableWidget_1->insertRow(ui->tableWidget_1->rowCount());
        ui->tableWidget_1->setItem(ui->tableWidget_1->rowCount() -1, Info, new QTableWidgetItem("Keccak 384"));
        ui->tableWidget_1->setItem(ui->tableWidget_1->rowCount() -1, Valor, new QTableWidgetItem(QString(SHA3_384)));

        ui->tableWidget_1->insertRow(ui->tableWidget_1->rowCount());
        ui->tableWidget_1->setItem(ui->tableWidget_1->rowCount() -1, Info, new QTableWidgetItem("Keccak 512"));
        ui->tableWidget_1->setItem(ui->tableWidget_1->rowCount() -1, Valor, new QTableWidgetItem(QString(SHA3_512)));

    }
    else
    {
        exit(0);
    }
}
