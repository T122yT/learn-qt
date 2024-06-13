#include "qcustomplotwidget.h"
#include "qcustomplot.h"


#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qCustomPlotWidget w;
    w.show();
    return a.exec();
}
