#include "rpn.h"

RPN::RPN(Queue<Token*> q)
{
    _post_fix = q;
}

double RPN::evaluate(double value) // evaluates post_fix expression using rpn algorithm
{
    const bool debug = false;
    Queue<Token*> q;
    q =_post_fix;

    if (debug) cout << "\nq(post_fix): " << q;
    Queue<Token*>::Iterator it = q.front();
    Token* temp = *it;
    Stack<Token*> rpn_stack;
    if (debug)cout << "\nrpn_stack: " << rpn_stack << " size: " << rpn_stack.size() << endl;

    double operands[2];
    int token_type;

    while(!q.empty())
    {
        it = q.front();
        temp = *it;
        token_type = temp -> type();

        switch(token_type)
        {
            case 1:
            {
                Token* t = q.pop();
                rpn_stack.push(t);
                break;
            }

            case 2:
            {
                double result = 0;

                if(temp->get_precedence() != 10)
                {
                    for(int i = 0; i < 2; i++)
                    {
                        operands[i] = rpn_stack.pop() -> value();

                    }

                    result = temp->operation(operands[1], operands[0]);
                    rpn_stack.push(new Number(result));
                    q.pop();
                    if (debug) cout << endl << "Queue q: " << q << endl;
                    break;
                }


                else
                {
                    int num_args = static_cast<Function*>(temp) -> get_args();


                    for(int i = 0; i < num_args; i++)
                    {
                        operands[i] = rpn_stack.pop()->value();

                    }

                    if(num_args == 0)
                    {
                        result = static_cast<Function*>(temp)-> evaluate();
                    }

                    else if(num_args == 1)
                    {
                        result = static_cast<Function*>(temp)-> evaluate(operands[0]);
                    }
                    else
                    {
                        result = static_cast<Function*>(temp)-> evaluate(operands[1], operands[0]);
                    }

                    rpn_stack.push(new Number(result));
                    q.pop();

                    break;
                }


            }

            case 5:
            if (debug) cout << endl << "value: " << value << endl;
            q.pop();
            rpn_stack.push(new Number(value));
            if (debug)cout << "\nrpn_stack: " << rpn_stack << endl;
            break;

        }

    }
    if (debug)cout << "\nrpn_stack: " << rpn_stack << endl;
    double stack_value = rpn_stack.pop()->value();
    if (debug) cout << "\nstack_value: " <<stack_value << endl;
    return stack_value;

}
