#include <bits/stdc++.h>
using namespace std;
    // Method1: Recursion (TLE)
    int numDecodeWays(string &s, int n)
    {
        if (n <= 1)
            return 1;
        int oneDigitWays = s[n - 1] != '0' ? numDecodeWays(s, n - 1) : 0;
        int twoDigitWays = s[n - 2] == '1' or (s[n - 2] == '2' and s[n - 1] < '7') ? numDecodeWays(s, n - 2) : 0;
        return oneDigitWays + twoDigitWays;
    }

    // Method2: Memoization (Fastest: 0ms)
    vector<int> memoize = vector<int>(101, -1);
    int numDecodeWaysMemoize(string &s, int n)
    {
        if (n <= 1)
            return 1;
        if (memoize[n] == -1)
        {
            int oneDigitWays = s[n - 1] != '0' ? numDecodeWaysMemoize(s, n - 1) : 0;
            int twoDigitWays = s[n - 2] == '1' or (s[n - 2] == '2' and s[n - 1] < '7') ? numDecodeWaysMemoize(s, n - 2) : 0;
            memoize[n] = oneDigitWays + twoDigitWays;
        }
        return memoize[n];
    }

    // Method3: DP (Fast: 4ms)
    int numDecodeWaysDP(string &s, int n)
    {
        vector<int> dp(n + 1, 1);
        for (int i = 2; i <= n; i++)
        {
            int oneDigitWays = s[i - 1] != '0' ? dp[i - 1] : 0;
            int twoDigitWays = s[i - 2] == '1' or (s[i - 2] == '2' and s[i - 1] < '7') ? dp[i - 2] : 0;
            dp[i] = oneDigitWays + twoDigitWays;
        }
        return dp[n];
    }

    // Method4: DP [Constant Space] (Fastest: 0ms)
    int numDecodeWaysDP(string &s, int n)
    {
        int prev_prev = 1, prev = 1;
        for (int i = 2; i <= n; i++)
        {
            int oneDigitWays = s[i - 1] != '0' ? prev : 0;
            int twoDigitWays = s[i - 2] == '1' or (s[i - 2] == '2' and s[i - 1] < '7') ? prev_prev : 0;
            int curr = oneDigitWays + twoDigitWays;
            prev_prev = prev, prev = curr;
        }
        return prev;
    }

    // Main
    int numDecodings(string s)
    {
        // handle simple case
        if (s[0] == '0')
            return 0;
        // return numDecodeWays(s, s.length());
        // return numDecodeWaysMemoize(s, s.length());
        return numDecodeWaysDP(s, s.length());
    }
int main()
{
    return 0;
}