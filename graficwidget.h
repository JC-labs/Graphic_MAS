#ifndef GRAFICWIDGET_H
#define GRAFICWIDGET_H

#include <QGLWidget>
#include <QtWidgets>
#include "Datas.h"
#include "progress.h"

class GraficWidget : public QGLWidget
{
    Q_OBJECT

private:
    QApplication*  app;
    QVector<point> v;
    QLineEdit      *f, *d1, *d2, *st;
    Progress       p;
    GLdouble       pl,pr,pt,pb;
    GLdouble       pX;
    GLdouble       pY;
    QPoint         mP;
    int            tw,th;
    double         ts;
    bool           f1,f2;
    int            s1,s2;

public:
    explicit GraficWidget(QWidget *parent = 0);
    explicit GraficWidget(QLineEdit* e1, QLineEdit* e2, QLineEdit* e3, QLineEdit* e4,
                          QWidget *parent = 0);

    void init(QApplication* ap);

    double num(string ss);
    double num(char tc);


protected:
    virtual void initializeGL( );
    virtual void resizeGL (int w, int h);
    virtual void paintGL ( );


    virtual void mousePressEvent(QMouseEvent* e );
    virtual void mouseMoveEvent (QMouseEvent* e );
    virtual void mouseDoubleClickEvent(QMouseEvent* e );

signals:

public slots:
    void build();
    void scale(int);
    void setF1(bool);
    void setF2(bool);
    void setS1(int s);
    void setS2(int s);

};

#endif // GRAFICWIDGET_H
