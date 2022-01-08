#include <bits/stdc++.h>
using namespace std;
//to understand the below approach watch algoexpert video
// we will be using dp to solve this we will use a dp table profit[k][n]
/*
profit[t][d] will store the maximum profit at dth day by doing at most t transactions
for filling the profit[t][d] the following reccurence relation will be used
profit[t][d]=max(profit[t][d-1],
            price[d]-price[m] for all m,(0<=m<d)
            )
the first term 'profit[t][d-1]' indicates that we are not doing any transaction on the curent dth day
the second trm 'price[d]-price[m] for all m,(0<=m<d)' indicates that we are transacting on this curent dth day
i.e. we are selling a stock on the jth day which we bought at mth day
and if we do a transaction at this jth day, the profit we will get will be price at this day -price of mth day
+ profit[t-1][m] i.e. profit at mth day by doing at most t-1 transactions
*/
int maxProfit(int n, int k, int prices[])
{
    int profit[k + 1][n];
    //initialization
    for (int t = 0; t <= k; t++)
        profit[t][0] = 0;
    for (int d = 0; d < n; d++)
        profit[0][d] = 0;
    for (int t = 1; t <= k; t++)
    {
        for (int d = 1; d < n; d++)
        {
            //we are not doing any transaction on the jth day
            profit[t][d] = profit[t][d - 1];
            for (int m = 0; m < d; m++)
            {
                profit[t][d] = max(profit[t][d], prices[d] - prices[m] + profit[t - 1][m]);
            }
        }
    }
    return profit[k][n - 1];
} //time complexity O(k*n^2) space O(n*k)
//optimized solution
// to understand this optimization watch algoexpert's video at time stamp 23:40
int maxProfit(int n, int k, int prices[])
{
    int profit[k + 1][n + 1];
    memset(profit, 0, sizeof profit);

    for (int t = 1; t <= k; t++)
    {
        //this is the part of the time optimization
        int maxSofar = INT_MIN;
        for (int d = 1; d <= n; d++)
        {
            // this is the part of the time optimization
            maxSofar = max(maxSofar, profit[t - 1][d - 1] - prices[d - 1]);
            profit[t][d] = profit[t][d - 1];
            profit[t][d] = max(profit[t][d], prices[d - 1] + maxSofar);
        }
    }
    return profit[k][n];
}
int main()
{
    int n, k;
    cin >> n >> k;
    int prices[n];
    for (int i = 0; i < n; i++)
        cin >> prices[i];
    cout << maxProfit(n, k, prices) << endl;
    return 0;
}