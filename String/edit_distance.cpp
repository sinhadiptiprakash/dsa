#include <bits/stdc++.h>
using namespace std;
//let the maximum length of both the strings 500
int dp[501][501];
//below is the recursive appraoch
/*
Approach:
1.base case: if str1 is empty then we insert m no. of characters into str1 
    else if str2 is empty then we delete n no. of characters from str1 to make str1==str2
2.if last character of both the strings same we don't need to do any opration we just return the subproblem(n-1,m-1)
3.if last characters don't match we will have 3 choices for this decision and always add 1 for any choice
    (i)we have to repalce the last character of str1 with last character of str2, 
        i.e. decreasing length of both the strings by one
    (ii)we have to delete the last cahracter of the str1,
        i.e. decreasing only the str1 by 1
    (iii)we have to insert the last character of str2 into the str1,
        i.e. decreasing only the str2 by 1
*/
//recursive
int edit_distance(string str1, int n, string str2, int m)
{
    if (n == 0 || m == 0)
        return max(m, n);
    if (str1[n - 1] == str2[m - 1])
        return edit_distance(str1, n - 1, str2, m - 1); //no need of doing any operation

    return min(1 + edit_distance(str1, n - 1, str2, m - 1) //replacing
               ,
               min(1 + edit_distance(str1, n - 1, str2, m) //deleting
                   ,
                   1 + edit_distance(str1, n, str2, m - 1))); //inserting
}
//memoization
int edit_distance_memoization(string str1, int n, string str2, int m)
{
    if (n == 0 || m == 0)
        return max(m, n);
    if (dp[n][m] != -1)
        return dp[n][m];
    if (str1[n - 1] == str2[m - 1])
        return dp[n][m] = edit_distance_memoization(str1, n - 1, str2, m - 1);

    return dp[n][m] = min(1 + edit_distance_memoization(str1, n - 1, str2, m - 1), min(1 + edit_distance_memoization(str1, n - 1, str2, m), 1 + edit_distance_memoization(str1, n, str2, m - 1)));
}
//bottom-up dp
int edit_distance_bottom_up(string s1, string s2)
{
    int n1 = s1.length(), n2 = s2.length();

    int dp[n1 + 1][n2 + 1];

    //to change any string to 0 , all characters have to be either removed or inserted.
    for (int i = 0; i < n1 + 1; i++)
        dp[i][0] = i;
    for (int j = 1; j < n2 + 1; j++)
        dp[0][j] = j;

    for (int i = 1; i < n1 + 1; i++)
    {
        for (int j = 1; j < n2 + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                //if characters are same then we don't do anything
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                //now here we can find MINIMUM of three operations :
                //INSERT: Here we will be sure that the element inserted will be same character as that of s2.
                //So we will just decrease the current index of s2 by 1 as now it will match with the s1.here s1's index is not decreased as it will automatically be shifted by 1 due addition of new element to its right.
                //DELETE: Here we will only remove the current index of s1.Therefore s1's index is decreased by 1.
                //REPLACE: Here will decreasing both index of s1 and s2 by 1 as element have been replaced and will surely match with eachother.

                //ALL operation will carry 1 value so 1 has been added :)

                dp[i][j] = min(min(dp[i - 1][j] + 1, 1 + dp[i - 1][j - 1]), dp[i][j - 1] + 1);
            }
        }
    }
    return dp[n1][n2];
}
int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    int n = str1.length();
    int m = str2.length();
    memset(dp, -1, sizeof(dp));
    cout << edit_distance_bottom_up(str1, str2) << endl;
    return 0;
}