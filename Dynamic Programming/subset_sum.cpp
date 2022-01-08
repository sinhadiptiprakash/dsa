#include<bits/stdc++.h>
using namespace std;
//recuresivve approach
bool subsetSum(int a[],int n,int sum){
    if(sum==0)
        return true;
    if(n==0)
        return false;
    if(a[n-1]<=sum)
        return subsetSum(a, n - 1, sum) || subsetSum(a, n - 1, sum - a[n - 1]);
    return subsetSum(a, n - 1, sum);
}
//bottom up
bool subsetSumBU(int a[],int n,int sum){
    bool dp[n+1][sum+1];
    for (int i = 0; i <= sum;i++)
        dp[0][i] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= sum;j++){
            if(a[i-1]<=sum)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}
int main(){
    int n,sum;
    cin >> n>>sum;
    int a[n];
    for (int i = 0; i < n;i++)
        cin >> a[i];
    cout << subsetSumBU(a, n, sum) << endl;
    return 0;
}