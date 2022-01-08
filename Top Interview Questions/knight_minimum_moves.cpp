#include <bits/stdc++.h>
using namespace std;

// move the obstacle
vector<int> col_dir = {-2, -1, 1, 2, -2, -1, 1, 2};
vector<int> row_dir = {-1, -2, -2, -1, 1, 2, 2, 1};

bool isValid(int n, int r, int c)
{
    if (r >= 1 && r <= n && c >= 1 && c <= n)
        return true;
    return false;
}
//using BFS
//Function to find out minimum steps Knight needs to reach target position.
int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
{
    bool visited[N][N] = {false};
    queue<pair<pair<int, int>, int>> q;
    q.push({{KnightPos[0], KnightPos[1]}, 0});
    int x, y, steps;
    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();
        x = temp.first.first, y = temp.first.second, steps = temp.second;
        if (x == TargetPos[0] && y == TargetPos[1])
            return steps;
        if (!visited[x][y])
        {
            visited[x][y] = true;
            for (int i = 0; i < 8; i++)
            {
                int new_x = x + row_dir[i];
                int new_y = y + col_dir[i];
                if (isValid(N, new_x, new_y) && !visited[new_x][new_y])
                {
                    q.push({{new_x, new_y}, steps + 1});
                }
            }
        }
    }
    return -1;
}
int main()
{
    int N = 30;
    vector<int> knightPos = {4, 5};
    vector<int> targetPos = {1, 1};
    cout << minStepToReachTarget(knightPos, targetPos, N) << endl;
    return 0;
}
