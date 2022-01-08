#include <bits/stdc++.h>
using namespace std;
vector<int> spiral_traversal_of_matrix(vector<vector<int>> &matrix, int row, int col)
{
    vector<int> res;
    int i, row_start = 0, col_start = 0;
    /* row_start - starting row index
        row - ending row index
        col_start - starting column index
        col - ending column index
        i - iterator
    */
    while (row_start < row && col_start < col)
    {
        //Put the first row from the remaining rows
        for (i = col_start; i < col; ++i)
            res.push_back(matrix[row_start][i]);
        row_start++;
        // Put the last column from the remaining columns
        for (i = row_start; i < row; ++i)
            res.push_back(matrix[i][col - 1]);
        col--;
        // Put the last row from the remaining rows
        if (row_start < row)
        {
            for (i = col - 1; i >= col_start; --i)
                res.push_back(matrix[row - 1][i]);
            row--;
        }

        // Putt the first column from the remaining columns
        if (col_start < col)
        {
            for (i = row - 1; i >= row_start; --i)
                res.push_back(matrix[i][col_start]);
            col_start++;
        }
    }
    return res;
}
// below is the recursive approach printing matrix in spiral order
void spiral_traversal_of_matrix_recursive(vector<vector<int>> matrix, int row_start, int col_start, int row, int col)
{
    // If i or j lies outside the matrix
    if (row_start >= row or col_start >= col)
        return;

    // Print First Row
    for (int p = col_start; p < col; p++)
        cout << matrix[row_start][p] << " ";

    // Print Last Column
    for (int p = row_start + 1; p < row; p++)
        cout << matrix[p][col - 1] << " ";

    // Print Last Row, if Last and First Row are not same
    if ((row - 1) != row_start)
        for (int p = col - 2; p >= col_start; p--)
            cout << matrix[row - 1][p] << " ";

    // Print First Column,  if Last and
    // First Column are not same
    if ((col - 1) != col_start)
        for (int p = row - 2; p > row_start; p--)
            cout << matrix[p][col_start] << " ";
    // recursively call for the next sub-problems
    spiral_traversal_of_matrix_recursive(matrix, row_start + 1, col_start + 1, row - 1, col - 1);
}
int main()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int>> matrix(r, vector<int>(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cin >> matrix[i][j];
    }
    spiral_traversal_of_matrix_recursive(matrix, 0, 0, r, c);
    return 0;
}