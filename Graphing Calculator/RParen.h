#ifndef RPAREN_H
#define RPAREN_H
#include "token.h"

class RParen:public Token
{
public:

    RParen():Token(4){};
    void print() const
    {
        cout << ")";
    }
};

#endif // RPAREN_H
