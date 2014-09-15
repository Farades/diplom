#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "comdialog.h"

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->disconnectButton->setEnabled(false);
    ui->sendButton->setEnabled(false);
    ui->lineEdit->setEnabled(false);

    serial   = new QSerialPort(this);
    settings = new ComDialog;

    initActionsConnections();

    connect(serial, SIGNAL(readyRead()), this, SLOT(readData()));
    connect(this, SIGNAL(getData(QByteArray)), this, SLOT(writeData(QByteArray)));
}

void MainWindow::writeData(const QByteArray &data)
{
    qDebug() << "Sending:" << data;
    serial->write(data);
}

void MainWindow::readData()
{
    QByteArray data = serial->readAll();
    ui->plainTextEdit->insertPlainText(QString(data));
}

void MainWindow::readFromLineEdit()
{
    QByteArray text = ui->lineEdit->text().toLocal8Bit();
    ui->lineEdit->setText("");
    emit getData(text);
}

void MainWindow::openSerialPort()
{
    ComDialog::Settings p = settings->settings();
    serial->setPortName(p.name);
    serial->setBaudRate(p.baudRate);
    serial->setDataBits(p.dataBits);
    serial->setParity(p.parity);
    serial->setStopBits(p.stopBits);
    serial->setFlowControl(p.flowControl);
    if (serial->open(QIODevice::ReadWrite)) {
        ui->statusBar->showMessage(tr("Connected to %1 : %2, %3, %4, %5, %6")
                                   .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
                                   .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));
        qDebug() << "Connected to" << p.name;
    } else {
        QMessageBox::critical(this, tr("Error"), serial->errorString());

        ui->statusBar->showMessage(tr("Open error"));
    }
    ui->sendButton->setEnabled(true);
    ui->connectButton->setEnabled(false);
    ui->disconnectButton->setEnabled(true);
    ui->lineEdit->setEnabled(true);
}

void MainWindow::closeSerialPort()
{
    serial->close();
    ui->sendButton->setEnabled(false);
    ui->connectButton->setEnabled(true);
    ui->disconnectButton->setEnabled(false);
    ui->lineEdit->setEnabled(false);
    ui->statusBar->showMessage(tr("Disconnected"));
    qDebug() << "Disconnect from com-port";
}

void MainWindow::initActionsConnections()
{
    connect(ui->actionConfigure, SIGNAL(triggered()), settings, SLOT(show()));
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(close()));

    connect(ui->connectButton, SIGNAL(clicked()),
            this, SLOT(openSerialPort()));
    connect(ui->disconnectButton, SIGNAL(clicked()),
            this, SLOT(closeSerialPort()));

    connect(ui->sendButton, SIGNAL(clicked()),
            this, SLOT(readFromLineEdit()));
}

MainWindow::~MainWindow()
{
    delete settings;
    delete ui;
}
