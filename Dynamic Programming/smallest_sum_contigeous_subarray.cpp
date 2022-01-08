#include <bits/stdc++.h>
using namespace std;
int inverseKadane(int a[], int n)
{
    int minSumSofar = a[0], curentSum = a[0];
    for (int i = 1; i < n; i++)
    {
        curentSum = min(curentSum + a[i], a[i]);
        minSumSofar = min(minSumSofar, curentSum);
    }
    return minSumSofar;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << inverseKadane(a, n) << endl;
    return 0;
}