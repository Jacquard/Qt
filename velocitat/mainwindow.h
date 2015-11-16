#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QObject>
#include <QWidget>
#include <QString>
#include <QtMath>
#include "dialog.h"

/*
 * Incloem math.h per a poder utilitzar fmodf
 */
#include <math.h>
#include <time.h>

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
    void on_actionQuant_a_triggered();

private:
    Ui::MainWindow *ui;
    Dialog *mDialog;
};

#endif // MAINWINDOW_H
