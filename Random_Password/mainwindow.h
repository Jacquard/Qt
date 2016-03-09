#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGlobal>

#include <QString>
#include <QMessageBox>
#include <QCryptographicHash>
#include <time.h>
#include <qmath.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    QString cadena(const int);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
