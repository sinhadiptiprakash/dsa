#include <bits/stdc++.h>
using namespace std;
/*
This problem is just the modification of Longest Common Subsequence problem. 
//The idea is to find the LCS(str, str) where str is the input string with the restriction 
//that when both the characters are same, they shouldn’t be on the same index in the two strings. 
*/
//below function returns the longest_repeating_subsequence string and the length of it
pair<string, int> longest_repeating_sequence_dp(string str)
{
    int n = str.length();
    int dp[n + 1][n + 1];
    //initlizing first row and column in dp table
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = 0;
        dp[i][0] = 0;
    }
    // Fill dp table (similar to LCS loops)
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // If characters match and indexes are not same
            if (str[i - 1] == str[j - 1] && i != j)
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    //now the dp[n][n] stores the length of the longest_repeating_subsequence
    //now we gonna find the string from the dp table
    //it is as similar as finding the LCS string from the dp table

    //THIS PART OF CODE FINDS THE RESULT STRING USING DP[][]
    // Initialize result
    string res = "";

    // Traverse dp[][] from bottom right
    int i = n, j = n;
    while (i > 0 && j > 0)
    {
        // If this cell is same as diagonally adjacent cell just above it,
        // then same characters are present at str[i-1] and str[j-1].
        // Append any of them to result.
        if (dp[i][j] == dp[i - 1][j - 1] + 1)
        {
            res = res + str[i - 1];
            i--;
            j--;
        }

        // Otherwise we move to the side that that gave us maximum result
        else if (dp[i][j] == dp[i - 1][j])
            i--;
        else
            j--;
    }

    // Since we traverse dp[][] from bottom, we get result in reverse order.
    reverse(res.begin(), res.end());
    return {res, dp[n][n]};
}
int main()
{
    string str = "AABEBCDD";
    auto res = longest_repeating_sequence_dp(str);
    cout << res.first << ' ' << res.second << endl;
    return 0;
}