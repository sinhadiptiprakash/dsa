#include <bits/stdc++.h>
using namespace std;
struct minStack
{
    stack<long long int> st;
    long long int min;
    long long int intConv; //we will use this variable to convert int to long long int

    void push(int val)
    {
        intConv = val; //converts val from int to long long int
        if (st.empty())
        {
            min = intConv;
            st.push(intConv);
        }
        else if (intConv <= min)
        {
            st.push(2 * intConv - min);
            min = intConv;
        }
        else
            st.push(intConv);
    }

    void pop()
    {

        long long int t = st.top();
        if (t <= min)
            min = 2 * min - t;

        st.pop();
    }

    int top()
    {

        if (st.top() <= min)
            return min;

        return st.top();
    }

    int getMin()
    {
        return min;
    }
};
int main()
{
    int a[] = {4, 5, 2, 7, 3, -1, 2, 0, 4};
    minStack ms;
    for (int i = 0; i < 9;i++)
        ms.push(a[i]);
    while(!ms.st.empty()){
        cout << ms.top() << endl;
        ms.pop();
    }
    return 0;
}