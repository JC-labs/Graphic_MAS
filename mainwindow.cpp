#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{

    font = new QFont("Arial", 10);
    window.setFont(*font);

    Iicon.addFile(":/icon/icon-i.ico");
    window.setWindowIcon(Iicon);
    app->setWindowIcon(Iicon);
    app->setApplicationName("Графік 0.7");
    app->setApplicationVersion("0.7");

    l1.setText("f(x) = ");
    l2.setText("D(f) = [");
    l3.setText(";");
    l4.setText("]");
    l5.setText("Крок:");
    b1.setText("Побудувати");

    help.setText("Help");
    //help.setMaximumWidth(40);
    about.setText("About");
    //about.setMaximumWidth(40);

    hl1.setSpacing(0);
    hl1.addWidget(&l1,0);
    hl1.addWidget(&e1,20);
    hl1.addSpacing(15);
    hl1.addWidget(&l2,0);
    hl1.addWidget(&e2,2);
    hl1.addWidget(&l3,0);
    hl1.addWidget(&e3,2);
    hl1.addWidget(&l4,0);
    hl1.addSpacing(15);
    hl1.addWidget(&l5,0);
    hl1.addWidget(&e5,2);
    hl1.addSpacing(15);
    hl1.addWidget(&b1,3);

    s3.setOrientation(Qt::Horizontal);
    s3.setRange(100,1000);
    s3.setValue(551);

    s1.setRange(0,100);
    s1.setValue(50);
    s2.setRange(0,100);
    s2.setValue(50);

    ls1.setText("5.0");
    ls2.setText("5.0");

    gw = new GraficWidget(&e1,&e2,&e3,&e5);
    gw->init(app);

    sl1.addWidget(&f1);
    sl1.addWidget(&s1);
    sl1.addWidget(&ls1);

    sl2.addWidget(&f2);
    sl2.addWidget(&s2);
    sl2.addWidget(&ls2);

    hl2.addLayout(&sl1,0);
    hl2.addWidget(gw,20);
    hl2.addLayout(&sl2,0);

    hl3.addWidget(&help,0);
    hl3.addWidget(&s3,20);
    hl3.addWidget(&about,0);

    vl2.addLayout(&hl2);
    vl2.addLayout(&hl3);

    t1.setLayout(&vl2);
    t.addTab(&t1, "Графік");

    vl1.addLayout(&hl1);
    vl1.addWidget(&t);

    window.setLayout(&vl1);

    connect(&b1, SIGNAL(clicked()), gw, SLOT(build()));
    connect(&s3, SIGNAL(valueChanged(int)), gw, SLOT(scale(int)));
    connect(&f1, SIGNAL(clicked(bool)), gw, SLOT(setF1(bool)));
    connect(&f2, SIGNAL(clicked(bool)), gw, SLOT(setF2(bool)));
    connect(&s1, SIGNAL(valueChanged(int)), gw, SLOT(setS1(int)));
    connect(&s2, SIGNAL(valueChanged(int)), gw, SLOT(setS2(int)));
    connect(&s1, SIGNAL(valueChanged(int)), this, SLOT(change1(int)));
    connect(&s2, SIGNAL(valueChanged(int)), this, SLOT(change2(int)));
    connect(&about, SIGNAL(clicked()), &a, SLOT(open()));
    connect(&help, SIGNAL(clicked()), &h, SLOT(open()));
}

/*
void MainWindow::show()
{

}
*/
void MainWindow::showMaximized()
{
    window.showMaximized();
}

void MainWindow::init(QApplication* ap)
{
    app = ap;
}

void MainWindow::change1(int i)
{
    double i1 = static_cast<double>(i);
    i1 = (i1 == 0) ? 1 : ((i1 < 0) ? 1/(-i1) : i1);
    ls1.setNum(i1/10);
}

void MainWindow::change2(int i)
{
    double i1 = static_cast<double>(i);
    i1 = (i1 == 0) ? 1 : ((i1 < 0) ? 1/(-i1) : i1);
    ls2.setNum(i1/10);
}
