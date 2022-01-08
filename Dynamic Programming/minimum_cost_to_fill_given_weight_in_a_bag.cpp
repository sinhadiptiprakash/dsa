#include <bits/stdc++.h>
using namespace std;
// like unbounded knapsack
int minCost(int a[], int n, int w)
{
    int dp[n + 1][w + 1];
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 1; i <= w; i++)
        dp[0][i] = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (i <= j && a[i - 1] != -1 && dp[i][j - i] != INT_MAX)
            {
                dp[i][j] = min(dp[i][j], a[i - 1] + dp[i][j - i]);
            }
        }
    }
    return dp[n][w] == INT_MAX ? -1 : dp[n][w];
}
int main()
{
    int n, w;
    cin >> n >> w;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << minCost(a, n, w) << endl;
    return 0;
}