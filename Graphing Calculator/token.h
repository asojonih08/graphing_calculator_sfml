#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
using namespace std;

class Token
{
public:
    Token(int type):_type(type){};

    int type();
    virtual void print() const;
    virtual int get_precedence();
    virtual double value();
    virtual double operation(const double& left, const double& right);

    friend ostream& operator <<(ostream& outs, Token* token)
    {

        (*token).print();
        return outs;
    }

    friend ostream& operator <<(ostream& outs, const Token &token)
    {
        token.print();
        return outs;
    }

private:

    int _type; //1 Number, 2 Operator, 3 LParen, 4 RParen
};

#endif // TOKEN_H
