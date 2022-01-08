#include <bits/stdc++.h>
using namespace std;
//longest common subs-tring RECURSIVE
int lcss(string a, int n, string b, int m, int cnt)
{
    //if one of the string is empty we return the count
    if (n == 0 || m == 0)
        return cnt;
    //if the last character matches then we increase the count by 1 and recursively call for rest
    if (a[n - 1] == b[m - 1])
        cnt = lcss(a, n - 1, b, m - 1, cnt + 1);
    //if the last character does not match either we delete the last character of a or b
    //and make the count=0 as we are searching for a substring so whenever we get a mismatch
    //we start a the count from 0 by deleting either the last chracter of a or b
    else
        cnt = max(cnt, max(lcss(a, n - 1, b, m, 0), lcss(a, n, b, m - 1, 0)));
    return cnt;
}
//bottom up
int longestCommonSubstring(string a, string b, int n, int m)
{
    int dp[n + 1][m + 1];
    int result = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0 || a[i - 1] != b[j - 1])
                dp[i][j] = 0;
            else
                dp[i][j] = 1 + dp[i - 1][j - 1];
            result = max(result, dp[i][j]);
        }
    }
    return result;
}
int main()
{
    string s1, s2;
    int n, m;
    cin >> s1 >> s2;
    n = s1.length(), m = s2.length();
    cout << longestCommonSubstring(s1, s2, n, m) << endl;
    return 0;
}