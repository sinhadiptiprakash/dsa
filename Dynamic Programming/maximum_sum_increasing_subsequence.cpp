#include <bits/stdc++.h>
using namespace std;
// similar like Longest Increasing Subsequence
int longestIncreasingSubsequence(int a[], int n)
{
    int dp[n];
    for (int i = 0; i < n; i++)
        dp[i] = a[i];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j])
                dp[i] = max(dp[i], dp[j] + a[i]);
        }
    }
    int maxSum = 1;
    for (int i = 0; i < n; i++)
    {
        maxSum = max(maxSum, dp[i]);
    }
    return maxSum;
} // time O(N^2) space O(N)
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << longestIncreasingSubsequence(a, n) << endl;
    return 0;
}