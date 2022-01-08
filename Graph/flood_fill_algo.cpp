#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> col_dir = {0, 0, -1, 1};
    vector<int> row_dir = {-1, 1, 0, 0};
    bool isValid(int m, int n, int sr, int sc)
    {
        if (sr >= 0 && sr < m && sc >= 0 && sc < n)
            return true;
        return false;
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int m = image.size();
        int n = image[0].size();
        pair<int, int> temp;
        int x, y;
        int startingColor = image[sr][sc];
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            x = temp.first, y = temp.second;
            image[x][y] = newColor;
            for (int i = 0; i < 4; i++)
            {
                int new_x = x + row_dir[i];
                int new_y = y + col_dir[i];
                if (isValid(m, n, new_x, new_y) && image[new_x][new_y] == startingColor && image[new_x][new_y] != newColor)
                    q.push({new_x, new_y});
            }
        }
        return image;
    }
};