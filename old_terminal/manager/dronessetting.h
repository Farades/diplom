#ifndef DRONESSETTING_H
#define DRONESSETTING_H

#include <QDialog>

namespace Ui {
class dronesSetting;
}

class dronesSetting : public QDialog
{
    Q_OBJECT

public:
    struct Settings {
        int size;
    };

    explicit dronesSetting(QWidget *parent = 0);
    ~dronesSetting();

    Settings settings() const;

private slots:
    void apply();

private:
    void updateSettings();

private:
    Ui::dronesSetting *ui;
    Settings currentSettings;
};

#endif // DRONESSETTING_H
