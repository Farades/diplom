#ifndef APPWIDGET_H
#define APPWIDGET_H

#include <QWidget>
#include <QTabWidget>

class AppWidget : public QWidget {
    Q_OBJECT

private:
    QTabWidget tab;
    void tabCreate();

public:
    AppWidget(QWidget* pwgt = 0);
};

#endif // APPWIDGET_H
