#ifndef TEMPSDIALOG_H
#define TEMPSDIALOG_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class TempsDialog;
}

class TempsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TempsDialog(QWidget *parent = 0);
    ~TempsDialog();
    int hola();

private slots:
    float on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::TempsDialog *ui;
};

#endif // TEMPSDIALOG_H
