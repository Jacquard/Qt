#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QFileInfo>
#include <QDate>
#include <QDateTime>
#include <QHeaderView>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    void info(QString data);

private:
    Ui::Dialog *ui;

    void InfoArxiu(QString Data);
    void Hashes(QString Data);

    enum Columna
    {
        Info, Valor
    };

private slots:
};

#endif // DIALOG_H
