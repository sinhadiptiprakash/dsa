#include <bits/stdc++.h>
using namespace std;
// similar logic as LCS but the difference here we will not consider the character where i==j
int LongestRepeatingSubsequence(string str)
{
    int n = str.size();
    int dp[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (str[i - 1] == str[j - 1] && i != j)
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][n];
}
int main()
{
    string str;
    cin >> str;
    cout << LongestRepeatingSubsequence(str) << endl;
    return 0;
}