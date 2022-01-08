#include <bits/stdc++.h>
using namespace std;
//recursive
int unboundedKnapsack(int val[], int wt[], int n, int w)
{
    if (n == 0 || w == 0)
        return 0;
    if (wt[n - 1] <= w)
        return max(val[n - 1] + unboundedKnapsack(val, wt, n, w - wt[n - 1]), unboundedKnapsack(val, wt, n - 1, w));
    return unboundedKnapsack(val, wt, n - 1, w);
}
//bottom up
int unboundedKnapsackDP(int val[], int wt[], int n, int w)
{
    int dp[n + 1][w + 1];
    for (int i = 0; i <= w; i++)
        dp[0][i] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (wt[i - 1] <= j)
                dp[i][j] = max(val[i - 1] + dp[i][j - wt[i - 1]], dp[i - 1][j]);
        }
    }
    return dp[n][w];
}
int main()
{
    int n, w;
    cin >> n >> w;
    int val[n], wt[n];
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    cout << unboundedKnapsackDP(val, wt, n, w) << endl;
    return 0;
}