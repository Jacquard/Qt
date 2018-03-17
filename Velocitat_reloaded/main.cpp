#include "mainwindow.h"
#include <QApplication>
#include <QString>
#include <QSize>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle(QString::fromUtf8("Velocitat"));
/*
    QWidget *centralWidget = new QWidget;
    QTabWidget *tabs = new QTabWidget(centralWidget);

    QVBoxLayout *vboxlay = new QVBoxLayout;
    QSpacerItem *spacer = new QSpacerItem(645,455, QSizePolicy::Expanding, QSizePolicy::Expanding);

//    centralWidget->setLayout(vboxlay);



    tabs->addTab(new QWidget(),"Metres");
    tabs->addTab(new QWidget(),"Milles");
    int numTabs = tabs->count();

    QPushButton *boto1 = new QPushButton("1");
    QLineEdit *edit1 = new QLineEdit;


    vboxlay->addWidget(boto1);
    vboxlay->addWidget(edit1);

    tabs->widget(0)->setLayout(vboxlay);

    //tabs->widget(0)->layout()

    w.setCentralWidget(centralWidget);
    */
    w.show();

    return a.exec();
}
