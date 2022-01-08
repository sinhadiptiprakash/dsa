#include <bits/stdc++.h>
using namespace std;

void insert_at_bottom(stack<int> &s, int x)
{
    if (s.size() == 0)
    {
        s.push(x);
        return;
    }

    int tmp = s.top();
    s.pop();
    insert_at_bottom(s, x);
    s.push(tmp);
}

int main()
{
    int n, x;
    cin >> n >> x;
    stack<int> s;
    while (n--)
    {
        int a;
        cin >> a;
        s.push(a);
    }

    insert_at_bottom(s, x);

    while (!s.empty())
    {
        cout << s.top() << "\n";
        s.pop();
    }
}