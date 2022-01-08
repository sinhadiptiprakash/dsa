#include <bits/stdc++.h>
using namespace std;
//maximum profit by buying and selling stocks at most k times
int maxProfit(vector<int> &prices, int k)
{

    //for first buy---> to ensure we are buying a stock at lesser price we need to maximise the amount of money left with us after buying therefore we try to maximise the first buy {similarly for first sell,second buy, second sell}

    // after completing the 4 transactions whatever is left with us is our profit

    int buy = INT_MIN, sell = 0;
    int n = prices.size();
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < k; j++)
        {
            buy = max(buy, sell - prices[i]);
            sell = max(sell, buy + prices[i]);
        }
    }
    return sell;
}

int main()
{
    int n,k;
    cin >> n>>k;
    vector<int> prices(n);
    for(int i=0;i<n;i++){
        cin >> prices[i];
    }
    cout << maxProfit(prices, k) << endl;
    return 0;
}