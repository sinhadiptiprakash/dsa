#include <bits/stdc++.h>
using namespace std;
struct val
{
    int first;
    int second;
};
// we need to sort the pairs first and for that we will be requiring a custom comparator
bool comp(const val &a, const val &b)
{
    return a.first < b.first;
}
int maxChainLength(struct val p[], int n)
{
    int dp[n];
    // we sort the pairs according to the first element
    // Here only applying LIS is not enough because consider the sequence: [{4,5},{2,3}]
    // if we don't sort, then the answer will be 1 but the actual answer would be 2, for that we need to sort
    // and rest of the things are just LIS
    sort(p, p + n, comp);
    for (int i = 0; i < n; i++)
        cout << p[i].first << ' ' << p[i].second << endl;
    for (int i = 0; i < n; i++)
        dp[i] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (p[i].first > p[j].second)
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    int mx = dp[0];
    for (int i = 1; i < n; i++)
        mx = max(mx, dp[i]);
    return mx;
}
int main()
{
    int n;
    cin >> n;
    val p[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].first >> p[i].second;
    }
    cout << maxChainLength(p, n) << endl;
    return 0;
}