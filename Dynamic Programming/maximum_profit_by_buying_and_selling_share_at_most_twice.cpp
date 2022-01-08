#include <bits/stdc++.h>
using namespace std;
//using dp
int maximumProfit(vector<int> &price)
{
    int n = price.size();
    int buyPrice, sellPrice;
    int dp[n];
    dp[n - 1] = 0;
    sellPrice = price[n - 1];
    // now dp[i] will store maximum profit by buying and selling shares within ith day to n-1 th day
    // so we have to start the loop from the right side
    for (int i = n - 2; i >= 0; i--)
    {
        sellPrice = max(sellPrice, price[i]);
        // buying price is the price[i]
        dp[i] = max(dp[i + 1], sellPrice - price[i]);
    }
    buyPrice = price[0];
    //now as dp[i] stores maximum profit from ith day to n-1 th day
    // so if we find the maximum profit from 0 to i-1 th day and sum them up we get maximum profit
    // now we are getting the maximum profit by buying and selling within 0 to ith day and adding it with maximum profit from i to n-1 day
    for (int i = 1; i < n; i++)
    {
        buyPrice = min(buyPrice, price[i]);
        dp[i] = max(dp[i - 1], dp[i] + (price[i] - buyPrice));
    }
    return dp[n - 1];
}
int main()
{
    int n;
    cin >> n;
    vector<int> price(n);
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    cout << maximumProfit(price) << endl;
    return 0;
}