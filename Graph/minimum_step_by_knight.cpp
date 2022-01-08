#include <bits/stdc++.h>
using namespace std;
/*
Approach: 
    This problem can be seen as shortest path in unweighted graph. 
    Therefore we use BFS to solve this problem. We try all 8 possible positions 
    where a Knight can reach from its position. If reachable position is not already visited 
    and is inside the board, we push this state into queue with distance 1 more than its parent state. 
    Finally we return distance of target position, when it gets pop out from queue.
*/

//for getting the next directions below three vectors are used
vector<int> col_dir = {2, 2, -2, -2, 1, 1, -1, -1};
vector<int> row_dir = {-1, 1, 1, -1, 2, -2, 2, -2};

bool isValid(int n, int r, int c)
{
    if (r >= 1 && r <= n && c >= 1 && c <= n)
        return true;
    return false;
}
//using BFS

int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
{
    vector<vector<bool>> visited(N + 1, vector<bool>(N + 1, 0));
    int res = INT_MAX;
    queue<vector<int>> q;
    // x,y,distance from its previous cell which this cell came from
    q.push({KnightPos[0], KnightPos[1], 0});
    vector<int> temp;
    int r, c, dis, new_r, new_c;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        r = temp[0], c = temp[1], dis = temp[2];
        visited[r][c] = 1;
        if (r == TargetPos[0] && c == TargetPos[1])
            return dis;
        for (int i = 0; i < 8; i++)
        {
            new_r = r + row_dir[i];
            new_c = c + col_dir[i];
            if (isValid(N, new_r, new_c) && !visited[new_r][new_c])
            {
                q.push({new_r, new_c, dis + 1});
                visited[new_r][new_c] = true;
            }
        }
    }
    return INT_MAX;
}
int main()
{
    int n;
    cin >> n;
    vector<int> knightPos(2);
    vector<int> targetPos(2);
    for (int i = 0; i < 2; i++)
        cin >> knightPos[i];
    for (int i = 0; i < 2; i++)
        cin >> targetPos[i];
    cout << minStepToReachTarget(knightPos, targetPos, n) << endl;
    return 0;
}