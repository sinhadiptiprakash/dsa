#include <bits/stdc++.h>
using namespace std;
struct Item
{
    int value;
    int weight;
};
static bool cmp(struct Item i1, struct Item i2)
{
    double vw1 = (double)i1.value / i1.weight;
    double vw2 = (double)i2.value / i2.weight;
    return vw1 > vw2;
}

double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr, arr + n, cmp);
    double fVal = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i].weight <= W)
        {
            fVal += arr[i].value;
            W -= arr[i].weight;
        }

        else
        {
            double priceperWt = (double)arr[i].value / arr[i].weight;
            fVal += priceperWt * W;
            break;
        }
    }

    return fVal;
} //though this solution is not accepted in gfg its correct ans because even code in gfg is not accepted by themselve
//output of both code is same
int main()
{
    Item arr[] = {{100, 20}, {60, 10}, {120, 30}};
    int n = sizeof(arr) / sizeof(Item);
    int w = 50;
    cout << fractionalKnapsack(w, arr, n) << endl;
    return 0;
}