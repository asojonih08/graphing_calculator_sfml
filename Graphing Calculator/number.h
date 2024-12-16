#ifndef NUMBER_H
#define NUMBER_H

#include "token.h"
#include <string>

using namespace std;

class Number:public Token
{
public:
    Number():Token(1), _num(0){};
    Number(double num):Token(1), _num(num){};
    Number(string string_num):Token(1), _num(stod(string_num)){};

    double value();

    void print() const;

private:
    double _num;

};

#endif // NUMBER_H
