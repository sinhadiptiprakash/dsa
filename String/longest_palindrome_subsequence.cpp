#include <bits/stdc++.h>
using namespace std;
int dp[1000][1000];
//using lcs concept
//the longest palindrome sequence is the LCS of the string itself and the reversed string
//below is the memoized version of lcs using dp
int LCS(string str1, int n, string str2, int m)
{
    if (n == 0 || m == 0)
        return 0;
    if (dp[n][m] != -1)
        return dp[n][m];
    if (str1[n - 1] == str2[m - 1])
        return 1 + LCS(str1, n - 1, str2, m - 1);
    return max(LCS(str1, n - 1, str2, m), LCS(str1, n, str2, m - 1));
}
int longest_palindrome_sub_sequence_using_lcs(string s)
{
    //first reverse the string
    string t = s;
    reverse(s.begin(), s.end());
    //now the longest palindromic sequence is LCS(s,t)
    //now for getting the LCS we first have to initialize the dp array with all -1
    memset(dp, -1, sizeof(dp));
    return LCS(s, s.length(), t, t.length());
}
//another
int longestPalindromicSubsequence(string str, int i, int j)
{
    if (i > j)
        return 0;
    if (i == j)
        return 1;
    if (str[i] == str[j])
        return 2 + longestPalindromicSubsequence(str, i + 1, j - 1);
    return max(longestPalindromicSubsequence(str, i + 1, j), longestPalindromicSubsequence(str, i, j - 1));
}
int main()
{
    string str;
    cin >> str;
    cout << longestPalindromicSubsequence(str, 0, str.length() - 1) << endl;
    return 0;
}