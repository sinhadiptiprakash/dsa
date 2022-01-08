#include <bits/stdc++.h>
using namespace std;
queue<int> reverse_queue_recursion(queue<int> &q)
{
    if (q.size() == 1)
        return q;
    int front = q.front();
    q.pop();
    queue<int> rest = reverse_queue_recursion(q);
    rest.push(front);
    return rest;
}
queue<int> reverse_queue_iterative(queue<int> q)
{
    stack<int> stack;
    queue<int> result;
    while (!q.empty())
    {
        stack.push(q.front());
        q.pop();
    }
    while (!stack.empty())
    {
        result.push(stack.top());
        stack.pop();
    }
    return result;
}
int main()
{
    queue<int> q;
    for (int i = 0; i < 5; i++)
    {
        q.push(i);
    }
    auto res = reverse_queue_iterative(q);
    while (!res.empty())
    {
        cout << res.front() << endl;
        res.pop();
    }
    return 0;
}