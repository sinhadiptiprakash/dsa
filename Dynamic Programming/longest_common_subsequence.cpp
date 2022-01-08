#include <bits/stdc++.h>
using namespace std;
//recursive
int lcs(string s1, int n, string s2, int m)
{
    if (n == 0 || m == 0)
        return 0;
    if (s1[n - 1] == s2[m - 1])
        return 1 + lcs(s1, n - 1, s2, m - 1);
    return max(lcs(s1, n - 1, s2, m), lcs(s1, n, s2, m - 1));
}
//bottom up
int lcsBU(string s1, int n, string s2, int m)
{
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    //below part of the code is for printing the LCS
    //we go backward from the last index i.e. the length of the lcs
    int i = n, j = m, index = dp[n][m];
    //charcater array to store LCS
    //obviously the length of the LCS string would be index+1,
    //one extra space for storing the null character at the end of a character array
    char LCS[index + 1];
    LCS[index] = '\0'; // Set the terminating character
    while (i > 0 && j > 0)
    {
        //if the characters at i and j of s and t are same then include this character, decrease i and j by 1
        if (s1[i - 1] == s2[j - 1])
        {
            LCS[index - 1] = s1[i - 1];
            i--;
            j--;
            //as we are calculating the lcs backwards index should be decreased
            index--;
        }
        //else check dp table and compare dp[i-1][j] and dp[i][j-1] and go to the direction of greater value
        //because going to the lower value is meaning less because lower value can't contribute to the lcs
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    cout << LCS << endl;
    return dp[n][m];
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << lcsBU(s1, s1.length(), s2, s2.length()) << endl;
    return 0;
}