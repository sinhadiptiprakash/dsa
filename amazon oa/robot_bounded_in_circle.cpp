#include <bits/stdc++.h>
using namespace std;
//robot bounded in circle
//If your final position is different from starting position after one instruction pass but orientation is same as before then it can 't be bounded. Here' s my simple c++ code :

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
bool isRobotBounded(string instructions)
{
    int x = 0, y = 0, o = 0;
    // o -> 0, 1, 2, 3
    // if final pos after 1 instruction pass is diff but orientation is same then no circle, otherwise circle
    //         ^0
    //      1 < > 3
    //         v2

    for (int i = 0; i < instructions.size(); i++)
    {
        if (instructions[i] == 'G')
        {
            x += dx[o];
            y += dy[o];
        }
        else if (instructions[i] == 'L')
        {
            o = (o + 1) % 4;
        }
        else if (instructions[i] == 'R')
        {
            o = (o - 1 + 4) % 4;
        }
    }
    if ((x != 0 || y != 0) && o == 0)
        return false;
    return true;
}
int main()
{
    return 0;
}