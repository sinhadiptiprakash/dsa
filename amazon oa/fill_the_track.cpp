#include <bits/stdc++.h>
using namespace std;
bool comp(const vector<int> &a, const vector<int> &b)
{
    return a[1] > b[1];
}
int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
{
    sort(boxTypes.begin(), boxTypes.end(), comp);
    int n = boxTypes.size();
    int res = 0;
    for (int i = 0; i < n && truckSize; i++)
    {
        if (boxTypes[i][0] <= truckSize)
        {
            res += boxTypes[i][0] * boxTypes[i][1];
            truckSize -= boxTypes[i][0];
        }
        else
        {
            res += boxTypes[i][1] * truckSize;
            truckSize = 0;
        }
    }
    return res;
}
int main()
{
    int n, truckSize;
    cin >> n;
    vector<vector<int>> boxTypes(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> boxTypes[i][0] >> boxTypes[i][1];
    }
    cin >> truckSize;
    cout << maximumUnits(boxTypes, truckSize) << endl;
    return 0;
}