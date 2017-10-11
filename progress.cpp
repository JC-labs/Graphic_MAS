#include "progress.h"

Progress::Progress(QWidget *parent) :
    QWidget(parent)
{
    l1.setText("Виконується операція побудови графіка. Будь ласка почекайте. \n"
               "Якщо побудова триває занадто довго спробуйте зменшити область значень "
               "і(або) крок обчислень.");
    v.addWidget(&l1);
    v.addWidget(&b);
    w.setLayout(&v);
}

void Progress::start(double tmin, double tmax, double tstep, QApplication *app)
{
    b.setRange(min = tmin, max = tmax);
    st = tstep;
    b.setValue(cur = tmin);
    w.show();
    app->processEvents();
}

void Progress::step()
{
    b.setValue(cur+=st);
    w.update();
}

void Progress::finish()
{
    w.hide();
}
