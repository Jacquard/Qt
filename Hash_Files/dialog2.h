#ifndef DIALOG2_H
#define DIALOG2_H

#include <QDialog>
#include <QFile>
#include <QMessageBox>
#include <QCryptographicHash>
#include <QThread>

namespace Ui {
class Dialog2;
}

class Dialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog2(QWidget *parent = 0);
    ~Dialog2();
    void collision(QString data1, QString data2);

private:
    Ui::Dialog2 *ui;
};

#endif // DIALOG2_H
