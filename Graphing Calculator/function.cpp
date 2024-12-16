#include "function.h"

void Function::print() const
{
    cout << _name;
}

int Function::get_precedence()
{
    return 10;
}

int Function::calc_precedence()
{
    return 10;
}

int Function::amount_of_arguments()
{
    int func_name = 0;

    if(_name == "cos") func_name = 1;
    else if (_name == "sin") func_name = 2;
    else if (_name == "tan") func_name = 3;
    else if (_name == "cot") func_name = 4;
    else if (_name == "csc") func_name = 5;
    else if (_name == "sec") func_name = 6;
    else if (_name == "arcsin") func_name = 7;
    else if (_name == "arccos") func_name = 8;
    else if (_name == "arctan") func_name = 9;
    else if (_name == "arccot") func_name = 10;
    else if (_name == "arccsc") func_name = 11;
    else if (_name == "arcsec") func_name = 12;
    else if (_name == "abs") func_name = 13;
    else if (_name == "max") func_name = 14;
    else if (_name == "min") func_name = 15;
    else if (_name == "pi") func_name = 16;
    else if (_name == "e") func_name = 17;

    switch (func_name)
    {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13: return 1;
        case 14:
        case 15: return 2;
        case 16:
        case 17: return 0;
    }
  return -1;
}

double Function::evaluate(double arg1, double arg2)
{
    // 1 arg functions
    if(_name == "sin") return sin(arg1);
    if(_name == "cos") return cos(arg1);
    if(_name == "tan") return tan(arg1);
    if(_name == "cot") return cos(arg1)/sin(arg1);
    if(_name == "csc") return 1 / (sin(arg1));
    if(_name == "sec") return 1 / (cos(arg1));
    if(_name == "arcsin") return asin(arg1);
    if(_name == "arccos") return acos(arg1);
    if(_name == "arctan") return atan(arg1);
    if(_name == "arccot") return acos(arg1)/asin(arg1);
    if(_name == "arccsc") return 1 / (asin(arg1));
    if(_name == "arcsec") return 1 / (acos(arg1));
    if(_name == "abs") return abs(arg1);

    // 2 arg functions
    if(_name == "max") return max(arg1,arg2);
    if(_name == "min") return min(arg1,arg2);

    // 0 arg functions
    if(_name == "pi") return M_PI;
    if(_name == "e") return exp(1.0);

}

int Function::get_args()
{
    return number_of_args;
}
