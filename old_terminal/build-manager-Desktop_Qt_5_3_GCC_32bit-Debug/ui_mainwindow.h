/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionConfigure;
    QAction *actionExit;
    QAction *actionDrone;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QGridLayout *gridLayout;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *dronesTable;
    QPushButton *refreshDroneTableSize;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QPlainTextEdit *plainTextEdit;
    QPushButton *connectButton;
    QPushButton *disconnectButton;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *sendButton;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(653, 509);
        actionConfigure = new QAction(MainWindow);
        actionConfigure->setObjectName(QStringLiteral("actionConfigure"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionDrone = new QAction(MainWindow);
        actionDrone->setObjectName(QStringLiteral("actionDrone"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout = new QGridLayout(tab_3);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        dronesTable = new QTableWidget(tab_2);
        dronesTable->setObjectName(QStringLiteral("dronesTable"));

        verticalLayout_3->addWidget(dronesTable);

        refreshDroneTableSize = new QPushButton(tab_2);
        refreshDroneTableSize->setObjectName(QStringLiteral("refreshDroneTableSize"));

        verticalLayout_3->addWidget(refreshDroneTableSize);

        tabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        plainTextEdit = new QPlainTextEdit(tab);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        verticalLayout_2->addWidget(plainTextEdit);

        connectButton = new QPushButton(tab);
        connectButton->setObjectName(QStringLiteral("connectButton"));

        verticalLayout_2->addWidget(connectButton);

        disconnectButton = new QPushButton(tab);
        disconnectButton->setObjectName(QStringLiteral("disconnectButton"));

        verticalLayout_2->addWidget(disconnectButton);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        sendButton = new QPushButton(tab);
        sendButton->setObjectName(QStringLiteral("sendButton"));

        horizontalLayout->addWidget(sendButton);


        verticalLayout_2->addLayout(horizontalLayout);

        tabWidget->addTab(tab, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 653, 19));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_File->menuAction());
        menu_File->addAction(actionConfigure);
        menu_File->addAction(actionDrone);
        menu_File->addSeparator();
        menu_File->addAction(actionExit);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Control system group drones - Matcepura A.M.", 0));
        actionConfigure->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\275\321\204\320\270\320\263\321\203\321\200\320\260\321\206\320\270\321\217 \321\201\320\276\320\265\320\264\320\270\320\275\320\265\320\275\320\270\321\217", 0));
        actionExit->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", 0));
        actionDrone->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 \320\263\321\200\321\203\320\277\320\277\320\270\321\200\320\276\320\262\320\272\320\270", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "\320\240\320\260\320\261\320\276\321\202\320\260 \321\201 \320\221\320\241", 0));
        refreshDroneTableSize->setText(QApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214 \321\200\320\260\320\267\320\274\320\265\321\200", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\320\234\320\276\320\275\320\270\321\202\320\276\321\200\320\270\320\275\320\263 \320\263\321\200\321\203\320\277\320\277\321\213", 0));
        connectButton->setText(QApplication::translate("MainWindow", "Connect", 0));
        disconnectButton->setText(QApplication::translate("MainWindow", "Disconnect", 0));
        sendButton->setText(QApplication::translate("MainWindow", "Send", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\320\242\320\265\321\200\320\274\320\270\320\275\320\260\320\273", 0));
        menu_File->setTitle(QApplication::translate("MainWindow", "\320\234\320\265\320\275\321\216", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
