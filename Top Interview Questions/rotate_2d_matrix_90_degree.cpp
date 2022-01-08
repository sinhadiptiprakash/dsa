#include <bits/stdc++.h>
using namespace std;
//approach 1
//take an extra matrix and store the rotated matrix at that matrix like top-row goes to the right-colum and so on
//this will take O(N^2) time and and O(N^2) space as well
//approach 2
//1.transpose the whole matrix in place i.e. make rows into colums and vice versa
// or we can transpose the matrix by reversing the matrix diagonals
//2.reverse each row of the transposed matrix
//transposing by swapping the matrix[i][j] with matrix[j][i]
void transpose(vector<vector<int>> &matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        //below we start j from i to avoid transposing already transpssed pairs
        for (int j = i; j < col; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}
//below is the function for reversing a row of a matrix
void reverse(vector<int> &row, int n)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        swap(row[i++], row[j--]);
    }
}
void rotate_2d_matrix2(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    //transposing the matrix i.e. swapping matrix[i][j] with matrix[j][i]
    transpose(matrix, row, col);
    //reverse each row from top to bottom in the transposed matrix
    for (int i = 0; i < row; i++)
    {
        //reversing this row
        reverse(matrix[i], col);
    }
    //now we have the 90 degree rotated matrix
} //time complexity O(N^2) space complexity O(1)

int main()
{
    int row, col;
    cin >> row >> col;
    vector<vector<int>> matrix(row, vector<int>(col));
    //taking matrix data
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> matrix[i][j];
        }
    }
    //rotating the matrix
    rotate_2d_matrix2(matrix);
    //printing the matrix
    cout << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}