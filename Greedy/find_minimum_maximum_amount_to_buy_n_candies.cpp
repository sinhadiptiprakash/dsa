#include <bits/stdc++.h>
using namespace std;
pair<int, int> buy_candies(int candies[], int n, int k)
{
    sort(candies, candies + n);
    int min_money = 0, max_money = 0;
    int buy = 0, free = n;
    while (buy < free)
    {
        min_money += candies[buy++];
        free -= k;
    }
    buy = n - 1, free = 0;
    while (free <= buy)
    {
        max_money += candies[buy--];
        free += k;
    }
    return {min_money, max_money};
}
int main()
{
    int candies[] = {3, 2, 1, 4, 5};
    int n = sizeof(candies) / sizeof(int);
    auto res = buy_candies(candies, n, 4);
    cout << res.first << ' ' << res.second << endl;
    return 0;
}