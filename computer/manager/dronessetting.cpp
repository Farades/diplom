#include "dronessetting.h"
#include "ui_dronessetting.h"

dronesSetting::dronesSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dronesSetting)
{
    ui->setupUi(this);

    connect(ui->saveDronesSettingButton, SIGNAL(clicked()),
            this, SLOT(apply()));

    currentSettings.size = 1;
}

dronesSetting::~dronesSetting()
{
    delete ui;
}

void dronesSetting::apply()
{
    updateSettings();
    hide();
}

dronesSetting::Settings dronesSetting::settings() const
{
    return currentSettings;
}

void dronesSetting::updateSettings()
{
    currentSettings.size = ui->sizeSpinBox->value();
}
