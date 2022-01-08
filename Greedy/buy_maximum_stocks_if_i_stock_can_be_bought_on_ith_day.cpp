#include <bits/stdc++.h>
using namespace std;
//using greedy
int buy_maximum_stocks(int price[],int n,int money_in_hand){
    vector<pair<int, int>> price_and_day(n);
    for (int i = 0; i < n;i++){
        price_and_day[i] = {price[i], i+1};
    }
    sort(price_and_day.begin(), price_and_day.end());
    int res = 0;
    for (int i = 0; i < n && money_in_hand>0; i++)
    {
        if(price_and_day[i].first<=money_in_hand){
            int stocks_this_day = min(price_and_day[i].second, money_in_hand / price_and_day[i].first);
            res += stocks_this_day;
            money_in_hand -= price_and_day[i].first * stocks_this_day;
        }
    }
    return res;
}//time complexity O(n*log(n))
int main()
{
    int price[] = {10, 7, 19};
    int n = sizeof(price) / sizeof(price[0]);
    cout << buy_maximum_stocks(price, n, 45) << endl;
    return 0;
}