#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/QtGlobal>

#include <QMainWindow>

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

QT_BEGIN_NAMESPACE

namespace Ui {
class MainWindow;
}

QT_END_NAMESPACE

class Console;
class ComDialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:
    void getData(const QByteArray &data);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
      void openSerialPort();
      void closeSerialPort();
//    void about();
      void readFromLineEdit();
      void writeData(const QByteArray &data);
      void readData();

//    void handleError(QSerialPort::SerialPortError error);

private:
    void initActionsConnections();

private:
    Ui::MainWindow *ui;
    Console *console;
    ComDialog *settings;
    QSerialPort *serial;
};

#endif // MAINWINDOW_H
