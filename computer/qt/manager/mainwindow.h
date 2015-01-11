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
class dronesSetting;
class QTableWidget;
class ControlParser;

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
      void readFromLineEdit();
      void writeData(const QByteArray &data);
      void readData();

      void changeDronesTable();
      void changeDronesTableSize();

private:
    void initActionsConnections();
    void initDronesTable();

private:
    Ui::MainWindow *ui;
    QTableWidget* dronesTable;
    Console *console;
    ComDialog *settings;
    dronesSetting *dsettings;
    QSerialPort *serial;
    ControlParser *cparser;

    bool connectToCom;
};

#endif // MAINWINDOW_H
