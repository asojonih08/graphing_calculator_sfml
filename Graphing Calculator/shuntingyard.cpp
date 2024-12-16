#include "shuntingyard.h"

Queue<Token*> ShuntingYard::post_fix(Queue<Token*> infix) //converts infix expression of tokens to post fix expression
{
    Stack<Token*> post_stack;
    Queue<Token*> post_fix;

    Queue<Token*>::Iterator it_infix = infix.front();
    Token* temp_infix = *it_infix;
    Stack<Token*>::Iterator it_post_stack = post_stack.top();
    Token* temp_post_stack;
    const bool debug = false;

    if(!post_stack.empty())
        temp_post_stack = *it_post_stack;

    while(!infix.empty())
    {

        it_infix = infix.front();
        temp_infix = *it_infix;

        int type = (*temp_infix).type();

        it_post_stack = post_stack.top();


        if(!post_stack.empty())
        temp_post_stack = *it_post_stack;

        if(debug)cout << *temp_infix;

        if(debug) cout << "\ntype: " << type << endl;

        switch(type)

        {
            case 1: post_fix.push(infix.pop()); break;
            case 2:

                    if(post_stack.empty())
                    {
                        post_stack.push(infix.pop());
                        break;
                    }

                    if(temp_post_stack->type() == 3 || temp_infix -> get_precedence() > temp_post_stack -> get_precedence())
                        post_stack.push(infix.pop());

                    else
                    {
                        post_fix.push(post_stack.pop());
                        post_stack.push(infix.pop());
                    }
                    break;
            case 3:
                    post_stack.push(infix.pop());
                    break;
            case 4:
                    infix.pop();

                    while(temp_post_stack->type() !=3)
                    {
                        post_fix.push(post_stack.pop());
                        it_post_stack = post_stack.top();
                        temp_post_stack = *it_post_stack;
                    }
                    post_stack.pop(); break;

            case 5:
                    post_fix.push(infix.pop()); break;

         }
    }

    while(!post_stack.empty())
    post_fix.push(post_stack.pop());

    return post_fix;
}
