#include <bits/stdc++.h>
using namespace std;
struct specialStack
{
    int min;
    stack<int> s;
    bool isEmpty()
    {
        return s.empty();
    }
    void push(int d)
    {
        if (s.empty())
        {
            min = d;
            s.push(d);
        }
        else
        {
            if (d >= min)
                s.push(d);
            else
            {
                s.push(2 * d - min);
                min = d;
            }
        }
    }
    int peek()
    {
        if (isEmpty())
            return INT_MAX;
        int topElement = (s.top() < min ? min : s.top());
        return topElement;
    }
    int pop()
    {
        if (s.empty())
            return INT_MAX;
        int topElement = (s.top() < min ? min : s.top());
        if (topElement == min)
        {
            min = 2 * min - s.top();
        }
        s.pop();
        return topElement;
    }
    int getMin()
    {
        if (s.empty())
            return INT_MAX;
        return min;
    }
};
int main()
{
    specialStack st;
    int arr[] = {6, 0, 3, 7, 9, 2, -1, 8, 2, -4};
    for (int i = 0; i < 10; i++)
        st.push(arr[i]);
    cout << "top of the stack is " << st.s.top() << " and min is " << st.getMin() << endl;
    while (!st.isEmpty())
    {
        cout << st.pop() << ' ' << endl;
    }
    return 0;
}