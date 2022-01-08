#include <bits/stdc++.h>
using namespace std;
queue<int> reverse_first_k_elements(queue<int> q, int k)
{
    stack<int> stack;
    int i = 0;
    while (i < k && !q.empty())
    {
        stack.push(q.front());
        q.pop();
        i++;
    }
    queue<int> res;
    while (!stack.empty())
    {
        res.push(stack.top());
        stack.pop();
    }
    while (!q.empty())
    {
        res.push(q.front());
        q.pop();
    }
    return res;
}
int main()
{
    queue<int> q;
    for (int i = 0; i < 6; i++)
    {
        q.push(i);
    }
    auto res = reverse_first_k_elements(q, 3);
    while (!res.empty())
    {
        cout << res.front() << endl;
        res.pop();
    }
    return 0;
}