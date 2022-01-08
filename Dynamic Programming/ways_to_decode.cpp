#include <bits/stdc++.h>
using namespace std;
int numDecodings(string s)
{
    if (s[0] == '0')
        return 0;
    if (s.size() == 1)
        return 1;
    int dp[s.size() + 1];
    memset(dp, 0, sizeof(dp));
    dp[s.size()] = 1;
    if (s[s.size() - 1] != '0')
        dp[s.size() - 1] = 1;
    for (int i = s.size() - 2; i >= 0; i--)
    {
        if (s[i] == '0')
            dp[i] = 0;
        else
        {
            int num = (s[i] - '0') * 10 + s[i + 1] - '0';
            if (num >= 10 && num <= 26)
            {
                dp[i] += dp[i + 2];
            }
            dp[i] += dp[i + 1];
        }
    }

    return dp[0];
}
int main()
{
    return 0;
}