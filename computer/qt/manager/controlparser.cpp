#include "controlparser.h"

#include <QString>
#include <QDebug>

ControlParser::ControlParser()
{
}

ControlParser::Command ControlParser::parseFromDrones(QString text)
{
    qDebug() << "Parsing" << text;
}
