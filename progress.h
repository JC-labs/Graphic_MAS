#ifndef PROGRESS_H
#define PROGRESS_H

#include <QtWidgets>

class Progress : public QWidget
{
    Q_OBJECT

private:
    QWidget w;
    QProgressBar b;
    QLabel l1,l2;
    QVBoxLayout v;
    double min, max, st, cur;

public:
    explicit Progress(QWidget *parent = 0);

signals:

public:
    void start(double tmin, double tmax, double tstep, QApplication* app);
    void step();
    void finish();

};

#endif // PROGRESS_H
