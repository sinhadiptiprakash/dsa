#include <bits/stdc++.h>
using namespace std;
pair<int, int> getCoordinate(int num, int n)
{
    //get row from top
    int rowtop = (num - 1) / n;
    //get row from bottom
    int rowbottom = n - 1 - rowtop;
    int col = (num - 1) % n;
    if (n % 2 == rowbottom % 2)
        col = n - 1 - col;
    return {rowbottom, col};
}
int snakesAndLadders(vector<vector<int>> &board)
{
    int n = board.size();
    vector<bool> visited((n * n) + 1, 0);
    queue<pair<int, int>> q;
    q.push({1, 0});
    visited[1] = true;
    while (!q.empty())
    {
        auto temp = q.front();
        int num = temp.first;
        int steps = temp.second;
        q.pop();
        if (num == n * n)
            return steps;
        for (int j = 1; num + j <= n * n && j <= 6; j++)
        {
            int nextNum = num + j;
            auto p = getCoordinate(nextNum, n);
            int row = p.first;
            int col = p.second;
            if (board[row][col] != -1)
                nextNum = board[row][col];
            if (!visited[nextNum])
            {
                visited[nextNum] = true;
                q.push({nextNum, steps + 1});
            }
        }
    }
    return -1;
}
int main()
{
    int n = 6;
    vector<vector<int>> board(n, vector<int>(n, -1));
    board[5][1] = 15;
    board[3][4] = 13;
    board[3][1] = 35;
    cout << snakesAndLadders(board) << endl;
    return 0;
}