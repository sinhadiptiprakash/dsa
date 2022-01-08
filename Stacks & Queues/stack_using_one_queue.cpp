#include <bits/stdc++.h>
using namespace std;
class Stack
{
    queue<int> q;

public:
    Stack() {}
    bool is_empty()
    {
        //if  the queue is empty then the stack is empty
        return q.empty();
    }
    int size()
    {
        return q.size();
    }
    void push(int data)
    {
        int n = q.size();
        q.push(data);
        int i = 0;
        while (i < n)
        {
            q.push(q.front());
            q.pop();
            i++;
        }
    }
    int pop()
    {
        //stack underflow
        if (is_empty())
            return -1;
        int elem = q.front();
        q.pop();
        return elem;
    }
    int peek()
    {
        return q.front();
    }
};
int main()
{
    Stack stack;
    for (int i = 0; i < 5; i++)
    {
        stack.push(i);
    }
    cout << stack.peek() << endl;
    while (!stack.is_empty())
    {
        cout << stack.pop() << endl;
    }
    return 0;
}  