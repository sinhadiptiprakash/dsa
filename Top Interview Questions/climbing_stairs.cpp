#include <bits/stdc++.h>
using namespace std;
int climbStairs(int n)
{
    int beforePrev = 1, prev = 2;
    if (n <= 2)
        return n;
    int res = 0;
    for (int i = 3; i <= n; i++)
    {
        res = beforePrev + prev;
        beforePrev = prev;
        prev = res;
    }
    return res;
}
int main()
{
    return 0;
}