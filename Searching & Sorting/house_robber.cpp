#include <bits/stdc++.h>
using namespace std;
// using dynamic programming approach
int house_robber(vector<int> a)
{
    int n = a.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return a[0];
    int dp[n] = {0};
    dp[0] = a[0];
    dp[1] = (dp[0] > a[1] ? dp[0] : a[1]);
    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
    }
    return dp[n - 1];
} //time complexity O(N) space complexity O(N)
/*
Efficient Approach: By carefully observing the DP array, it can be seen that the values of previous two indices matter 
while calculating the value for an index. To replace the total DP array by two variables.
*/
int house_robber_efficient(vector<int> a)
{
    int n = a.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return a[0];
    int before_prev = a[0], prev = (a[0] > a[1] ? a[0] : a[1]), temp;
    for (int i = 2; i < n; i++)
    {
        temp = prev;
        prev = max(before_prev + a[i], prev);
        before_prev = temp;
    }
    return prev;
} //time complexity O(N) space complexity O(1)
int main()
{
    vector<int> a = {1, 2, 3, 1};
    cout << house_robber_efficient(a) << endl;
    return 0;
}