/********************************************************************************
** Form generated from reading UI file 'dronessetting.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRONESSETTING_H
#define UI_DRONESSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dronesSetting
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *sizeSpinBox;
    QPushButton *saveDronesSettingButton;

    void setupUi(QDialog *dronesSetting)
    {
        if (dronesSetting->objectName().isEmpty())
            dronesSetting->setObjectName(QStringLiteral("dronesSetting"));
        dronesSetting->resize(400, 300);
        verticalLayout = new QVBoxLayout(dronesSetting);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(dronesSetting);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        sizeSpinBox = new QSpinBox(dronesSetting);
        sizeSpinBox->setObjectName(QStringLiteral("sizeSpinBox"));

        horizontalLayout->addWidget(sizeSpinBox);


        verticalLayout->addLayout(horizontalLayout);

        saveDronesSettingButton = new QPushButton(dronesSetting);
        saveDronesSettingButton->setObjectName(QStringLiteral("saveDronesSettingButton"));

        verticalLayout->addWidget(saveDronesSettingButton);


        retranslateUi(dronesSetting);

        QMetaObject::connectSlotsByName(dronesSetting);
    } // setupUi

    void retranslateUi(QDialog *dronesSetting)
    {
        dronesSetting->setWindowTitle(QApplication::translate("dronesSetting", "Configure drones", 0));
        label->setText(QApplication::translate("dronesSetting", "\320\240\320\260\320\267\320\274\320\265\321\200:", 0));
        saveDronesSettingButton->setText(QApplication::translate("dronesSetting", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0));
    } // retranslateUi

};

namespace Ui {
    class dronesSetting: public Ui_dronesSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRONESSETTING_H
