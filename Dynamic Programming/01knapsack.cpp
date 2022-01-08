#include <bits/stdc++.h>
using namespace std;
//recursive approach
int knapsack(int w, int wt[], int val[], int n)
{
    if (n == 0 || w == 0)
        return 0;
    if (wt[n - 1] <= w)
        return max(knapsack(w, wt, val, n - 1), val[n - 1] + knapsack(w - wt[n - 1], wt, val, n - 1));
    return knapsack(w, wt, val, n - 1);
}
//bottom up dp
int knapsackBU(int w,int wt[],int val[],int n){
    int dp[w + 1][n + 1];
    //initializing
    for (int i = 0; i <= w;i++){
        for (int j = 0; j <= n;j++){
            if(i==0 || j==0)
                dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= w;i++){
        for (int j = 1; j <= n;j++){
            if(wt[j-1]<=i)
                dp[i][j] = max(dp[i][j - 1], dp[i - wt[j - 1]][j - 1] + val[j - 1]);
            else
                dp[i][j] = dp[i][j - 1];
        }
    }
    return dp[w][n];
}
int main()
{
    int n, w;
    cin >> n >> w;
    int wt[n], val[n];
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    cout << knapsackBU(w, wt, val, n) << endl;
    return 0;
}