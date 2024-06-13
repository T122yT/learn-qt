#include "widget.h"

#include <QApplication>
#include"login.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Widget w;
    //w.show();

    LogIn log;
    log.show();
    return a.exec();
}
