#include <bits/stdc++.h>
using namespace std;
// for better understanding the logic or recurrence relation visit GFG
int freqSum(int freq[], int i, int j)
{
    int sum = 0;
    for (int k = i; k <= j; k++)
        sum += freq[k];
    return sum;
}
//recursive
int optimalBSTCost(int freq[], int i, int j)
{
    if (i > j)
        return 0;
    if (i == j)
        return freq[i];
    int fSum = freqSum(freq, i, j);
    int minCost = INT_MAX, cost;
    // now make every key as root and recursively call lesser elements as left and greater elements as right subtree
    for (int r = i; r <= j; r++)
    {
        cost = optimalBSTCost(freq, i, r - 1) + optimalBSTCost(freq, r + 1, j);
        minCost = min(minCost, cost);
    }
    return minCost + fSum;
}
//using DP
int optimalBSTCostDP(int freq[], int n)
{
    int dp[n][n];
    for (int i = 0; i < n; i++)
        dp[i][i] = freq[i];
    int cost;
    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int r = i; r <= j; r++)
            {
                cost = (r > i ? dp[i][r - 1] : 0) + (r < j ? dp[r + 1][j] : 0) + freqSum(freq, i, j);
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[0][n - 1];
} // time complexity O(N^3) space complexity O(N^2)
int main()
{
    int n;
    cin >> n;
    int freq[n];
    for (int i = 0; i < n; i++)
        cin >> freq[i];
    cout << optimalBSTCostDP(freq, n) << endl;
    return 0;
}