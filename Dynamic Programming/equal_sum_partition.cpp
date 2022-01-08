#include <bits/stdc++.h>
using namespace std;
//we will be using subset sum as a subroutine to solve this
//bottom up
bool subsetSum(int a[], int n, int sum)
{
    bool dp[n + 1][sum + 1];
    for (int i = 0; i <= sum; i++)
        dp[0][i] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (a[i - 1] <= sum)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}
bool equalSumPartition(int a[],int n){
    //first of all get the sum of all the array elements
    int sum = 0;
    for (int i = 0; i < n;i++)
        sum += a[i];
    // if the sum is not even, the set can'nt be partitioned into two equal sum
    if (sum & 1)
        return false;
    return subsetSum(a, n, sum / 2);
}
int main()
{
    int n, sum;
    cin >> n >> sum;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << subsetSum(a, n, sum) << endl;
    return 0;
}