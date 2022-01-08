#include <bits/stdc++.h>
using namespace std;
int longestIncreasingSubsequence(int a[], int n)
{
    int dp[n];
    for (int i = 0; i < n; i++)
        dp[i] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            // checking if adjacent is differ by one if we consider a[j] as the last element of the subsequence
            // that has a[i] as last element
            if (abs(a[i] - a[j]) == 1)
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    int maxLen = 1;
    for (int i = 0; i < n; i++)
        maxLen = max(maxLen, dp[i]);
    return maxLen;
} // time O(N^2) space O(N)

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << longestIncreasingSubsequence(a, n) << endl;
    return 0;
}