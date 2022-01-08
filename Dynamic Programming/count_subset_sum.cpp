#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
//below is the RECURSIVE implementaion of COUNTING THE NO. OF SUBSETS WITH GIVEN SUM
int countSubsetSum(int a[], int n, int sum)
{
    if (sum == 0)
        return 1;
    if (n == 0)
        return 0;
    if (a[n - 1] > sum)
        return countSubsetSum(a, n - 1, sum);
    return countSubsetSum(a, n - 1, sum) + countSubsetSum(a, n - 1, sum - a[n - 1]);
}
//below is the MEMOIZATION VERSION OF COUNTING NO. OF SUBSETS WITH GIVEN SUM
int countSubsetSumMemo(int a[], int n, int sum)
{
    if (sum == 0)
        return 1;
    if (n == 0)
        return 0;
    if (dp[n][sum] != -1)
        return dp[n][sum];
    if (a[n - 1] > sum)
        return dp[n][sum] = countSubsetSumMemo(a, n - 1, sum);
    return dp[n][sum] = countSubsetSumMemo(a, n - 1, sum) + countSubsetSumMemo(a, n - 1, sum - a[n - 1]);
}
int countSubsetSumBU(int a[], int n, int sum)
{
    dp[0][0] = 1;
    for (int i = 1; i <= sum; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (a[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i - 1]];
        }
    }
    return dp[n][sum];
}
int main()
{

    return 0;
}