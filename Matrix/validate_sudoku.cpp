#include <bits/stdc++.h>
using namespace std;
bool checkRow(const vector<vector<char>> &board, int row)
{
    vector<bool> isPresent(10, false);
    for (auto col = 0; col < 9; ++col)
    {
        if (board[row][col] != '.')
        {
            if (isPresent[board[row][col] - '0'])
                return false;
            isPresent[board[row][col] - '0'] = true;
        }
    }
    return true;
}
bool checkCol(const vector<vector<char>> &board, int col)
{
    vector<bool> isPresent(10, false);
    for (auto row = 0; row < 9; ++row)
    {
        if (board[row][col] != '.')
        {
            if (isPresent[board[row][col] - '0'])
                return false;
            isPresent[board[row][col] - '0'] = true;
        }
    }
    return true;
}
bool checkGrid(const vector<vector<char>> &board, int grid)
{
    vector<bool> isPresent(10, false);
    int row = 3 * (grid / 3);
    int col = 3 * (grid % 3);
    for (auto r = row; r < row + 3; ++r)
    {
        for (auto c = col; c < col + 3; ++c)
        {
            if (board[r][c] != '.')
            {
                if (isPresent[board[r][c] - '0'])
                    return false;
                isPresent[board[r][c] - '0'] = true;
            }
        }
    }
    return true;
}
bool isValidSudoku(vector<vector<char>> &board)
{
    for (auto i = 0; i < 9; ++i)
    {
        if (!(checkGrid(board, i) && checkCol(board, i) && checkRow(board, i)))
            return false;
    }
    return true;
}
int main()
{
    return 0;
}