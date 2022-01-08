#include <bits/stdc++.h>
using namespace std;
// dp
long long int numOfWays(int n)
{
    long long int table[n + 1], i;
    memset(table, 0, sizeof(table));
    table[0] = 1;
    long long int arr[] = {3, 5, 10};
    for (int i = 0; i < 3; i++)
    {
        for (int j = arr[i]; j <= n; j++)
        {
            table[j] += table[j - arr[i]];
        }
    }
    return table[n];
}
int main()
{
    int n;
    cin >> n;
    cout << numOfWays(n) << endl;
    return 0;
}