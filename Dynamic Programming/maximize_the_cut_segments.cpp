#include <bits/stdc++.h>
using namespace std;
//recursive approach
int maximumSegments(int n, int x, int y, int z)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return INT_MIN;
    return max(1 + maximumSegments(n - x, x, y, z), max(1 + maximumSegments(n - y, x, y, z), 1 + maximumSegments(n - z, x, y, z)));
}
// top down
int dp[10001];
int maximumSegments(int n, int x, int y, int z)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return INT_MIN;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = max(1 + maximumSegments(n - x, x, y, z), max(1 + maximumSegments(n - y, x, y, z), 1 + maximumSegments(n - z, x, y, z)));
}
//bottom up DP
int maximumSegmentsBU(int n, int x, int y, int z)
{
    int table[n + 1];
    table[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        table[i] = -1;
        if (x <= i)
            table[i] = max(table[i], table[i - x]);
        if (y <= i)
            table[i] = max(table[i], table[i - y]);
        if (z <= i)
            table[i] = max(table[i], table[i - z]);
        if (table[i] != -1)
            table[i]++;
    }
    return max(0, table[n]);
}
int main()
{
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    cout << maximumSegmentsBU(n, x, y, z) << endl;
    return 0;
}