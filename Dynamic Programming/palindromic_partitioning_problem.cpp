#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string str, int i, int j)
{
    while (i < j)
    {
        if (str[i] != str[j])
            return false;
        i++, j--;
    }
    return true;
}
//recursive
int palindromicPartitioning(string str, int i, int j)
{
    if (i >= j || isPalindrome(str, i, j))
        return 0;
    int minCost = INT_MAX, cost;
    for (int k = i; k < j; k++)
    {
        cost = palindromicPartitioning(str, i, k) + palindromicPartitioning(str, k + 1, j) + 1;
        minCost = min(minCost, cost);
    }
    return minCost;
}
//bottom up
int palPartitioningDP(string str)
{
    int n = str.length();
    int dp[n][n] = {0};
    int cost;
    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i < n - len + 1; i++)
        {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            if (isPalindrome(str, i, j))
                dp[i][j] = 0;
            else
            {
                for (int k = i; k < j; k++)
                {
                    cost = 1 + dp[i][k] + dp[k + 1][j];
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }
    }
    return dp[0][n - 1];
} //time complexity O(N^3) and space comlexity O(N^2)
//we can reduce the time complexity by using extra 2d matrix pal[i][j]
// for storing if bubstring[i...j] is palindrome or not, and by this we can have a time complexity of O(N^2) and space of O(N^2)
int palPartitionDPEfficient(string str)
{
    // Get the length of the string
    int n = str.size();

    /* Create two arrays to build the solution in bottom-up manner
       dp[i] = Minimum number of cuts needed for a palindrome partitioning
                 of substring str[0..i]
       P[i][j] = true if substring str[i..j] is palindrome, else false
       Note that dp[i] is 0 if P[0][i] is true */
    int dp[n];
    bool P[n][n];

    int i, j, k, len; // different looping variables

    // Every substring of length 1 is a palindrome
    for (i = 0; i < n; i++)
        P[i][i] = true;

    /* len is substring length. Build the solution in bottom up manner by
       considering all substrings of length starting from 2 to n. */
    for (len = 2; len <= n; len++)
    {
        // For substring of length len, set different possible starting indexes
        for (i = 0; i < n - len + 1; i++)
        {
            j = i + len - 1; // Set ending index

            // If len is 2, then we just need to compare two characters. Else
            // need to check two corner characters and value of P[i+1][j-1]
            if (len == 2)
                P[i][j] = (str[i] == str[j]);
            else
                P[i][j] = (str[i] == str[j]) && P[i + 1][j - 1];
        }
    }

    for (i = 0; i < n; i++)
    {
        if (P[0][i] == true)
            dp[i] = 0;
        else
        {
            dp[i] = INT_MAX;
            for (j = 0; j < i; j++)
            {
                if (P[j + 1][i] == true && 1 + dp[j] < dp[i])
                    dp[i] = 1 + dp[j];
            }
        }
    }
    // Return the min cut value for complete string. i.e., str[0..n-1]
    return dp[n - 1];
}
//most efficient approach
int palindromePartitioning(string s)
{

    int n = s.length();
    vector<vector<bool>> pal(n, vector<bool>(n, false)); //if pal[i][j] is 1 then substring from i to j is palindrome
    // checking and storing the wheather a substring is palindrome or not
    for (int len = 1; len <= n; len++)
    {
        for (int i = 0; i < n + 1 - len; i++)
        {
            int j = i + len - 1;
            pal[i][j] = (s[i] == s[j]) && ((j - i <= 2) || pal[i + 1][j - 1]);
        }
    }
    // 1D DP table is needed here
    vector<int> dp(n);
    // dp[i] denotes the minimum number of cuts needed to partitioning substr s
    for (int i = 0; i < n; i++)
    {
        dp[i] = i; // we assume that maximum i no. of cuts will be needed to have all the partitions
        // palindrome for the substring from 0 to i
        for (int j = 0; j <= i; j++)
        {
            if (pal[j][i])
            {
                dp[i] = (j == 0) ? 0 : min(dp[i], dp[j - 1] + 1);
            }
        }
    }
    return dp[n - 1];
} // TC O(N^2) SC O(N^2)
int main()
{
    string str;
    cin >> str;
    cout << palPartitionDPEfficient(str) << endl;
    return 0;
}