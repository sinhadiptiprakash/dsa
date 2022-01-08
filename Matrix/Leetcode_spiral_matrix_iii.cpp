#include <bits/stdc++.h>
using namespace std;
//below is the functions to turn left right up down ,one unit
void turn_left(int &r, int &c)
{
    c -= 1;
}
void turn_right(int &r, int &c)
{
    c += 1;
}
void turn_up(int &r, int &c)
{
    r -= 1;
}
void turn_down(int &r, int &c)
{
    r += 1;
}
//for checking wheather a cell lies outside the matrix or not
bool is_outside(int row, int col, int r, int c)
{
    if (r >= row || c >= col || r < 0 || c < 0)
        return true;
    return false;
}
//depending on the previous turn we change the direction, for example if previous turn is up we turn into right direction
//as we are rotating in clockwise manner
//here u denotes up and so on
void next_turn(char &previous_direction, int &r, int &c)
{
    if (previous_direction == 'u')
    {
        turn_right(r, c);
        previous_direction = 'r';
    }
    else if (previous_direction == 'r')
    {
        turn_down(r, c);
        previous_direction = 'd';
    }
    else if (previous_direction == 'd')
    {
        turn_left(r, c);
        previous_direction = 'l';
    }
    else if (previous_direction == 'l')
    {
        turn_up(r, c);
        previous_direction = 'u';
    }
}
// below function moves in the same direction as its prev_direction
void move_in_same_direction(char previous_direction, int &r, int &c)
{
    if (previous_direction == 'r')
        c++;
    else if (previous_direction == 'u')
        r--;
    else if (previous_direction == 'd')
        r++;
    else if (previous_direction == 'l')
        c--;
}
vector<vector<int>> spiralMatrixIII(int rows, int cols, int r, int c)
{
    //for storing the co-ordinates
    vector<vector<int>> res;
    char previous_direction = 'r';
    //as in the problem we can see after every 2nd turn the no. of elements in each turn increases by 1
    // so for keeping track of how many steps should we go in the same direction we need turning_elements
    int turning_elements = 2;
    //count is for counting total cells put in the res
    int count = 0;
    //curent_count is for keeping track of how many cells we have traversed in the same direction
    int curent_count = 0;
    //for kepping track of no. of turns we have made
    int turn_count = 0;
    //as we have to traverse all the cells so the limit would be rows*cols
    int limit = rows * cols;
    // while we dont put all the cells's co-ordinates in the res
    while (count < limit)
    {
        //if the curent cell is within the board then only we put the cells in result
        //because cells outside the board is not worth including
        if (!is_outside(rows, cols, r, c))
        {
            res.push_back({r, c});
            count++;
        }
        curent_count++;
        // as after visiting turning elements of cells we change our turn
        if (curent_count == turning_elements)
        {
            //as we are changing our direction we have to increase turn count
            turn_count++;
            //as in every 2nd turn we are increasing the elements the turn visiting so we should increase the turning elements
            if (turn_count == 2)
                turning_elements++;
            // after every 3rd turn we should reset the turn_count to 1
            else if (turn_count == 3)
            {
                turn_count = 1;
            }
            // as we are changing direction to the next direction based on the previous direction
            next_turn(previous_direction, r, c);
            //we should reset the curent_count as well
            curent_count = 1;
        }
        else
            //if we dont need to change our direction we should move in the same direction
            move_in_same_direction(previous_direction, r, c);
    }
    return res;
}
int main()
{
    auto res = spiralMatrixIII(5, 6, 1, 4);
    for (auto it : res)
    {
        cout << it[0] << ',' << it[1];
        cout << "  ";
    }
    return 0;
}