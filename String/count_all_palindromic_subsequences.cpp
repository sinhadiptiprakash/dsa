#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
//in this problem we are gonna LCS kind of logic
/*
The problem can be recursively defined. 

Initial Values : i= 0, j= n-1;

CountPS(i,j)
// Every single character of a string is a palindrome 
// subsequence 
if i == j
   return 1 // palindrome of length 1

// If first and last characters are same, then we 
// consider it as palindrome subsequence and check
// for the rest subsequence (i+1, j), (i, j-1)
i.e. if (str[i] == str[j)]
   return   countPS(i+1, j) + countPS(i, j-1) + 1;

else
   // check for rest sub-sequence and  remove common
   // palindromic subsequences as they are counted
   // twice when we do countPS(i+1, j) + countPS(i,j-1)
   return countPS(i+1, j) + countPS(i, j-1) - countPS(i+1, j-1)
*/
int count_PS_recursive(string str, int i, int j)
{
    //if the string is empty
    if (i > j)
        return 0;
    // stirng with length 1 is always a palindrome
    if (i == j)
        return 1;
    // if the outer two characters match we already got one palindrome+ count of all other subsequences
    else if (str[i] == str[j])
    {
        return 1 + count_PS_recursive(str, i + 1, j) + count_PS_recursive(str, i, j - 1);
    }
    //if the outer characters dont match we check for rest subsequences
    //and remove common palindromic subsequences as they counted twice
    return count_PS_recursive(str, i + 1, j) + count_PS_recursive(str, i, j - 1) - count_PS_recursive(str, i + 1, j - 1);
}
//below is the memoization version
int count_PS_memoization(string str, int i, int j)
{
    if (i > j)
        return 0;
    if (i == j)
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    else if (str[i] == str[j])
    {
        return dp[i][j] = 1 + count_PS_memoization(str, i + 1, j) + count_PS_memoization(str, i, j - 1);
    }
    return dp[i][j] = count_PS_memoization(str, i + 1, j) + count_PS_memoization(str, i, j - 1) - count_PS_memoization(str, i + 1, j - 1);
}
//below is the bottom up version
int countPS(string str)
{
    int N = str.length();
    // create a 2D array to store the count of palindromic
    // subsequence
    int cps[N + 1][N + 1];
    memset(cps, 0, sizeof(cps));

    // palindromic subsequence of length 1
    for (int i = 0; i < N; i++)
        cps[i][i] = 1;

    // check subsequence of length L is palindrome or not
    for (int L = 2; L <= N; L++)
    {
        for (int i = 0; i <= N - L; i++)
        {
            int k = L + i - 1;
            if (str[i] == str[k])
                cps[i][k] = cps[i][k - 1] + cps[i + 1][k] + 1;
            else
                cps[i][k] = cps[i][k - 1] + cps[i + 1][k] - cps[i + 1][k - 1];
        }
    }
    // return total palindromic subsequence
    return cps[0][N - 1];
}
int main()
{
    string str;
    cin >> str;
    int n = str.size();
    cout << countPS(str) << endl;
    return 0;
}