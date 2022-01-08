#include <bits/stdc++.h>
using namespace std;
// below approach is
// 1. create a profit array of same size as the price array
// 2. traverse the price array from right to left and for every i store the maximum profit at that point
//      in this way the profit[0] will store the max_profit after buying and selling for 1 time
// 3. traverse the price array from left to right and for every i store the maximum profit at that point
//      by comparing with the max_profit computed at step 2
//      in this way the profit[n-1] will store the max_profit after buying and selling for at most 2 times
// N.B. we in 3 rd step we compare the total profit by summing the new with the profit computed at step 2
int maximum_profit_by_buying_selling_share_at_most_twice(int price[], int n)
{
    //creating a temporary array using dynamic memory allocation
    int *profit = new int[n];
    //initializing every element as 0
    for (int i = 0; i < n; i++)
        profit[i] = 0;
    //traversing the price array from right to left
    int selling_price = price[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        // updating the selling price if we get a higher price than before
        selling_price = max(selling_price, price[i]);
        // updating the profit[i] with maximum of its previous profit i.e. profit[i+1] and profit by buying with the price[i]
        profit[i] = max(profit[i + 1], selling_price - price[i]);
    }
    //traversing the price array from left to right
    int buy_price = price[0];
    for (int i = 1; i < n; i++)
    {
        // updating the buying price if we get a lower price than before
        buy_price = min(buy_price, price[i]);
        // Maximum profit is maximum of:
        // a) previous maximum, i.e., profit[i-1]
        // b) (Buy, Sell) at (min_price, price[i]) and add
        //    profit of other trans. stored in profit[i]
        profit[i] = max(profit[i - 1], profit[i] + (price[i] - buy_price));
    }
    int result = profit[n - 1];
    delete[] profit; // To avoid memory leak
    return result;
} //time complexity O(N) and space complexity o(N)
int maxProfit(vector<int> &pri)
{

    //for first buy---> to ensure we are buying a stock at lesser price we need to maximise the amount of money left with us after buying therefore we try to maximise the first buy {similarly for first sell,second buy, second sell}

    // after completing the 4 transactions whatever is left with us is our profit

    int fb = INT_MIN, sb = INT_MIN;
    int fs = 0, ss = 0;

    for (int i = 0; i < pri.size(); i++)
    {

        fb = max(fb, -pri[i]);     //since this is first buy and im paying therefore consider negation of pri[i]
        fs = max(fs, fb + pri[i]); //money left from first buy + money i get from selling this particular stock
        sb = max(sb, fs - pri[i]); // money left from prev transac - if i buy current stock (since buying so neative)
        ss = max(ss, sb + pri[i]); // money left after sb + if i sell at this price[i]
    }
    return ss;
}
int main()
{
    int price[] = {10, 22, 5, 75, 65, 80};
    int n = sizeof(price) / sizeof(price[0]);
    int price2[] = {1, 5, 1};
    cout << maximum_profit_by_buying_selling_share_at_most_twice(price2, 3) << endl;
    return 0;
}