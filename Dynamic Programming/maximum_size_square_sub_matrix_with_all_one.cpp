#include <bits/stdc++.h>
using namespace std;
//using dp
int maxSquare(int n,int m,vector<vector<int>> &mat){
    int dp[n][m];
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m;j++){
            if(i==0 || j==0)
                dp[i][j] = mat[i][j];
            else if(mat[i][j]==1){
                dp[i][j] = mat[i][j] + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            }
            else
                dp[i][j] = 0;
            mx = max(mx, dp[i][j]);
        }
    }
    return mx;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            cin >> mat[i][j];
        }
    }
    cout << maxSquare(n, m, mat) << endl;
    return 0;
}