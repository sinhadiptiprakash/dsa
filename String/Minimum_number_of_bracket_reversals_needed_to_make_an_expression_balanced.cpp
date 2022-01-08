#include <bits/stdc++.h>
using namespace std;
int minimum_number_of_breaket_reversal(string expression)
{
    //first of all we remove the already balanced expression within the expression
    // for doing so we need a stack of characters
    int len = expression.length();
    // length of expression must be even to make it balanced by using reversals.
    if (len % 2)
        return -1;
    stack<char> s;
    for (char c : expression)
    {
        if (!s.empty() && c == '}')
        {
            if (s.top() == '{')
                s.pop();
            else
                s.push(c);
        }
        else
            s.push(c);
    }
    //now we have removed balanced expression from the expression and now we have the un-balanced expression

    // Length of the reduced expression red_len = (m+n)
    int red_len = s.size();

    // count opening brackets at the end of stack
    int n = 0;
    cout << s.size() << endl;
    //now red_len will store the no. of } brackets and n store the no
    while (!s.empty() && s.top() == '{')
    {
        s.pop();
        n++;
        red_len--;
    }
    // as the last { brackets will balance the remaining } brakcets in the stack
    // after balancing remaining } brakcets will balance themselves
    return ((n / 2) + (n % 2) + (red_len / 2) + (red_len % 2));
} //time complexity O(N) space complexity O(N)

//below is the O(1) space optimized approach
/*
Approach:
    Since the expression only contains one type of brackets, 
    the idea is to maintain two variables to keep count of left bracket as well as right bracket 
    as we did in Length of the longest valid substring. 
    If the expression has balanced brackets, then we decrement left variable else we increment right variable. 
    Then all we need to return is ceil(left/2) + ceil(right/2).
*/
int minimum_number_of_breaket_reversal_efficient(string expression)
{
    int len = expression.length();
    // Expressions of odd lengths cannot be balanced
    if (len % 2 != 0)
        return -1;
    int left_brace = 0, right_brace = 0;
    int ans;
    for (int i = 0; i < len; i++)
    {

        // If we find a left bracket then we simply increment the left bracket
        if (expression[i] == '{')
            left_brace++;
        // Else if left bracket is 0 then we find unbalanced right bracket and
        // increment right bracket or if the expression is balanced then we decrement left
        else
        {
            if (left_brace == 0)
                right_brace++;
            else
                left_brace--;
        }
    }
    // as the last { brackets will balance the remaining } brakcets in the stack
    // after balancing remaining } brakcets will balance themselves
    ans = ((left_brace / 2) + (left_brace % 2) + (right_brace / 2) + (right_brace % 2));
    return ans;
} //time compelxity O(N) space complexity O(1)
int main()
{
    string expression;
    cin >> expression;
    cout << minimum_number_of_breaket_reversal_efficient(expression) << endl;
    return 0;
}