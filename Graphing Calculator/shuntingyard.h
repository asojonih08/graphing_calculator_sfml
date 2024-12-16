#ifndef SHUNTINGYARD_H
#define SHUNTINGYARD_H
#include "token.h"
#include "includes/Queue.h"
#include "includes/Stack.h"


class ShuntingYard
{
public:

    Queue<Token*> post_fix(Queue<Token*> infix);
};

#endif // SHUNTINGYARD_H
