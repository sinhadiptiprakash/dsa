#include <bits/stdc++.h>
using namespace std;
//for getting the next directions below three vectors are used
vector<int> col_dir = {0, 0, -1, 1};
vector<int> row_dir = {-1, 1, 0, 0};
vector<char> directions = {'U', 'D', 'L', 'R'};

bool isValid(vector<vector<int>> &m, int r, int c)
{
    int n = m.size();
    if (r >= 0 && r < n && c >= 0 && c < n && m[r][c])
        return true;
    return false;
}
//using DFS
void dfs(int r, int c, vector<vector<int>> &m, int n, string temp, vector<string> &res)
{
    if (r == n - 1 && c == n - 1 && m[r][c])
    {
        res.push_back(temp);
        return;
    }
    // we are modifying the matrix to avoid visiting visted cell again
    m[r][c] = 0;
    for (int i = 0; i < 4; i++)
    {
        int new_r = r + row_dir[i];
        int new_c = c + col_dir[i];
        if (isValid(m, new_r, new_c))
        {
            temp.push_back(directions[i]);
            dfs(new_r, new_c, m, n, temp, res);
            // after returning back from the recursive call we should pop out the last character of the temp
            // as now we are exploring a new path from r,c not from new_r,new_c
            temp.pop_back();
        }
    }
    //after exploring all the paths from r,c now we restore the r,c data
    m[r][c] = 1;
}
// main function which returns the vectore of direction-strings
vector<string> ratInAMaze(vector<vector<int>> &m, int n)
{
    vector<string> res;
    // if the matrix is empty or first cell is empty so return {}
    if (n == 0 || !m[0][0])
        return {};
    dfs(0, 0, m, n, "", res);
    return res;
}
int main()
{
    vector<vector<int>> m = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}};
    vector<string> res = ratInAMaze(m, 4);
    return 0;
}