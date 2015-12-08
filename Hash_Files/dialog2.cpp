#include "dialog2.h"
#include "ui_dialog2.h"

Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
}

Dialog2::~Dialog2()
{
    delete ui;
}

void Dialog2::collision(QString data1, QString data2)
{
    QChar caracterInicial_string1 = data1.at(0);
    QChar caracterInicial_string2 = data2.at(0);

    /*
     * Mirem que siguin dos fitxers i no fitxer i hash
     */
    if ((caracterInicial_string1 == 47) && (caracterInicial_string2 == 47))
    {
        QFile file1(data1);
        QFile file2(data2);
        if (file1.open(QIODevice::ReadOnly) && file2.open(QIODevice::ReadOnly))
        {
            QByteArray file1_hash = file1.readAll();
            QByteArray result_md5_file1 = QCryptographicHash::hash(file1_hash, QCryptographicHash::Md5);
            QByteArray result_sha1_file1 = QCryptographicHash::hash(file1_hash, QCryptographicHash::Sha1);
            QByteArray result_sha224_file1 = QCryptographicHash::hash(file1_hash, QCryptographicHash::Sha224);
            QByteArray result_sha256_file1 = QCryptographicHash::hash(file1_hash, QCryptographicHash::Sha256);
            QByteArray result_sha384_file1 = QCryptographicHash::hash(file1_hash, QCryptographicHash::Sha384);
            QByteArray result_sha512_file1 = QCryptographicHash::hash(file1_hash, QCryptographicHash::Sha512);

            QByteArray result_sha3224_file1 = QCryptographicHash::hash(file1_hash, QCryptographicHash::Sha3_224);
            QByteArray result_sha3256_file1 = QCryptographicHash::hash(file1_hash, QCryptographicHash::Sha3_256);
            QByteArray result_sha3384_file1 = QCryptographicHash::hash(file1_hash, QCryptographicHash::Sha3_384);
            QByteArray result_sha3512_file1 = QCryptographicHash::hash(file1_hash, QCryptographicHash::Sha3_512);


            QByteArray file2_hash = file2.readAll();
            QByteArray result_md5_file2 = QCryptographicHash::hash(file2_hash, QCryptographicHash::Md5);
            QByteArray result_sha1_file2 = QCryptographicHash::hash(file2_hash, QCryptographicHash::Sha1);
            QByteArray result_sha224_file2 = QCryptographicHash::hash(file2_hash, QCryptographicHash::Sha224);
            QByteArray result_sha256_file2 = QCryptographicHash::hash(file2_hash, QCryptographicHash::Sha256);
            QByteArray result_sha384_file2 = QCryptographicHash::hash(file2_hash, QCryptographicHash::Sha384);
            QByteArray result_sha512_file2 = QCryptographicHash::hash(file2_hash, QCryptographicHash::Sha512);

            QByteArray result_sha3224_file2 = QCryptographicHash::hash(file2_hash, QCryptographicHash::Sha3_224);
            QByteArray result_sha3256_file2 = QCryptographicHash::hash(file2_hash, QCryptographicHash::Sha3_256);
            QByteArray result_sha3384_file2 = QCryptographicHash::hash(file2_hash, QCryptographicHash::Sha3_384);
            QByteArray result_sha3512_file2 = QCryptographicHash::hash(file2_hash, QCryptographicHash::Sha3_512);


            QString final_1_md5 = QString(result_md5_file1.toHex());
            QString final_1_sha1 = QString(result_sha1_file1.toHex());
            QString final_1_sha224 = QString(result_sha224_file1.toHex());
            QString final_1_sha256 = QString(result_sha256_file1.toHex());
            QString final_1_sha384 = QString(result_sha384_file1.toHex());
            QString final_1_sha512 = QString(result_sha512_file1.toHex());

            QString final_1_sha3224 = QString(result_sha3224_file1.toHex());
            QString final_1_sha3256 = QString(result_sha3256_file1.toHex());
            QString final_1_sha3384 = QString(result_sha3384_file1.toHex());
            QString final_1_sha3512 = QString(result_sha3512_file1.toHex());


            QString final_2_md5 = QString(result_md5_file2.toHex());
            QString final_2_sha1 = QString(result_sha1_file2.toHex());
            QString final_2_sha224 = QString(result_sha224_file2.toHex());
            QString final_2_sha256 = QString(result_sha256_file2.toHex());
            QString final_2_sha384 = QString(result_sha384_file2.toHex());
            QString final_2_sha512 = QString(result_sha512_file2.toHex());

            QString final_2_sha3224 = QString(result_sha3224_file2.toHex());
            QString final_2_sha3256 = QString(result_sha3256_file2.toHex());
            QString final_2_sha3384 = QString(result_sha3384_file2.toHex());
            QString final_2_sha3512 = QString(result_sha3512_file2.toHex());

            if (QString::compare(final_1_md5, final_2_md5, Qt::CaseInsensitive) == 0)
            {
                QPalette background(palette());
                background.setColor(QPalette::Background, Qt::green);
                ui->label_4->setAutoFillBackground(true);
                ui->label_4->setPalette(background);
                ui->label_6->setAutoFillBackground(true);
                ui->label_6->setPalette(background);
            }
            else
            {
                QPalette background(palette());
                background.setColor(QPalette::Background, Qt::red);
                ui->label_4->setAutoFillBackground(true);
                ui->label_4->setPalette(background);
                ui->label_6->setAutoFillBackground(true);
                ui->label_6->setPalette(background);
            }
            if (QString::compare(final_1_sha1, final_2_sha1, Qt::CaseInsensitive) == 0)
            {
                QPalette background(palette());
                background.setColor(QPalette::Background, Qt::green);
                ui->label_7->setAutoFillBackground(true);
                ui->label_7->setPalette(background);
                ui->label_9->setAutoFillBackground(true);
                ui->label_9->setPalette(background);
            }
            else
            {
                QPalette background(palette());
                background.setColor(QPalette::Background, Qt::red);
                ui->label_7->setAutoFillBackground(true);
                ui->label_7->setPalette(background);
                ui->label_9->setAutoFillBackground(true);
                ui->label_9->setPalette(background);
            }
            if (QString::compare(final_1_sha224, final_2_sha224, Qt::CaseInsensitive) == 0)
            {
                QPalette background(palette());
                background.setColor(QPalette::Background, Qt::green);
                ui->label_10->setAutoFillBackground(true);
                ui->label_10->setPalette(background);
                ui->label_12->setAutoFillBackground(true);
                ui->label_12->setPalette(background);
            }
            else
            {
                QPalette background(palette());
                background.setColor(QPalette::Background, Qt::red);
                ui->label_10->setAutoFillBackground(true);
                ui->label_10->setPalette(background);
                ui->label_12->setAutoFillBackground(true);
                ui->label_12->setPalette(background);
            }
            if (QString::compare(final_1_sha256, final_2_sha256, Qt::CaseInsensitive) == 0)
            {
                QPalette background(palette());
                background.setColor(QPalette::Background, Qt::green);
                ui->label_13->setAutoFillBackground(true);
                ui->label_13->setPalette(background);
                ui->label_15->setAutoFillBackground(true);
                ui->label_15->setPalette(background);
            }
            else
            {
                QPalette background(palette());
                background.setColor(QPalette::Background, Qt::red);
                ui->label_13->setAutoFillBackground(true);
                ui->label_13->setPalette(background);
                ui->label_15->setAutoFillBackground(true);
                ui->label_15->setPalette(background);
            }
            if (QString::compare(final_1_sha384, final_2_sha384, Qt::CaseInsensitive) == 0)
            {
                QPalette background(palette());
                background.setColor(QPalette::Background, Qt::green);
                ui->label_16->setAutoFillBackground(true);
                ui->label_16->setPalette(background);
                ui->label_18->setAutoFillBackground(true);
                ui->label_18->setPalette(background);
            }
            else
            {
                QPalette background(palette());
                background.setColor(QPalette::Background, Qt::red);
                ui->label_16->setAutoFillBackground(true);
                ui->label_16->setPalette(background);
                ui->label_18->setAutoFillBackground(true);
                ui->label_18->setPalette(background);
            }
            if (QString::compare(final_1_sha512, final_2_sha512, Qt::CaseInsensitive) == 0)
            {
                QPalette background(palette());
                background.setColor(QPalette::Background, Qt::green);
                ui->label_19->setAutoFillBackground(true);
                ui->label_19->setPalette(background);
                ui->label_21->setAutoFillBackground(true);
                ui->label_21->setPalette(background);
            }
            else
            {
                QPalette background(palette());
                background.setColor(QPalette::Background, Qt::red);
                ui->label_19->setAutoFillBackground(true);
                ui->label_19->setPalette(background);
                ui->label_21->setAutoFillBackground(true);
                ui->label_21->setPalette(background);
            }
            if (QString::compare(final_1_sha3224, final_2_sha3224, Qt::CaseInsensitive) == 0)
            {
                QPalette background(palette());
                background.setColor(QPalette::Background, Qt::green);
                ui->label_25->setAutoFillBackground(true);
                ui->label_25->setPalette(background);
                ui->label_27->setAutoFillBackground(true);
                ui->label_27->setPalette(background);
            }
            else
            {
                QPalette background(palette());
                background.setColor(QPalette::Background, Qt::red);
                ui->label_25->setAutoFillBackground(true);
                ui->label_25->setPalette(background);
                ui->label_27->setAutoFillBackground(true);
                ui->label_27->setPalette(background);
            }
            if (QString::compare(final_1_sha3256, final_2_sha3256, Qt::CaseInsensitive) == 0)
            {
                QPalette background(palette());
                background.setColor(QPalette::Background, Qt::green);
                ui->label_28->setAutoFillBackground(true);
                ui->label_28->setPalette(background);
                ui->label_30->setAutoFillBackground(true);
                ui->label_30->setPalette(background);
            }
            else
            {
                QPalette background(palette());
                background.setColor(QPalette::Background, Qt::red);
                ui->label_28->setAutoFillBackground(true);
                ui->label_28->setPalette(background);
                ui->label_30->setAutoFillBackground(true);
                ui->label_30->setPalette(background);
            }
            if (QString::compare(final_1_sha3384, final_2_sha3384, Qt::CaseInsensitive) == 0)
            {
                QPalette background(palette());
                background.setColor(QPalette::Background, Qt::green);
                ui->label_31->setAutoFillBackground(true);
                ui->label_31->setPalette(background);
                ui->label_33->setAutoFillBackground(true);
                ui->label_33->setPalette(background);
            }
            else
            {
                QPalette background(palette());
                background.setColor(QPalette::Background, Qt::red);
                ui->label_31->setAutoFillBackground(true);
                ui->label_31->setPalette(background);
                ui->label_33->setAutoFillBackground(true);
                ui->label_33->setPalette(background);
            }
            if (QString::compare(final_1_sha3512, final_2_sha3512, Qt::CaseInsensitive) == 0)
            {
                QPalette background(palette());
                background.setColor(QPalette::Background, Qt::green);
                ui->label_34->setAutoFillBackground(true);
                ui->label_34->setPalette(background);
                ui->label_36->setAutoFillBackground(true);
                ui->label_36->setPalette(background);
            }
            else
            {
                QPalette background(palette());
                background.setColor(QPalette::Background, Qt::red);
                ui->label_34->setAutoFillBackground(true);
                ui->label_34->setPalette(background);
                ui->label_36->setAutoFillBackground(true);
                ui->label_36->setPalette(background);
            }
        }
    }
}

/*
 * Funcio per pintar VERD/VERMELL
 */
