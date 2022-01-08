#include <bits/stdc++.h>
using namespace std;
//its a similar approach of Rotten Oranges
class Solution
{
public:
    //checking if i,j is within the grid or not
    bool is_valid(int i, int j, int m, int n)
    {
        if (i < 0 || j < 0 || i >= m || j >= n)
            return false;
        return true;
    }
    vector<vector<int>> nearest(vector<vector<int>> &grid)
    {
        // zero_count is for keeping track of how many zeros are there in grid,
        // which are not got the distance from their nearest cell having 1
        int zero_count = 0;
        int m = grid.size();
        int n = grid[0].size();
        // in resultant for each i,j cell we store the distance of it from its nearest cell having 1
        vector<vector<int>> resultant(m, vector<int>(n, INT_MAX));
        // q will be storing the coordinates of the cells of which distances are calculated i.e. not zero
        queue<pair<int, int>> q;
        // directions is for getting the coordinates of adjacent cells
        vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        // first of all we count how many cells are there having zero in zero_count
        // and if a cell is having 1 we Enqueue its coordinates to the queue
        // and also make resulttant of this cell is 0 indicating distance from itself

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    resultant[i][j] = 0;
                    q.push({i, j});
                }
                else
                    zero_count++;
            }
        }
        // while the q is not empty and we have'nt calculated distances for all the cells having 0
        while (!q.empty() && zero_count > 0)
        {
            // the idea is very simple: we first extract a coordinates from the queue
            // and put its distance+1 in resultant for its all adjacent cells
            // we do so because from a cell to its adjacent is the minimum possible
            auto curent = q.front();
            q.pop();
            // we see up, down, right and left adjacent cells respectively by the help of the directions
            for (int i = 0; i < 4; i++)
            {
                // adjacent's x= curent's x+ directions's x
                int x = curent.first + directions[i].first;
                // adjacent's y= curent's y+ directions's y
                int y = curent.second + directions[i].second;
                // if the adjacent is not outside the grid
                if (is_valid(x, y, m, n))
                {
                    // if distance stored in curent cell+1 is less than the distance stored already in the adjacent cell in resultant
                    // we update its distance in resultant and also Enqueue this coordinates in the queue
                    // we also decreament the zero_count
                    // this step is very much similar to the shortest path in unweighted graph using BFS
                    if (resultant[curent.first][curent.second] + 1 < resultant[x][y])
                    {
                        resultant[x][y] = resultant[curent.first][curent.second] + 1;
                        q.push({x, y});
                        zero_count--;
                    }
                }
            }
        }
        return resultant;
    }
};

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    cout << endl;
    Solution s;
    auto resultant = s.nearest(grid);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << resultant[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}