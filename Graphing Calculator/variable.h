#ifndef VARIABLE_H
#define VARIABLE_H

#include "token.h"

class Variable:public Token
{
public:
    Variable():Token(5){};

    void print()const {cout << "x";};

};

#endif // VARIABLE_H
