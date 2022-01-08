#include <bits/stdc++.h>
using namespace std;
/*
total[i] = same[i] + diff[i]
same[i]  = diff[i-1]
diff[i]  = (diff[i-1] + diff[i-2]) * (k-1)
         = total[i-1] * (k-1)
*/
long long countWays(int n, int k)
{
    long long dp[n + 1];
    memset(dp, 0, sizeof(dp));
    const int mod = 1e9 + 7;

    dp[1] = k;
    dp[2] = k * k;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = ((k - 1) * (dp[i - 1] + dp[i - 2])) % mod;
    }

    return dp[n];
} //time O(N) space O(N)
int main()
{
    return 0;
}