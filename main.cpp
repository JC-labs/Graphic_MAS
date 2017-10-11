#include "Datas.h"
#include <QtWidgets>
#include "mainwindow.h"

int main(int arg1, char** arg2)
{
    QApplication app(arg1,arg2);
    MainWindow w;
    w.init(&app);
    w.showMaximized();
    return app.exec();
}
