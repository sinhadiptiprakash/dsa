#include <bits/stdc++.h>
using namespace std;
//below is the solution using stack
bool balanced_parenthesis_problem(string str)
{
    stack<char> st;
    for (char c : str)
    {
        //if the stack is empty or curent character is a openning parenthesis push it into the stack
        if (st.empty() || (c == '(' || c == '{' || c == '['))
            st.push(c);
        //else if its a closing parenthesis
        else
        {
            //if the stack is not empty we first pop the stack top and compare curent character with the popped top of the stack
            //if the curent character is the coresponding closing parenthesis of the top of the stack we do nothing and continue
            //else we can conclude that the expression is not balanced
            if (!st.empty())
            {
                char x = st.top();
                if (c == ')' && x == '(')
                    st.pop();
                else if (c == '}' && x == '{')
                    st.pop();
                else if (c == ']' && x == '[')
                    st.pop();
                else
                    return false;
            }
            //else the expression is not balanced
            else
                return false;
        }
    }
    //if the stack is empty then that means we got a balanced parenthesis otherwise not
    return (st.empty());
}
int main()
{
    string str;
    cin >> str;
    cout << balanced_parenthesis_problem(str) << endl;
    return 0;
}