#include <QtGui>
#include "AppWidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AppWidget app;

    app.show();

    return a.exec();
}
