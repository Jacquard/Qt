#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QEvent>
#include <QHBoxLayout>
#include <QLabel>
#include <QLayout>
#include <QLineEdit>
#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include <QTabBar>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QWidget>

#include "distanciadialog.h"
#include "tempsdialog.h"

#include <math.h>

namespace Ui {
class MainWindow;
}

class Event;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool eventFilter(QObject *watched, QEvent *event);
    float tempsARebre(int hores, int minuts, int segons);

private:
    Ui::MainWindow *ui;
    void setupTabs();
    TempsDialog *dialogTemps;
    DistanciaDialog *dialogDistancia;

private slots:
    void onTabChanged(int index);
    void setLaiAut();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
