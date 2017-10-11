#include "graficwidget.h"

GraficWidget::GraficWidget(QWidget *parent) : QGLWidget(parent)
{
    pl = -10000;
    pr =  10000;
    pt =  6667;
    pb = -6667;

    ts = 50;

    f1 = false;
    f2 = false;
    s1 = 50;
    s2 = 50;
}

GraficWidget::GraficWidget(QLineEdit *e1, QLineEdit *e2, QLineEdit *e3, QLineEdit *e4,
                           QWidget *parent) : f(e1), d1(e2), d2(e3), st(e4), QGLWidget(parent)
{
    pl = -10000;
    pr =  10000;
    pt =  6667;
    pb = -6667;

    ts = 50;

    f1 = false;
    f2 = false;
    s1 = 50;
    s2 = 50;
}


void GraficWidget::initializeGL()
{
    glClearColor(1,1,1,1);
}

void GraficWidget::resizeGL (int w, int h)
{
    tw=w; th=h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, (GLint)w, (GLint)h);
    glOrtho(pl, pr, pt, pb, -1, 1);
}

void GraficWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_LINES);

    glColor3f(0.9,0.9,0.9);
    if (f1)
    {
        for (int i = 0; i <  3000; i+=s1)
        {
            glVertex2f(i*ts,-3000*ts);
            glVertex2f(i*ts, 3000*ts);
        }
        for (int i = 0; i > -3000; i-=s1)
        {
            glVertex2f(i*ts,-3000*ts);
            glVertex2f(i*ts, 3000*ts);
        }
    }

    if (f2)
    {
        for (int i = 0; i <  3000; i+=s2)
        {
            glVertex2f(-3000*ts,i*ts);
            glVertex2f( 3000*ts,i*ts);
        }
        for (int i = 0; i > -3000; i-=s2)
        {
            glVertex2f(-3000*ts,i*ts);
            glVertex2f( 3000*ts,i*ts);
        }
    }
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.7, 0.7, 0.7);
    glVertex2f(-100000, 0);
    glVertex2f(100000, 0);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0, -100000);
    glVertex2f(0, 100000);
    glEnd();

    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < v.size(); i++)
    {
        glColor3f(0,0,0);
        glVertex2f(v[i].Gx()*10*ts,-(v[i].Gy())*10*ts);
    }
    glEnd();
}

void GraficWidget::build()
{
    v.clear();

    Datas d = f->text().toStdString();
    p.start(num(d1->text().toStdString()), num(d2->text().toStdString()),
            num(st->text().toStdString()), app);

    double di1 = num(d1->text().toStdString());
    double di2 = num(d2->text().toStdString());
    double sti = num(st->text().toStdString());
    if (di1 == 0 && di2 == 0 && sti == 0)
    {
        di1 = 1;
        di2 = 1;
        sti = 1;
    }

    for (double i = di1; i <= di2; i += sti)
    {
        v.push_back(*(new point(i,d.solve(i))));
        p.step();
    }
    p.finish();
}

double GraficWidget::num(string ss)
{
    double r = 0;
    bool p = false;
    bool m = false;
    double pn = 0.0;
    for (unsigned int i = 0; i < ss.size(); i++)
    {
        if (ss[i] == '.')
        {
            p = true;
            pn = 0.1;
        } else
        if (ss[i] == '-')
            m = true;
        else
        if (ss[i] == '1' || ss[i] == '2' || ss[i] == '3' || ss[i] == '4' || ss[i] == '5'
         || ss[i] == '6' || ss[i] == '7' || ss[i] == '8' || ss[i] == '9' || ss[i] == '0')
        {
            if(!m)
                if (!p)
                    r = 10*r + num(ss[i]);
                else
                {
                    r = r + num(ss[i])*pn;
                    pn/=10;
                }
            else
                if (!p)
                    r = 10*r - num(ss[i]);
                else
                {
                    r = r - num(ss[i])*pn;
                    pn/=10;
                }
        }
    }
    return r;
}

double GraficWidget::num(char tc)
{
    switch (tc)
    {
    case '0':
        return 0.0;
    case '1':
        return 1.0;
    case '2':
        return 2.0;
    case '3':
        return 3.0;
    case '4':
        return 4.0;
    case '5':
        return 5.0;
    case '6':
        return 6.0;
    case '7':
        return 7.0;
    case '8':
        return 8.0;
    case '9':
        return 9.0;
    default:
        return 0.0;
    }
}

void GraficWidget::mousePressEvent(QMouseEvent* e )
{
    mP = e->pos();
}


void GraficWidget::mouseMoveEvent(QMouseEvent* e)
{
    pX = (GLfloat)(e->x() - mP.x());
    pY = (GLfloat)(e->y() - mP.y());

    pl -= pX*(10);
    pr -= pX*(10);
    pt -= pY*(10);
    pb -= pY*(10);

    resizeGL(tw,th);
    updateGL();

    mP = e->pos();
}


void GraficWidget::mouseDoubleClickEvent(QMouseEvent* e )
{
    pl = -10000;
    pr =  10000;
    pt =  6667;
    pb = -6667;

    resizeGL(tw,th);
    updateGL();

    mP = e->pos();
}

void GraficWidget::init(QApplication* ap)
{
    app = ap;
}

void GraficWidget::scale(int i)
{
    ts = static_cast<double>(i);
    ts /= 10;
    ts = (ts == 0) ? 0.1 : ((ts < 0) ? 1/(-ts) : ts);

    updateGL();
}

void GraficWidget::setF1(bool f)
{
    f1 = f;

    updateGL();
}

void GraficWidget::setF2(bool f)
{
    f2 = f;

    updateGL();
}

void GraficWidget::setS1(int s)
{
    s1 = static_cast<double>(s);
    s1 = (s1 == 0) ? 1.0 : ((s1 < 0) ? 1/(-s1) : s1);

    updateGL();
}

void GraficWidget::setS2(int s)
{
    s2 = static_cast<double>(s);
    s2 = (s2 == 0) ? 1.0 : ((s2 < 0) ? 1/(-s2) : s2);

    updateGL();
}
