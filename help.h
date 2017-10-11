#ifndef HELP_H
#define HELP_H

#include <QtWidgets>

class About : public QWidget
{
    Q_OBJECT
public:
    About(QWidget *parent = 0);

private:
    QWidget w;
    QVBoxLayout v;
    QLabel l[9];

public slots:
    void open();
};


class Help : public QWidget
{
    Q_OBJECT
public:
    explicit Help(QWidget *parent = 0);

private:
    QWidget w;
    QWidget i, r;
    QVBoxLayout v;
    QHBoxLayout h;
    QLabel l;
    QPushButton b1, b2, b0;

signals:

public slots:
    void open();
    void inter();
    void m();
    void start();

};

#endif // HELP_H
