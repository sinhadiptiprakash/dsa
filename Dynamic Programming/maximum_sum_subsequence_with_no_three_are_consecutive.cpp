#include <bits/stdc++.h>
using namespace std;
int maximumSum(int a[], int n)
{
    int dp[n];
    dp[0] = a[0];
    dp[1] = dp[0] + a[1];
    dp[2] = max(a[2] + a[1], max(a[2] + a[0], a[0] + a[1]));
    for (int i = 3; i < n; i++)
    {
        dp[i] = max(a[i] + a[i - 1] + dp[i - 3], max(a[i] + dp[i - 2], dp[i - 1]));
    }
    return dp[n - 1];
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << maximumSum(a, n) << endl;
    return 0;
}