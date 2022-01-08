#include <bits/stdc++.h>
using namespace std;
int calculate(string s)
{
    int n = s.size();
    stack<int> stk;
    int sum = 0, sign = 1;

    for (int i = 0; i < n; ++i)
    {
        char ch = s[i];
        if (isdigit(ch))
        {
            int val = 0;
            while (i < n && isdigit(s[i]))
            {
                val = val * 10 + (s[i] - '0');
                ++i;
            }
            --i;
            val *= sign;
            sum += val;
            sign = 1;
        }
        else if (ch == '(')
        {
            stk.push(sum);
            stk.push(sign);
            sum = 0;
            sign = 1;
        }
        else if (ch == ')')
        {
            sum *= stk.top();
            stk.pop();
            sum += stk.top();
            stk.pop();
        }
        else if (ch == '-')
        {
            sign = -1;
        }
    }
    return sum;
}
int main()
{
    return 0;
}