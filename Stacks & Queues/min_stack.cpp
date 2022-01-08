#include <bits/stdc++.h>
using namespace std;
class MinStack
{
public:
    /** initialize your data structure here. */
    stack<pair<int, int>> stk;

    MinStack() {}

    void push(int val)
    {
        pair<int, int> p;
        if (stk.empty())
            p = make_pair(val, val);
        else
        {
            int min = stk.top().second;
            if (val <= min)
                p = make_pair(val, val);
            else
                p = make_pair(val, min);
        }
        stk.push(p);
    }

    void pop()
    {
        stk.pop();
    }

    int top()
    {
        return stk.top().first;
    }

    int getMin()
    {
        return stk.top().second;
    }
};
int main()
{
    return 0;
}