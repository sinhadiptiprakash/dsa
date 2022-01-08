#include <bits/stdc++.h>
using namespace std;
//recursive
int lcs(string s1, int n, string s2, int m, string s3, int o)
{
    if (n == 0 || m == 0 || o == 0)
        return 0;
    if (s1[n - 1] == s2[m - 1] && s2[m - 1] == s3[o - 1])
        return 1 + lcs(s1, n - 1, s2, m - 1, s3, o - 1);
    return max(lcs(s1, n - 1, s2, m, s3, o), max(lcs(s1, n, s2, m - 1, s3, o), lcs(s1, n, s2, m, s3, o - 1)));
}
//bottom up
int lcsBU(string s1, int n, string s2, int m, string s3, int o)
{
    int dp[n + 1][m + 1][o + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = 1; k <= o; k++)
            {
                if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1])
                    dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
                else
                {
                    dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
                }
            }
        }
    }
    return dp[n][m][o];
}
int main()
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    cout << lcsOfThree(s1, s2, s3) << endl;
    return 0;
}