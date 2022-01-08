#include <bits/stdc++.h>
using namespace std;
//this problem can be solved using some concepts: 1. BFS using Queue, 2.Finding no. of levels of a graph/tree using BFS/Level Order Traversal
/*
Approach:
If we find a 2 in a cell i.e. a rotten orange in a cell we have to make all the adjacent un-rotten oranges of it as rotten
    we always push all the newly rotten oranges to the queue for the next day.
    For getting the adjacent oranges and their directions we will be using a direction vector of pair<int,int>.
At first we will enqueue co-ordinates of all the rotten oranges in the queue and we are interested to find out the no. of
    levels in this graph/tree i.e. no. of day, after enquueing all the rotten oranges to the queue we enqueue a pair {-1,-1} as
    an indication of the end of the level/day. 
and continue like BFS.
If we get the {-,-1} pair then we should increase the day count and again enqueue a {-1,-1} pair as an indication of the end of the day
After the BFS we again traverse the whole grid to check if there is any un-rotten orrages if so then we return -1 otherwise
we return days count or level count
*/
class Solution
{
public:
    //for checking if the co-ordinate i,j lies within the grid or not
    bool isvalid(int i, int j, int m, int n)
    {
        if (i < 0 || j < 0 || i >= m || j >= n)
            return false;
        return true;
    }

    int orangesRotting(vector<vector<int>> &grid)
    {

        int m = grid.size(), n = grid[0].size();
        //q stores the co-ordinates of the rotten oranges
        queue<pair<int, int>> q;
        //directions vector stores the direction-changing co-ordinates to get the adjacent cells of a particular cell
        //For example curent co-ordinates+{-1,0} denotes going up, cuent co-ordinates+{1,0} denotes going down and so on
        vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        // at first we enqueue co-ordinates of all rotten oranges in the queue as a first step for the BFS
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        //we push -1,-1 to indicate the end of a level i.e. end of a day
        q.push({-1, -1});
        //before start of BFS the no days has been spent so the days=0
        int days = 0;
        while (!q.empty())
        {
            // we first store the front of the q and dequeue the queue
            pair<int, int> curent = q.front();
            q.pop();
            // now if curent co-ordinate is a {-1,-1} pair then it is an indication of one of the two situation
            //1.end of the curent day
            //2. end of the bfs
            if (curent.first == -1 && curent.second == -1)
            {
                // if the q is not empty then we again enqueue a pair {-1,-1} to the queue as an indication of the end of the level/day
                if (!q.empty())
                {
                    q.push({-1, -1});
                    //also as its an end of curent day
                    days += 1;
                }
                else // we are done with our BFS there is no more oranges to be checked
                    break;
            }
            else // if the curent co-ordinate is not a {-1,-1} pair
            {
                //we go every direction to get the adjacent cells of this co-ordinate
                for (int i = 0; i < 4; i++)
                {
                    // we add the x part of directions[i] to x and y part to y of the curent co-ordinate
                    // to get the co-ordinate of the adjacent cells
                    int x = curent.first + directions[i].first;
                    int y = curent.second + directions[i].second;
                    // if the got co-ordinate is a valid one and is an un-rotten orange
                    if (isvalid(x, y, m, n) && grid[x][y] == 1)
                    {
                        //we first make it as rotten and then enqueue this co-ordinte into the queue
                        //as it will rot other adjacent oranges in the next day
                        q.push({x, y});
                        grid[x][y] = 1 + grid[curent.first][curent.second];
                    }
                    //other wise if it is an empty cell we dont do anything and just continue
                    // and for the rotten oranges we already have them in our queue
                }
            }
        }
        // now we have claculated the no. of days to rott all the adjacent oranges of all rotten oranges
        // now if there is a un-rotten orange in the grid then that means the rotten oranges are failed to rot all the oranges
        //so we should return -1 in this case
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    return -1;
            }
        }
        return days;
    }
};
int main()
{
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    vector<vector<int>> grid2 = {{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};
    Solution s;
    cout << s.orangesRotting(grid) << endl;
    return 0;
}