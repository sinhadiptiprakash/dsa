#include <bits/stdc++.h>
using namespace std;
//recursive
int LPS(string str, int i, int j)
{
    if (i > j)
        return 0;
    if (i == j)
        return 1;
    if (str[i] == str[j])
        return 2 + LPS(str, i + 1, j - 1);
    return max(LPS(str, i + 1, j), LPS(str, i, j - 1));
}
//bottom up
int lpsDP(string str)
{
    int n = str.size();
    int dp[n][n];
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;
    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i < n - len + 1; i++)
        {
            int j = i + len - 1;
            if (str[i] == str[j] && len == 2)
                dp[i][j] = 2;
            else if (str[i] == str[j])
                dp[i][j] = 2 + dp[i + 1][j - 1];
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    return dp[0][n - 1];
}
int main()
{
    string str;
    cin >> str;
    int n = str.length();
    cout << lpsDP(str) << endl;
    return 0;
}