#include <bits/stdc++.h>
using namespace std;
// similar like longest palindromic subsequence
//recursive
/*
problem can be recursively defined. 

Initial Values : i= 0, j= n-1;

CountPS(i,j)
// Every single character of a string is a palindrome 
// subsequence 
if i == j
   return 1 // palindrome of length 1

// If first and last characters are same, then we 
// consider it as palindrome subsequence and check
// for the rest subsequence (i+1, j), (i, j-1)
Else if (str[i] == str[j)]
   return   countPS(i+1, j) + countPS(i, j-1) + 1;

else
   // check for rest sub-sequence and  remove common
   // palindromic subsequences as they are counted
   // twice when we do countPS(i+1, j) + countPS(i,j-1)
   return countPS(i+1, j) + countPS(i, j-1) - countPS(i+1, j-1)
*/
int countPalindromes(string str, int i, int j)
{
    if (i > j)
        return 0;
    if (i == j)
        return 1;
    if (str[i] == str[j])
        return 1 + countPalindromes(str, i + 1, j) + countPalindromes(str, i, j - 1);
    return countPalindromes(str, i + 1, j) + countPalindromes(str, i, j - 1) - countPalindromes(str, i + 1, j - 1);
}
//bottom up
int countPalindromicSubsequences(string str)
{
    int n = str.length();
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;
    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            int j = i + len - 1;
            if (str[i] == str[j])
                dp[i][j] = 1 + dp[i + 1][j] + dp[i][j - 1];
            else
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
        }
    }
    return dp[0][n - 1];
}
int main()
{
    string str;
    cin >> str;
    cout << countPalindromicSubsequences(str) << endl;
    return 0;
}