#include <bits/stdc++.h>
using namespace std;
int dp[2001][2001];
// N.B. wild contains wild card characters

//below is the recursive memoization implementation
bool wild_card_matching(string pattern, string wild, int n, int m)
{
    //base cases
    // If both the input string and wild reach their end,return true
    if (m < 0 && n < 0)
        return 1;
    // If only the wild reaches its end, return false
    else if (m < 0)
        return 0;
    // If only the input string reaches its end, return true
    // if the remaining characters in the wild are all `*`
    else if (n < 0)
    {
        for (int i = 0; i <= m; i++)
        {
            if (wild[i] != '*')
            {
                return 0;
            }
        }

        return 1;
    }

    // If the subproblem is encountered for the first time
    if (dp[m][n] == -1)
    {
        if (wild[m] == '*')
        {
            // 1. `*` matches with current characters in the input string.
            // Here, we will move to the next character in the string.

            // 2. Ignore `*` and move to the next character in the wild
            return dp[m][n] = wild_card_matching(pattern, wild, n - 1, m) || wild_card_matching(pattern, wild, n, m - 1);
        }
        else
        {
            // If the current character is not a wildcard character, it
            // should match the current character in the input string
            if (wild[m] != '?' && wild[m] != pattern[n])
            {
                return dp[m][n] = 0;
            }
            // check if `wild[0…m-1]` matches `pattern[0…n-1]`
            else
            {
                return dp[m][n] = wild_card_matching(pattern, wild, n - 1, m - 1);
            }
        }
    }
    //if we have already computed this subproblem return the solution
    return dp[m][n];
}
bool wild_card_matching_bottom_up(string pattern, string wild)
{
    int n = pattern.size();
    int m = wild.size();
    // empty wild can only match with empty string
    if (m == 0)
        return (n == 0);

    // dp table for storing results of subproblems
    bool dp[n + 1][m + 1];

    // initailze dp table to false
    memset(dp, false, sizeof(dp));

    // empty wild can match with empty string
    dp[0][0] = true;

    // Only '*' can match with empty string
    for (int j = 1; j <= m; j++)
        if (wild[j - 1] == '*')
            dp[0][j] = dp[0][j - 1];

    // fill the table in bottom-up fashion
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // Two cases if we see a '*'
            // a) We ignore ‘*’ character and move to next  character in the wild, i.e., ‘*’ indicates an empty sequence.
            // b) '*' character matches with ith  character in input
            if (wild[j - 1] == '*')
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j];

            // Current characters are considered as matching in two cases
            // (a) current character of wild is '?'
            // (b) characters actually match
            else if (wild[j - 1] == '?' || pattern[i - 1] == wild[j - 1])
                dp[i][j] = dp[i - 1][j - 1];

            // If characters don't match
            else
                dp[i][j] = false;
        }
    }

    return dp[n][m];
}

//below is the iterative solution(fastest without extra memory)
bool isMatch(string pattern, string wild)
{
    int n = pattern.size();
    int m = wild.size();
    int i = 0, j = 0, check1 = -1, check2 = -1;
    while (i < n)
    {
        if (j < m && (pattern[i] == wild[j] || wild[j] == '?'))
        {
            i++;
            j++;
        }
        else if (j < m && wild[j] == '*')
        {
            check1 = i;
            check2 = j;
            j++;
        }
        else if (check1 == -1)
            return false;
        else
        {
            i = check1 + 1;
            j = check2 + 1;
            check1 = i;
        }
    }
    //now if the pattern is empty then if we do not get all * from this j to end of the wild, return false
    for (j; j < m; j++)
    {
        if (wild[j] != '*')
            return false;
    }
    return true;
}
int main()
{
    string pattern, wild;
    cin >> pattern >> wild;
    int n = pattern.size();
    int m = wild.size();
    memset(dp, -1, sizeof dp);
    cout << isMatch(pattern, wild) << endl;
    return 0;
}