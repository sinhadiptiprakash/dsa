#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfitLeetCode(vector<int> &prices)
    {
        int buyingPrice = INT_MAX;
        int maxprofit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            //if we get a lower price than before we will update the buyingPrice because it might be our buying price
            if (prices[i] < buyingPrice)
                buyingPrice = prices[i];
            //we always check and update the maxProfit
            else if (prices[i] - buyingPrice > maxprofit)
                maxprofit = prices[i] - buyingPrice;
        }
        return maxprofit;
    }
};
int main()
{
    return 0;
}