#include <bits/stdc++.h>
using namespace std;
//function for generating all subsets of a given set, i.e. powerset
vector<vector<int>> powerSet(vector<int> &a)
{
    if (a.size() == 0)
        return {{}};
    vector<vector<int>> result;
    vector<int> temp;
    int last = a.back();
    a.pop_back();
    result = powerSet(a);
    int n = result.size();
    for (int i = 0; i < n; i++)
    {
        temp = result[i];
        temp.push_back(last);
        result.push_back(temp);
    }
    return result;
}
void print(vector<int> &v)
{
    for (int i : v)
        cout << i << " ";
    cout << endl;
}
//backtracking way of generating the powerset
void powerSet(vector<int> a, vector<int> sofar)
{
    if (a.empty())
    {
        print(sofar);
        return;
    }
    int last = a.back();
    a.pop_back();
    powerSet(a, sofar);
    sofar.push_back(last);
    powerSet(a, sofar);
}
//backtracking way of printing all k length subsets of a given set
void printAllSubSets(vector<int> nums, vector<int> res, int k)
{
    if (nums.empty())
    {
        if (res.size() == k)
            print(res);
        return;
    }
    else
    {
        int last = nums.back();
        nums.pop_back();
        res.push_back(last);
        printAllSubSets(nums, res, k);
        res.pop_back();
        printAllSubSets(nums, res, k);
    }
}
//backtracking way of printing all the binary number of length n
void printBinary(int n, string result)
{
    if (n == 0)
    {
        cout << result << endl;
        return;
    }
    printBinary(n - 1, result + "0");
    printBinary(n - 1, result + "1");
}
//backtracking way of printing all the decimals of n digit
void printDecimal(int n, vector<int> sofar)
{
    if (n == 0)
    {
        print(sofar);
        return;
    }
    for (int i = 0; i < 10; i++)
    {
        sofar.push_back(i);
        printDecimal(n - 1, sofar);
        sofar.pop_back();
    }
}
//backtracking way of printing the dice-combinations which add to a given sum
void diceSums(int n, int sum, vector<int> sofar)
{
    if (n == 0)
    {
        if (sum == 0)
            print(sofar);
        return;
    }
    for (int i = 1; i < 7; i++)
    {
        sofar.push_back(i);
        diceSums(n - 1, sum - i, sofar);
        sofar.pop_back();
    }
}
//backtracking way of generating all partition of a given integer
void partition(int n, int remain, vector<int> sofar)
{
    if (remain == 0)
    {
        print(sofar);
        return;
    }
    else if (remain < 0)
        return;
    for (int i = 1; i < n; i++)
    {
        sofar.push_back(i);
        partition(n, remain - i, sofar);
        sofar.pop_back();
    }
}
//checking wheather a subset exists with a given sum
bool subsetSum(set<int> s, int target)
{
    if (s.empty())
    {
        return target == 0;
    }
    int last = *(s.begin());
    s.erase(last);
    return subsetSum(s, target - last) || subsetSum(s, target);
    return false;
}
//backtracking way of printing all the subsets with given sum
void subsetSum(vector<int> s, int sum, vector<int> result)
{
    if (s.empty())
    {
        if (sum == 0)
            print(result);
        return;
    }
    int last = s.back();
    s.pop_back();
    result.push_back(last);
    subsetSum(s, sum - last, result);
    result.pop_back();
    subsetSum(s, sum, result);
}
//backtracking way of counting the no. of subsets with given sum
void countSubsetSumWays(vector<int> nums, int sum, int &count)
{
    if (nums.empty())
    {
        if (sum == 0)
            count++;
        return;
    }
    int descision = nums.back();
    nums.pop_back();
    countSubsetSumWays(nums, sum - descision, count);
    countSubsetSumWays(nums, sum, count);
}
//backtracking way of checking wheather a target weight is measureable by the use of the weights or not
bool isMeasureable(vector<int> weights, int target)
{
    if (weights.empty())
    {
        if (target == 0)
            return true;
        return false;
    }
    //decision
    int dec = weights.back();
    weights.pop_back();
    //choices:
    //1.do not use the curent weight
    //2. use the curent weight in the opposite side of the target
    //3. put it in the samse side of the target
    return isMeasureable(weights, target) || isMeasureable(weights, target - dec) || isMeasureable(weights, target + dec);
    return false;
}
//below is the fucntion for printing the two sides of a general weigh machine represented by two vectors<int>
void print2(vector<int> left, vector<int> right)
{
    for (auto it : left)
        cout << it << " ";
    cout << "         ";
    for (auto it : right)
        cout << it << " ";
    cout << endl;
}
//below is the function for printing the both sides of a general weigh machine when the target is measurable
void measureable(vector<int> weights, int target, vector<int> sofarLeft, vector<int> sofarRight)
{
    if (weights.empty())
    {
        if (target == 0)
            print2(sofarLeft, sofarRight);
        return;
    }
    int last = weights.back();
    weights.pop_back();
    measureable(weights, target, sofarLeft, sofarRight);
    sofarLeft.push_back(last);
    measureable(weights, target - last, sofarLeft, sofarRight);
    sofarLeft.pop_back();
    sofarRight.push_back(last);
    measureable(weights, target + last, sofarLeft, sofarRight);
}
//backtracking way of generating all n length alphabet combinations made by a-z letters
void letterPermutation(int n, string sofar)
{
    if (n == 0)
    {
        cout << sofar << endl;
        return;
    }
    for (char c = 'A'; c <= 'Z'; c++)
    {
        sofar += c;
        letterPermutation(n - 1, sofar);
        sofar.pop_back();
    }
}
//function for printing the 2d vector
void print(vector<vector<int>> &ar)
{
    for (int i = 0; i < ar.size(); i++)
    {
        for (int j = 0; j < ar.size(); j++)
            cout << ar[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}
//////////////////////////////////////////////////////////////////////////////////////////////
//below functions are for solving the N-Queens problem using backtracking
//below function is for checking if the queen can be placed in this cell[row][col]
bool isValid(vector<vector<int>> &sol, int row, int col, int N)
{
    //checking row-wise
    for (int i = 0; i < col; i++)
        if (sol[row][i] == 1)
            return false;
    //checking upper diagonal in the left side
    for (int i = row, j = col; j >= 0 && i < N; i++, j--)
        if (sol[i][j] == 1)
            return false;
    //checking lower diagonal in the right side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (sol[i][j] == 1)
            return false;
    return true;
}
void nQueens(vector<vector<int>> &sol, int col, int N)
{
    //if we placed all the N queens print the solution matrix and return
    if (col == N)
    {
        print(sol);
        cout << endl;
        return;
    }
    //decision is the each colum
    //choices for each decision are the rows
    for (int row = 0; row < N; row++)
    {
        //if the curent row is valid then include this cell in solution matrix
        if (isValid(sol, row, col, N))
        {
            sol[row][col] = 1;
            //recursively handle other decision following above choice
            nQueens(sol, col + 1, N);
            //backtracking by unchoosing the choice
            sol[row][col] = 0;
        }
    }
}
//below is the function for checking if the curent row,col postion is safe
bool isSafe(vector<vector<int>> question, int row, int col, int N)
{
    if (row >= 0 && row < N && col >= 0 && col < N && question[row][col] == 1)
        return true;
    return false;
}
void ratInaMaze(vector<vector<int>> question, vector<vector<int>> ans, int row, int col, int N)
{
    //if we've reached the destination
    if (row == N - 1 && col == N - 1)
    {
        //include this cell in ans
        ans[row][col] = 1;
        //print the solution followed by a newline and return
        print(ans);
        cout << endl;
        return;
    }
    //we are solving the curent decision ourselves and pick a choice out of all available choices
    //checking wheather the curent cell is safe then include it in the ans matrix
    if (isSafe(question, row, col, N))
    {
        ans[row][col] = 1;
        //1st choice is going right
        //we made this choice and our remaining decision follow this choice
        ratInaMaze(question, ans, row, col + 1, N);
        //2nd choice is going down
        //we made this choice and our remaining decision follow this choice
        ratInaMaze(question, ans, row + 1, col, N);
        //backtracking
        ans[row][col] = 0;
    }
}
//////////////////////////////////////////////////////////////////////////////////
bool valid(vector<vector<int>> &ans, int val, int row, int col)
{
    //checking row-wise
    for (int i = 0; i < 9; i++)
        if (ans[i][col] == val)
            return false;
    //checking column-wise
    for (int i = 0; i < 9; i++)
        if (ans[row][i] == val)
            return false;
    //checking the cell's 3*3 box
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (ans[i + startRow][j + startCol] == val)
                return false;
    return true;
}
void solveSudoku(vector<vector<int>> board, int row, int col)
{
    //checking if the row is not out of board but the col is, then we increament the row, reset the col to 0
    //bcause we are traversing the matrix in level wise
    if (row < 9 && col == 9)
    {
        row++;
        col = 0;
    }
    //if the row is out of the board that means we got a solution so we print it and return
    if (row == 9)
    {
        print(board);
        return;
    }
    //checking if the curent cell is empty or not
    if (board[row][col] == 0)
    {
        //we have choices to fill the cell
        for (int i = 1; i <= 9; i++)
        {
            //if the picked choice is valid in the board, include it in the solution
            if (valid(board, i, row, col))
            {
                //including this choice(number) in solution
                board[row][col] = i;
                //recursively remaining decision followed this choice
                solveSudoku(board, row, col + 1);
                //if this choice does'nt lead to the solution remove this solution from the board
                board[row][col] = 0;
            }
        }
    }
    //if the curent cell has a number already then we recursively solve for other cells
    else
        solveSudoku(board, row, col + 1);
}
int main()
{
    //below is the board which is to be solved
    vector<vector<int>> question(9, vector<int>(9, 0));
    question = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                {5, 2, 0, 0, 0, 0, 0, 0, 0},
                {0, 8, 7, 0, 0, 0, 0, 3, 1},
                {0, 0, 3, 0, 1, 0, 0, 8, 0},
                {9, 0, 0, 8, 6, 3, 0, 0, 5},
                {0, 5, 0, 0, 9, 0, 6, 0, 0},
                {1, 3, 0, 0, 0, 0, 2, 5, 0},
                {0, 0, 0, 0, 0, 0, 0, 7, 4},
                {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    solveSudoku(question, 0, 0);
    return 0;
}