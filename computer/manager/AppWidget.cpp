#include "AppWidget.h"
#include <QtGui>

AppWidget::AppWidget(QWidget* pwgt)
{

}

void AppWidget::tabCreate()
{
    QStringList lst;
    lst << "Linux" << "Windows" << "MacOS" << "OS32";

    foreach (QString str, lst) {
        tab.addTab(QLabel(str, &tab), str);
    }
}
