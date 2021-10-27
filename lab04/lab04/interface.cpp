#include "interface.h"

bool Interface::readInputInt(int &read, QLineEdit *line)
{
    bool ok;
    read = line->text().toInt(&ok, 10);
    return ok;
}

bool Interface::readInputInt(int &read, QLineEdit *line, int leftBorder, int rightBorder)
{
    bool ok;
    read = line->text().toInt(&ok, 10);
    if (ok != true)
        return ok;
    if (read < leftBorder || read > rightBorder)
        ok = false;
    return ok;
}
