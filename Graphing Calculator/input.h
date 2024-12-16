#ifndef INPUT_H
#define INPUT_H
#include "token.h"
#include "number.h"
#include "operator.h"
#include "function.h"
#include "LParen.h"
#include "RParen.h"
#include "variable.h"
#include <string>
#include <iostream>
#include "includes/Queue.h"
#include <iomanip>
#include <cstring>

using namespace std;

class Input
{
public:
    Input();

    Queue<Token*> tokenize(char *input_infix);
};

#endif // INPUT_H
