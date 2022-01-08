#include <bits/stdc++.h>
using namespace std;
// recursion
int countPerfects(int n)
{
    if (n <= 3)
        return n;
    int x = sqrt(n);
    int res = INT_MAX;
    for (int i = x; i >= 1; i--)
    {
        res = min(res, 1 + countPerfects(n - i * i));
    }
    return res;
}
// bottom up DP
int countPerfectSquares(int n)
{
    if (n <= 3)
        return n;
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0, dp[1] = 1, dp[2] = 2, dp[3] = 3, dp[4] = 1;
    for (int i = 5; i <= n; i++)
    {
        int x = sqrt(i);
        for (int j = x; j >= 1; j--)
        {
            dp[i] = min(dp[i], 1 + dp[i - j * j]);
        }
    }
    return dp[n];
}
int main()
{
    return 0;
}