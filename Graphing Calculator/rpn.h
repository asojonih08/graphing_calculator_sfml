#ifndef RPN_H
#define RPN_H

#include "token.h"
#include "number.h"
#include "operator.h"
#include "function.h"
#include "includes/Queue.h"
#include "includes/Stack.h"

class RPN
{
public:

    RPN(){};
    RPN(Queue<Token*> q);

    void post_fix(const Queue<Token*> &q);
    double evaluate(double value = 0);
    double operator()(double value = 0);

private:
    Queue<Token*> _post_fix;
};

#endif // RPN_H
