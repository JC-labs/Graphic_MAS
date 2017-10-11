CONFIG += qt
QT = widgets opengl
win32:RC_ICONS += icon-o.ico

HEADERS += \
    data.h \
    datas.h \
    graficwidget.h \
    mainwindow.h \
    progress.h \
    help.h

SOURCES += \
    data.cpp \
    datas.cpp \
    graficwidget.cpp \
    mainwindow.cpp \
    progress.cpp \
    main.cpp \
    help.cpp

RESOURCES += \
    res.qrc

