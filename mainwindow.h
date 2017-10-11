#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include "graficwidget.h"
#include "help.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

    //void show();
    void showMaximized();
    void init(QApplication* ap);


private:
    QApplication *app;
    GraficWidget *gw;
    QWidget window;
    QFont *font;

    QLabel l1;
    QLineEdit e1;
    QLabel l2;
    QLineEdit e2;
    QLabel l3;
    QLineEdit e3;
    QLabel l4;
    QLabel l5;
    QLineEdit e5;
    QPushButton b1;
    QHBoxLayout hl1;

    QSlider s1,s2,s3;
    QCheckBox f1,f2;
    QLabel ls1,ls2;

    QHBoxLayout hl2;
    QHBoxLayout hl3;

    QVBoxLayout vl2;
    QVBoxLayout sl1,sl2;

    QWidget t1;
    QTabWidget t;

    QVBoxLayout vl1;

    QIcon Iicon, Oicon;

    About a;
    Help h;
    QPushButton help;
    QPushButton about;

public slots:
    void change1(int i);
    void change2(int i);
};

#endif // MAINWINDOW_H
