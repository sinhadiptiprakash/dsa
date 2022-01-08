#include <bits/stdc++.h>
using namespace std;
bool isValid(vector<vector<char>> &board, int row, int col, char number)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == number || board[i][col] == number)
        {
            return false;
        }
    }
    int rowStart = (row / 3) * 3;
    int colStart = (col / 3) * 3;

    for (int x = rowStart; x < rowStart + 3; x++)
    {
        for (int y = colStart; y < colStart + 3; y++)
        {
            if (board[x][y] == number)
            {
                return false;
            }
        }
    }
    return true;
}
bool solve(vector<vector<char>> &board, int row, int col)
{
    if (row < 9 && col == 9)
    {
        row++;
        col = 0;
    }
    if (row == 9)
        return true;
    if (board[row][col] != '.')
        return solve(board, row, col + 1);

    for (char digit = '1'; digit <= '9'; digit++)
    {
        if (isValid(board, row, col, digit))
        {
            board[row][col] = digit;
            if (solve(board, row, col + 1))
                return true;
            board[row][col] = '.';
        }
    }

    return false;
}
void solveSudoku(vector<vector<char>> &board)
{
    solve(board, 0, 0);
}
int main()
{
    return 0;
}