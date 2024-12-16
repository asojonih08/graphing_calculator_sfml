#include "input.h"

Input::Input()
{

}

Queue<Token*> Input::tokenize(char *input_infix) //tokenizes inout string
{
    Queue<Token*> infix2;

    char deliminator [] = " ";

    input_infix = strtok(input_infix, deliminator);

    while(input_infix)
    {
        cout << input_infix;

        if(isdigit(*input_infix))
        {
            infix2.push(new Number(stod(input_infix)));
            cout << setw(25 - strlen(input_infix)) << "NUMBER" << endl;
        }

        else if(*input_infix == 'x')
        {
            infix2.push(new Variable());
            cout << setw(25 - strlen(input_infix)) << "VARIABLE" << endl;
        }

        else if(*input_infix == '(')
        {
            infix2.push(new LParen());
            cout << setw(25 - strlen(input_infix)) << "LPAREN" << endl;
        }

        else if(*input_infix == ')')
        {
            infix2.push(new RParen());
            cout << setw(25 - strlen(input_infix)) << "RPAREN" << endl;
        }

        else
        {
            if(*input_infix == '+' || *input_infix == '-' ||
               *input_infix == '*' || *input_infix == '/' || *input_infix == '^')
            {
                infix2.push(new Operator(input_infix));
                cout << setw(25 - strlen(input_infix)) << "OPERATOR" << endl;
            }

            else
            {
                infix2.push(new Function(input_infix));
                cout << setw(25 - strlen(input_infix)) << "FUNCTION" << endl;
            }
        }

        input_infix = strtok(NULL,deliminator);
    }
    cout << infix2;
    return infix2;
}
