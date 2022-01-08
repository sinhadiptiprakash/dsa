#include <bits/stdc++.h>
using namespace std;
/*
OPTIMAL substructure:
lets dp[i][j] denote the maximum coins when i to j coins are left
now if its my move then 
dp[i][j]=max(
        coins[i]+min(dp[i+2][j],dp[i+1][j-1]),//1st
        coins[j]+min(dp[i,j-2],dp[i+1,j-1]) //2nd 
)
see the Karumanchi Book
*/
int optimalGame(int coins[], int n)
{
    int dp[n][n] = {0};
    for (int i = 0; i < n; i++)
        dp[i][i] = coins[i];
    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i < n - len + 1; i++)
        {
            int j = i + len - 1;
            dp[i][j] = max(coins[i] + min(dp[i + 2][j], dp[i + 1][j - 1]), coins[j] + min(dp[i][j - 2], dp[i + 1][j - 1]));
        }
    }
    return dp[0][n - 1];
}
int main()
{
    int n;
    cin >> n;
    int coins[n];
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    cout << optimalGame(coins, n) << endl;
    return 0;
}