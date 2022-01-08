#include <bits/stdc++.h>
using namespace std;
// Since the only options we have are two wheels and four wheels, the number of ways would only increase by 1 on next multiples of 4.

vector<int> findVehicles(vector<int> &vehicles)
{
    int n = vehicles.size();
    for (int i = 0; i < n; i++)
    {
        if (vehicles[i] % 2 != 0)
        {
            vehicles[i] = 0;
            continue;
        }
        int numOfWays = vehicles[i] / 4 + 1;
        vehicles[i] = numOfWays;
    }
    return vehicles;
}
int main()
{
    return 0;
}