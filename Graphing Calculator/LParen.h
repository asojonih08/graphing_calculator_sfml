#ifndef LPAREN_H
#define LPAREN_H

#include "token.h"

class LParen:public Token
{
public:
    LParen():Token(3){};
    void print() const
    {
        cout << "(";
    };
};

#endif // LPAREN_H
