#include <bits/stdc++.h>
using namespace std;
class MinStack
{
public:
    /** initialize your data structure here. */
    stack<int> s;
    stack<int> ss;

    MinStack()
    {
    }

    void push(int val)
    {

        s.push(val);
        if (ss.size() == 0 or ss.top() >= val)
            ss.push(val);
        return;
    }

    void pop()
    {
        if (ss.size() == 0)
            return;
        int ans = s.top();
        s.pop();
        if (ss.top() == ans)
            ss.pop();
        return;
    }

    int top()
    {
        return s.top();
    }

    int getMin()
    {

        if (ss.size() == 0)
            return -1;
        else
            return ss.top();
    }
};
int main()
{
    return 0;
}