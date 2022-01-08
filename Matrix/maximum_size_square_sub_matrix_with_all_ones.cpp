#include <bits/stdc++.h>
using namespace std;
//below is the dynamic programming approach for the problem for better under standing have a dry run
//returns the area of the maximum square sub-matrix
int max_square_sub_matrix_with_ones(vector<vector<int>> matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    int dp[row + 1][col + 1];
    //at first copy the first row and first column from the matrix to the dp table as it is
    for (int i = 0; i < col; i++)
        dp[0][i] = matrix[0][i];
    // copying the first column
    for (int i = 0; i < row; i++)
        dp[i][0] = matrix[i][0];
    // for other cases we use the dynamic programming
    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            if (matrix[i][j])
            {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
            else
                dp[i][j] = 0;
        }
    }
    //so far we have stored the maximum size square sub-matrix i.e. dp[row][col] will store
    //the length of the maximum size square sub-matrix with all one
    int max_len = dp[0][0], max_i=0, max_j=0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (dp[i][j] > max_len)
            {
                max_len = dp[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }
    // printing the maximum square sub-matrix
    cout << "maximum size square sub-matrix" << endl;
    for (int i = max_i; i > max_i - max_len; i--)
    {
        for (int j = max_j; j > max_j - max_len; j--)
        {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
    //return the maximum area
    return max_len * max_len;
}
int main()
{
    int row, col;
    cin >> row >> col;
    vector<vector<int>> matrix(row, vector<int>(col));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> matrix[i][j];
        }
    }
    int max_area = max_square_sub_matrix_with_ones(matrix);
    cout << max_area << endl;
}