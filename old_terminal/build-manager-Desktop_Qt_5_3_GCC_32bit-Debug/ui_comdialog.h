/********************************************************************************
** Form generated from reading UI file 'comdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMDIALOG_H
#define UI_COMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ComDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *selectBox;
    QGridLayout *gridLayout;
    QLabel *serialNumberLabel;
    QLabel *manufacturerLabel;
    QLabel *locationLabel;
    QLabel *vendorLabel;
    QComboBox *comPortSelectBox;
    QLabel *descriptionLabel;
    QLabel *productLabel;
    QGroupBox *parametersBox;
    QGridLayout *gridLayout_2;
    QComboBox *baudRateBox;
    QComboBox *stopBitsBox;
    QLabel *baudRateLabel;
    QComboBox *dataBitsBox;
    QComboBox *parityBox;
    QComboBox *flowControlBox;
    QLabel *dataBitsLabel;
    QLabel *parityLabel;
    QLabel *stopBitsLabel;
    QLabel *flowControlLabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *updateButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *saveButton;

    void setupUi(QDialog *ComDialog)
    {
        if (ComDialog->objectName().isEmpty())
            ComDialog->setObjectName(QStringLiteral("ComDialog"));
        ComDialog->resize(407, 374);
        verticalLayout = new QVBoxLayout(ComDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        selectBox = new QGroupBox(ComDialog);
        selectBox->setObjectName(QStringLiteral("selectBox"));
        gridLayout = new QGridLayout(selectBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        serialNumberLabel = new QLabel(selectBox);
        serialNumberLabel->setObjectName(QStringLiteral("serialNumberLabel"));

        gridLayout->addWidget(serialNumberLabel, 3, 0, 1, 1);

        manufacturerLabel = new QLabel(selectBox);
        manufacturerLabel->setObjectName(QStringLiteral("manufacturerLabel"));

        gridLayout->addWidget(manufacturerLabel, 2, 0, 1, 1);

        locationLabel = new QLabel(selectBox);
        locationLabel->setObjectName(QStringLiteral("locationLabel"));

        gridLayout->addWidget(locationLabel, 4, 0, 1, 1);

        vendorLabel = new QLabel(selectBox);
        vendorLabel->setObjectName(QStringLiteral("vendorLabel"));

        gridLayout->addWidget(vendorLabel, 5, 0, 1, 1);

        comPortSelectBox = new QComboBox(selectBox);
        comPortSelectBox->setObjectName(QStringLiteral("comPortSelectBox"));

        gridLayout->addWidget(comPortSelectBox, 0, 0, 1, 1);

        descriptionLabel = new QLabel(selectBox);
        descriptionLabel->setObjectName(QStringLiteral("descriptionLabel"));

        gridLayout->addWidget(descriptionLabel, 1, 0, 1, 1);

        productLabel = new QLabel(selectBox);
        productLabel->setObjectName(QStringLiteral("productLabel"));

        gridLayout->addWidget(productLabel, 6, 0, 1, 1);


        horizontalLayout_2->addWidget(selectBox);

        parametersBox = new QGroupBox(ComDialog);
        parametersBox->setObjectName(QStringLiteral("parametersBox"));
        gridLayout_2 = new QGridLayout(parametersBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        baudRateBox = new QComboBox(parametersBox);
        baudRateBox->setObjectName(QStringLiteral("baudRateBox"));

        gridLayout_2->addWidget(baudRateBox, 0, 1, 1, 1);

        stopBitsBox = new QComboBox(parametersBox);
        stopBitsBox->setObjectName(QStringLiteral("stopBitsBox"));

        gridLayout_2->addWidget(stopBitsBox, 3, 1, 1, 1);

        baudRateLabel = new QLabel(parametersBox);
        baudRateLabel->setObjectName(QStringLiteral("baudRateLabel"));

        gridLayout_2->addWidget(baudRateLabel, 0, 0, 1, 1);

        dataBitsBox = new QComboBox(parametersBox);
        dataBitsBox->setObjectName(QStringLiteral("dataBitsBox"));

        gridLayout_2->addWidget(dataBitsBox, 1, 1, 1, 1);

        parityBox = new QComboBox(parametersBox);
        parityBox->setObjectName(QStringLiteral("parityBox"));

        gridLayout_2->addWidget(parityBox, 2, 1, 1, 1);

        flowControlBox = new QComboBox(parametersBox);
        flowControlBox->setObjectName(QStringLiteral("flowControlBox"));

        gridLayout_2->addWidget(flowControlBox, 4, 1, 1, 1);

        dataBitsLabel = new QLabel(parametersBox);
        dataBitsLabel->setObjectName(QStringLiteral("dataBitsLabel"));

        gridLayout_2->addWidget(dataBitsLabel, 1, 0, 1, 1);

        parityLabel = new QLabel(parametersBox);
        parityLabel->setObjectName(QStringLiteral("parityLabel"));

        gridLayout_2->addWidget(parityLabel, 2, 0, 1, 1);

        stopBitsLabel = new QLabel(parametersBox);
        stopBitsLabel->setObjectName(QStringLiteral("stopBitsLabel"));

        gridLayout_2->addWidget(stopBitsLabel, 3, 0, 1, 1);

        flowControlLabel = new QLabel(parametersBox);
        flowControlLabel->setObjectName(QStringLiteral("flowControlLabel"));

        gridLayout_2->addWidget(flowControlLabel, 4, 0, 1, 1);


        horizontalLayout_2->addWidget(parametersBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        updateButton = new QPushButton(ComDialog);
        updateButton->setObjectName(QStringLiteral("updateButton"));

        horizontalLayout->addWidget(updateButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        saveButton = new QPushButton(ComDialog);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        horizontalLayout->addWidget(saveButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ComDialog);

        QMetaObject::connectSlotsByName(ComDialog);
    } // setupUi

    void retranslateUi(QDialog *ComDialog)
    {
        ComDialog->setWindowTitle(QApplication::translate("ComDialog", "Configure connect", 0));
        selectBox->setTitle(QApplication::translate("ComDialog", "\320\222\321\213\320\261\320\276\321\200 COM-\320\277\320\276\321\200\321\202\320\260:", 0));
        serialNumberLabel->setText(QApplication::translate("ComDialog", "TextLabel", 0));
        manufacturerLabel->setText(QApplication::translate("ComDialog", "\320\237\321\200\320\276\320\270\320\267\320\262\320\276\320\264\320\270\321\202\320\265\320\273\321\214:", 0));
        locationLabel->setText(QApplication::translate("ComDialog", "Location:", 0));
        vendorLabel->setText(QApplication::translate("ComDialog", "Vendor ID:", 0));
        descriptionLabel->setText(QApplication::translate("ComDialog", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265:", 0));
        productLabel->setText(QApplication::translate("ComDialog", "Product ID:", 0));
        parametersBox->setTitle(QApplication::translate("ComDialog", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 COM-\320\277\320\276\321\200\321\202\320\260:", 0));
        baudRateLabel->setText(QApplication::translate("ComDialog", "BaudRate:", 0));
        dataBitsLabel->setText(QApplication::translate("ComDialog", "Data bits:", 0));
        parityLabel->setText(QApplication::translate("ComDialog", "Parity :", 0));
        stopBitsLabel->setText(QApplication::translate("ComDialog", "Stop bits", 0));
        flowControlLabel->setText(QApplication::translate("ComDialog", "Flow control:", 0));
        updateButton->setText(QApplication::translate("ComDialog", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", 0));
        saveButton->setText(QApplication::translate("ComDialog", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0));
    } // retranslateUi

};

namespace Ui {
    class ComDialog: public Ui_ComDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMDIALOG_H
