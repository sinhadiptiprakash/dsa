#include <bits/stdc++.h>
#include "infix_to_postfix.h"
using namespace std;
/*
The procedure for getting the result is: 
1.Convert the expression in Reverse Polish notation( post-fix notation). 
2.Push the operands into the stack in the order they appear.  
3.When any operator encounters then pop two topmost operands for executing the operation.  
4.After execution push the result obtained into the stack.  
5.After the complete execution of expression, the final result remains on the top of the stack. 
*/
int operations(int a, int b, char opertr)
{
    if (opertr == '+')
        return a + b;
    if (opertr == '-')
        return a - b;
    if (opertr == '*')
        return a * b;
    if (opertr == '/')
        return a / b;
    else
        return a ^ b;
}
int arithmetic_expresion_evaluation(string expression)
{
    string postfix = infix_to_postfix(expression);
    stack<int> operands;
    for (char c : postfix)
    {
        if (is_operand(c))
            operands.push(c - '0');
        else
        {
            if (!operands.empty())
            {
                int b = operands.top();
                operands.pop();
                int a = operands.top();
                operands.pop();
                operands.push(operations(a, b, c));
            }
        }
    }
    return operands.top();
}
int main()
{
    string expression;
    cin >> expression;
    int res = arithmetic_expresion_evaluation(expression);
    cout << res << endl;
    return 0;
}