#ifndef INTERFACE_H
#define INTERFACE_H

#include <QLineEdit>

typedef enum
{
    OK,
    INPUT_ERROR
} InputError;

class Interface
{
public:
    bool readInputInt(int &read, QLineEdit *line);
    bool readInputInt(int &read, QLineEdit *line, int leftBorder, int rightBorder);
};

#endif // INTERFACE_H
