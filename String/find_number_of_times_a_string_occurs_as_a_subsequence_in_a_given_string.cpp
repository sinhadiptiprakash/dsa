#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
//below is the recursive version to count number of occurence of the string str2 in str1
int find_number_of_occurence(string str1, string str2, int m, int n)
{
    //if both the string is empty or the str2 is empty that means str2 occurs in str1 one times
    if ((m == 0 && n == 0) || n == 0)
        return 1;
    // if the first string is empty
    if (m == 0)
        return 0;
    //recursive cases:

    // If last characters are same Recur for remaining strings by
    // 1. considering last characters of both strings
    // 2. ignoring last character of first string as str2 may appear in the string str1 excluding the last character
    if (str1[m - 1] == str2[n - 1])
        return find_number_of_occurence(str1, str2, m - 1, n - 1) + find_number_of_occurence(str1, str2, m - 1, n);
    //else If last characters are different,
    // ignore last char of first string and recur for remaining string
    return find_number_of_occurence(str1, str2, m - 1, n);
}
//below is the memoization version
int find_occurences_memo(string str1, string str2, int m, int n)
{
    if ((m == 0 && n == 0) || n == 0)
        return 1;
    if (m == 0)
        return 0;
    //if this subproblem is already solved return it
    if (dp[m][n] != -1)
        return dp[m][n];
    if (str1[m - 1] == str2[n - 1])
        return dp[m][n] = find_occurences_memo(str1, str2, m - 1, n - 1) + find_occurences_memo(str1, str2, m - 1, n);
    //else If last characters are different,
    // ignore last char of first string and recur for remaining string
    return dp[m][n] = find_occurences_memo(str1, str2, m - 1, n);
}

//below is the bottom up appraoch
int find_occurences_bu(string str1, string str2)
{
    int m = str1.length();
    int n = str2.length();
    int table[m + 1][n + 1];
    //caring about the base cases i.e. initialization
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if ((i == 0 && j == 0) || (j == 0))
                table[i][j] = 1;
            else
                table[i][j] = 0;
        }
    }
    //filling the table based on the recureence discussed above recurrence relation
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                table[i][j] = table[i - 1][j - 1] + table[i - 1][j];
            }
            else
                table[i][j] = table[i - 1][j];
        }
    }
    return table[m][n];
}
int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    int m = str1.length();
    int n = str2.length();
    memset(dp, -1, sizeof(dp));
    cout << find_occurences_bu(str1, str2) << endl;
    return 0;
}