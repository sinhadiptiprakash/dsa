#include <bits/stdc++.h>
using namespace std;
//like unbounded knapsack
int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    int dp[n + 1][amount + 1];
    for (int j = 0; j < amount + 1; j++)
        dp[0][j] = INT_MAX - 1;
    for (int i = 1; i < n + 1; i++)
        dp[i][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <=amount; j++)
        {
            if (coins[i - 1] <= j)
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][amount] == INT_MAX - 1 ? -1 : dp[n][amount];
} //TC O(N^2) SC O(N^2)
int coinChange(vector<int> &coins, int amount)
{
    vector<int> v(amount + 1, amount + 1);
    v[0] = 0;
    for (int i = 1; i <= amount; i++)
    {
        for (auto c : coins)
        {
            if (i >= c)
                v[i] = min(v[i], v[i - c] + 1);
        }
    }
    return v.back() > amount ? -1 : v.back();
} //TC O(N^2) SC O(N)

int main()
{
    return 0;
}