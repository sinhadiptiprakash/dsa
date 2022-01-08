#include <bits/stdc++.h>
using namespace std;
//for gfg
vector<int> rowIndexes = {-1, -1, 0, 1, 1, 1, 0, -1};
vector<int> colIndexes = {0, 1, 1, 1, 0, -1, -1, -1};
void dfs(vector<vector<char>> &grid, int row, int col, int r, int c)
{
    if (r < 0 || r >= row || c < 0 || c >= col || grid[r][c] != '1')
        return;
    grid[r][c] = '0';
    for (int i = 0; i < 8; i++)
    {
        int newRow = r + rowIndexes[i];
        int newCol = c + colIndexes[i];
        dfs(grid, row, col, newRow, newCol);
    }
}
int numIslands(vector<vector<char>> &grid)
{
    int row = grid.size();
    int col = grid[0].size();
    int islands = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] == '1')
            {
                islands++;
                dfs(grid, row, col, i, j);
            }
        }
    }
    return islands;
}
int main()
{

    return 0;
}