#include "operator.h"

int Operator::calc_precedence()
{
    switch(_op[0])
    {
        case '^': return 3;  //operator precedence
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
    }
    return 0;
}

double Operator::operation(const double& left, const double& right) // operator calc
{

    switch (_op[0])
    {
        case '+': return left + right;
        case '-': return left - right;
        case '*': return left * right;
        case '/': return left / right;
        case '^': return pow(left, right);
    }


    return 0;
}

int Operator::get_precedence()
{
    return _precedence;
}

void Operator::print() const
{
    cout << _op;
}
