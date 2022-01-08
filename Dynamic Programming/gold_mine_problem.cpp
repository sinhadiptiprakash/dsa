#include <bits/stdc++.h>
using namespace std;
bool isvalid(int i, int j, int n, int m)
{
    if (i >= 0 && i < n && j >= 0 && j < m)
        return true;
    return false;
}
int goldMine(vector<vector<int>> &matrix, int n, int m)
{
    int dp[n][m];
    // initializing the first column of dp
    for (int i = 0; i < n; i++)
        dp[i][0] = matrix[i][0];
    int leftUp, leftDown;
    // for each column we traverse each row and that's why the i loop i.e. row loop is nested inside the column loop
    for (int j = 1; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            // if the left Upper cell is not out of the matrix then fill this with dp value of this cell,
            // otherwise INT_MIN
            leftUp = (isvalid(i - 1, j - 1, n, m) ? dp[i - 1][j - 1] : INT_MIN);
            // similarly for other
            leftDown = (isvalid(i + 1, j - 1, n, m) ? dp[i + 1][j - 1] : INT_MIN);
            dp[i][j] = matrix[i][j] + max(dp[i][j - 1], max(leftUp, leftDown));
        }
    }
    // as the rightmost column will store the results
    // so to get the maximum amount of gold we have to traverse the last column
    int res = dp[0][m - 1];
    for (int i = 1; i < n; i++)
    {
        res = max(res, dp[i][m - 1]);
    }
    return res;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];
    }
    cout << goldMine(matrix, n, m) << endl;
    return 0;
}