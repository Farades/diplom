#ifndef COMDIALOG_H
#define COMDIALOG_H

#include <QDialog>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

QT_USE_NAMESPACE

QT_BEGIN_NAMESPACE

namespace Ui {
class ComDialog;
}

QT_END_NAMESPACE

class ComDialog : public QDialog
{
    Q_OBJECT

public:
    struct Settings {
        QString name;
        qint32 baudRate;
        QString stringBaudRate;
        QSerialPort::DataBits dataBits;
        QString stringDataBits;
        QSerialPort::Parity parity;
        QString stringParity;
        QSerialPort::StopBits stopBits;
        QString stringStopBits;
        QSerialPort::FlowControl flowControl;
        QString stringFlowControl;
        bool localEchoEnabled;
    };

    explicit ComDialog(QWidget *parent = 0);
    ~ComDialog();

    Settings settings() const;

private slots:
    void showPortInfo(int idx);
    void apply();
    void updateCOM();

private:
    void fillPortsParameters();
    void fillPortsInfo();
    void updateSettings();

private:
    Ui::ComDialog *ui;
    Settings currentSettings;
};

#endif // COMDIALOG_H
