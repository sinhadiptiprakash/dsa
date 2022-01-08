#include <bits/stdc++.h>
using namespace std;
//recursive
/*
f(n) = ways n people can remain single 
       or pair up.

For n-th person there are two choices:
1) n-th person remains single, we recur 
   for f(n - 1)
2) n-th person pairs up with any of the 
   remaining n - 1 persons. We get (n - 1) * f(n - 2)

Therefore we can recursively write f(n) as:
f(n) = f(n - 1) + (n - 1) * f(n - 2)
*/
int numOfWaysToPair(int n)
{
    if (n <= 2)
        return n;
    return numOfWaysToPair(n - 1) + (n - 1) * numOfWaysToPair(n - 2);
}
//dp
int ways(int n)
{
    const int mod = 1e9 + 7;
    long long dp[n + 1];
    dp[0] = 0, dp[1] = 1, dp[2] = 2;
    for (int i = 3; i <= n; i++)
        dp[i] = ((dp[i - 1]) % mod + (dp[i - 2] * (i - 1)) % mod) % mod;
    return dp[n];
}
int countFriendsPairings(int n)
{
    int a = 1, b = 2, c = 0;
    if (n <= 2)
        return n;
    for (int i = 3; i <= n; i++)
    {
        c = b + (i - 1) * a;
        a = b;
        b = c;
    }
    return c;
} // time complexity O(N) space complexity O(1)
int main()
{
    int n;
    cin >> n;
    cout << ways(n) << endl;
    return 0;
}