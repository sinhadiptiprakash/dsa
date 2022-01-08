#include <bits/stdc++.h>
using namespace std;
//recursive
int ncr(int n, int r)
{
    if (r > n)
        return 0;
    if (n == r || r == 0)
        return 1;
    return ncr(n - 1, r - 1) + ncr(n - 1, r);
}
//bottom up
int ncrBU(int n, int k)
{
    int C[n + 1][k + 1] = {0};
    int i, j;
    const int mod = 1e9 + 7;
    // Calculate value of Binomial Coefficient
    // in bottom up manner
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= min(i, k); j++)
        {
            // Base Cases
            if (j == 0 || j == i)
                C[i][j] = 1;
            // Calculate value using previously
            // stored values
            else
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
        }
    }

    return C[n][k];
}
int main()
{
    int n, r;
    cin >> n >> r;
    cout << ncrBU(n, r) << endl;
    return 0;
}