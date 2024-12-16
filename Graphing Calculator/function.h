#ifndef FUNCTION_H
#define FUNCTION_H
#define _USE_MATH_DEFINES
#include <cmath>
#include "operator.h"


class Function:public Operator
{
public:
    Function(string name):Operator(name), _precedence(calc_precedence()), _name(name), number_of_args(amount_of_arguments()){};

    int amount_of_arguments();
    double evaluate(double arg1 = 0, double arg2 = 0);
    int get_args();
    void print()const;
    int get_precedence();

private:
    int calc_precedence();
    int _precedence;
    string _name;
    int number_of_args;
};

#endif // FUNCTION_H
