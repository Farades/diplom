#ifndef CONTROLPARSER_H
#define CONTROLPARSER_H

class QString;

class ControlParser
{
public:
    struct Command {
        int from;
        int to;
    };

public:
    ControlParser();
    void parseToDrones(QString text);
    Command parseFromDrones(QString text);
};

#endif // CONTROLPARSER_H
