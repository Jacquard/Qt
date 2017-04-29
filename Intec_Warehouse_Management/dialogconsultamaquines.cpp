#include "dialogconsultamaquines.h"
#include "ui_dialogconsultamaquines.h"

DialogConsultaMaquines::DialogConsultaMaquines(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogConsultaMaquines)
{
    ui->setupUi(this);
    ui->lineEdit->setInputMask( "#>A###" );
    //connect(le, SIGNAL(textEdited(const QString &)), SLOT(toUpper(const QString &)));
}

DialogConsultaMaquines::~DialogConsultaMaquines()
{
    delete ui;
}

/*
void Test::toUpper(const QString &text)
{
    QLineEdit *le = qobject_cast<QLineEdit *>(sender());
    if (!le)
        return;
    le->setText(text.toUpper());
}
*/

void DialogConsultaMaquines::on_pushButton_clicked()
{
    /*
     * Crear funció que busqui a la base de dades i retorni els components que la integraven
     */
}
