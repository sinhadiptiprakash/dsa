#include<bits/stdc++.h>
using namespace std;
int dp[101][101];
// recursive approach
int editDistance(string str1,int m,string str2,int n){
    if(m==0 || n==0)
        return max(m, n);
    if(str1[m-1]==str2[n-1])
        return editDistance(str1, m - 1, str2, n - 1);
    else
        return min(1 + editDistance(str1, m - 1, str2, n - 1), min(1 + editDistance(str1, m - 1, str2, n), 1 + editDistance(str1, m, str2, n - 1)));
}
// memoization
int editDistanceMemo(string str1,int m,string str2,int n){
    if (m == 0 || n == 0)
        return max(m, n);
    if(dp[m][n]!=-1)
        return dp[m][n];
    if (str1[m - 1] == str2[n - 1])
        return editDistanceMemo(str1, m - 1, str2, n - 1);
    else
        return dp[m][n]=min(1 + editDistanceMemo(str1, m - 1, str2, n - 1), min(1 + editDistanceMemo(str1, m - 1, str2, n), 1 + editDistance(str1, m, str2, n - 1)));
}
// bottom up
int editDistanceBU(string str1,string str2){
    int m = str1.length();
    int n = str2.length();
    int table[m + 1][n + 1] = {0};
    for (int i = 0; i <= m;i++){
        for (int j = 0; j <= n;j++){
            if(i==0 || j==0)
                table[i][j] = max(i, j);
        }
    }
    for (int i = 1; i <= m;i++){
        for (int j = 1; j <= n;j++){
            if(str1[i-1]==str2[j-1])
                table[i][j] = table[i - 1][j - 1];
            else{
                table[i][j] = min(1 + table[i - 1][j - 1], min(1 + table[i - 1][j], 1 + table[i][j - 1]));
            }
        }
    }
    return table[m][n];
}
int main(){
    string str1, str2;
    cin >> str1 >> str2;
    // memset(dp, -1, sizeof(dp));
    // cout << editDistanceMemo(str1, str1.length(), str2, str2.length()) << endl;
    cout << editDistanceBU(str1, str2) << endl;
    return 0;
}