#include <bits/stdc++.h>
using namespace std;
//recursive approach
int numOfWaysToChange(int coins[], int m, int money)
{
    if (money == 0)
        return 1;
    if (m == 0)
        return 0;
    if (coins[m - 1] <= money)
        return numOfWaysToChange(coins, m, money - coins[m - 1]) + numOfWaysToChange(coins, m - 1, money);
    return numOfWaysToChange(coins, m - 1, money);
}
//using bottom up dp
long long int count(int coins[], int m, int money)
{
    long long int dp[m + 1][money + 1];
    for (int i = 0; i <= m; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= money; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= money; j++)
        {
            if (coins[i - 1] <= j)
                dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[m][money];
} //time complexity O(M*money) space complexity O(M*money)
long long int countSpaceOptimized(int coins[], int m, int money)
{
    // table[i] will be storing the number of solutions for
    // value i. We need n+1 rows as the table is constructed
    // in bottom up manner using the base case (n = 0)
    int table[money + 1];
    // Initialize all table values as 0
    memset(table, 0, sizeof(table));
    // Base case (If given value is 0)
    table[0] = 1;
    // Pick all coins one by one and update the table[] values
    // after the index greater than or equal to the value of the picked coin
    for (int i = 0; i < m; i++)
        for (int j = coins[i]; j <= money; j++)
            table[j] += table[j - coins[i]];
    return table[money];
} //space complexity O(money)
int main()
{
    int n, money;
    cin >> n >> money;
    int coins[n];
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    cout << count(coins, n, money) << endl;
    return 0;
}