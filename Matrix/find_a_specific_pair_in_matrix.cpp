#include <bits/stdc++.h>
using namespace std;
/*
A simple solution would be to apply Brute-Force. For all values mat(a, b) in the matrix, 
we find mat(c, d) that has maximum value such that c > a and d > b 
and keeps on updating maximum value found so far. We finally return the maximum value.
Below is its implementation. 
*/
// The function returns maximum value A(c,d) - A(a,b)
// over all choices of indexes such that both c > a
// and d > b.
int find_specific_pair_in_matrix_bf(vector<vector<int>> matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    int max_dif = INT_MIN;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            //for every element matrix[i][j] we try to find the matrix[k][l] where k>i && l>j and update max_dif
            for (int k = i + 1; k < row; k++)
            {
                for (int l = j + 1; l < col; l++)
                {
                    max_dif = max(max_dif, matrix[k][l] - matrix[i][j]);
                }
            }
        }
    }
    return max_dif;
} //time complexity O(n^4)
//below is the better approach
/*
An efficient solution uses extra space. 
We pre-process the matrix such that index(i, j) stores max of elements in matrix from (i, j) to (N-1, N-1) 
and in the process keeps on updating maximum value found so far. We finally return the maximum value.
*/
int find_a_specific_pair_in_matrix_efficient(vector<vector<int>> matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    //suffix_max[i][j] stores maixmum from matrix[i][j] to matrix[row-1][col-1]
    int suffix_max[row][col];
    int max_dif = INT_MIN;
    //updating the last row of the suffix_max
    suffix_max[row - 1][col - 1] = matrix[row - 1][col - 1];
    for (int i = col - 2; i >= 0; i--)
    {
        if (matrix[row - 1][i] > suffix_max[row - 1][i + 1])
            suffix_max[row - 1][i] = matrix[row - 1][i];
    }
    //updating the last column
    for (int i = row - 2; i >= 0; i--)
    {
        if (matrix[i][col - 1] > suffix_max[i + 1][col - 1])
            suffix_max[i][col - 1] = matrix[i][col - 1];
    }
    //updating other portion of the matrix as well as max_dif from the bottom
    for (int i = row - 2; i >= 0; i--)
    {
        for (int j = col - 2; j >= 0; j--)
        {
            //updating the max_dif
            if (suffix_max[i + 1][j + 1] - matrix[i][j] > max_dif)
                max_dif = suffix_max[i + 1][j + 1] - matrix[i][j];
            //updating the suffix_max[i][j] on the go
            suffix_max[i][j] = max(matrix[i][j], max(suffix_max[i][j - 1], suffix_max[i - 1][j]));
        }
    }
    return max_dif;
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
    cout << find_specific_pair_in_matrix_bf(matrix) << endl;
}