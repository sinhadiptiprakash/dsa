#include <bits/stdc++.h>
using namespace std;
// here we can make as many transaction as we want
int maxProfit(vector<int> &prices)
{
    int maxprofit = 0;
    int n = prices.size();
    for (int i = 1; i < n; i++)
    {
        if (prices[i] > prices[i - 1])
            maxprofit += prices[i] - prices[i - 1];
    }
    return maxprofit;
} //time O(N) space O(1)
int main()
{
    return 0;
}