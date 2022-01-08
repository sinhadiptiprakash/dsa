#include <bits/stdc++.h>
using namespace std;
//infix to postfix conversion using stack
//for getting the precedence of an operator
int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
bool is_operand(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        return true;
    return false;
}
bool is_operator(char c)
{
    if (c == '+' || c == '-' || c == '/' || c == '*' || c=='^')
        return true;
    return false;
}
bool is_opening_bracket(char c)
{
    if (c == '(' || c == '[' || c == '{')
        return true;
    return false;
}
bool is_closing_bracket(char c){
    if (c == ')' || c == ']' || c == '}')
        return true;
    return false;
}
string infix_to_postfix(string expression)
{
    string postfix_expression = "";
    stack<char> stack;
    for (char c : expression)
    {
        if (is_operand(c))
            postfix_expression.push_back(c);
        else if (is_opening_bracket(c))
            stack.push(c);
        // else if it is an operator, then
        //pop all the operators from the stack which are greater than or equal to in precedence than that of the scanned operator.
        //After doing that Push the scanned operator to the stack. (If you encounter parenthesis while popping then stop there
        //and push the scanned operator in the stack.)
        else if (is_operator(c))
        {
            while (!stack.empty() && precedence(c) <= precedence(stack.top()) && !is_opening_bracket(stack.top()))
            {
                postfix_expression.push_back(stack.top());
                stack.pop();
            }
            stack.push(c);
        }
        //else if it is a closing bracket
        else
        {
            if (c == ')')
            {
                while (!stack.empty() && stack.top() != '(')
                {
                    postfix_expression.push_back(stack.top());
                    stack.pop();
                }
                //now also remove the '(' bracket
                stack.pop();
            }
            else if (c == '}')
            {
                while (!stack.empty() && stack.top() != '{')
                {
                    postfix_expression.push_back(stack.top());
                    stack.pop();
                }
                //now also remove the '{' bracket
                stack.pop();
            }
            else
            {
                while (!stack.empty() && stack.top() != '[')
                {
                    postfix_expression.push_back(stack.top());
                    stack.pop();
                }
                //now also remove the '[' bracket
                stack.pop();
            }
        }
    }
    while (!stack.empty())
    {
        postfix_expression.push_back(stack.top());
        stack.pop();
    }
    return postfix_expression;
}
int main()
{
    string expression;
    cin >> expression;
    cout << infix_to_postfix(expression) << endl;
    return 0;
}