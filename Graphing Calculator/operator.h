#ifndef OPERATOR_H
#define OPERATOR_H

#include <math.h>
#include "token.h"

class Operator:public Token
{
public:
    Operator(string op):Token(2), _op(op), _precedence(calc_precedence()){};

    double operation(const double& left, const double& right);
    void print() const;

    string op();
    virtual int get_precedence();

private:
    virtual int calc_precedence();
    string _op;
    int _precedence;
};

#endif // OPERATOR_H
