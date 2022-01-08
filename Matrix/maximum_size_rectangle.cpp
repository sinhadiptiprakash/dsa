#include <bits/stdc++.h>
using namespace std;
// this problem is the extension of the maximum_size_square_sub_matrix with all ones
// Approach:
// In this post an interesting method is discussed that uses largest rectangle under histogram as a subroutine.
// If the height of bars of the histogram is given then the largest area of the histogram can be found.
// This way in each row, the largest area of bars of the histogram can be found.
// To get the largest rectangle full of 1’s, update the next row with the previous row
// and find the largest area under the histogram, i.e. consider each 1’s as filled squares
// and 0’s with an empty square and consider each row as the base.
//below is the implementaion of the largest rectangle in a histogram
int largest_rectangle_in_histogram(vector<int> &heights)
{
    int n = heights.size();
    int maxArea = 0, curArea, i = 0, tp, width;
    //in the stack we just store the indices of the heights not the heights
    stack<int> st;
    while (i < n)
    {
        //if the stack is empty or the heights at curent index is greater than the heights at stack's top index
        // we push the curent index and increament i
        if (st.empty() || heights[st.top()] <= heights[i])
            st.push(i++);
        //if the height at curent index is less than the height at stack's top index we do the following
        //1.fist store the top index in tp variable
        //and pop the stack to have the index before the tp index at the top of the stack
        //2. we calculate the width of the rectangle with the heights[tp]
        //if the stack is empty then the width will be simply i itself
        //otherwise as we have the index before the tp index in the top of the stack
        //the width would be curnt index-index stored at top of stack-1
        //then we calculate the curArea with this width and height
        else
        {
            tp = st.top();
            st.pop();
            width = (st.empty() ? i : i - st.top() - 1);
            curArea = width * heights[tp];
            maxArea = max(curArea, maxArea);
        }
    }
    //after doing all the operation above if the stack is not empty yet
    //while the stack is not empty we do the following
    //1. store the index stored at the top of the stack and pop the stack
    //calculate the width in the same way as discussed above
    //and calculate and compre the curent and max areas
    while (!st.empty())
    {
        tp = st.top();
        st.pop();
        width = (st.empty() ? i : i - st.top() - 1);
        curArea = width * heights[tp];
        maxArea = max(curArea, maxArea);
    }
    return maxArea;
}
// Returns area of the largest rectangle with all 1s in
// A[][]
int max_rectangle(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    // Calculate area for first row and initialize it as
    // result
    int result = largest_rectangle_in_histogram(matrix[0]);

    // iterate over row to find maximum rectangular area
    // considering each row as histogram
    for (int i = 1; i < row; i++)
    {

        for (int j = 0; j < col; j++)
            // if A[i][j] is 1 then add A[i -1][j]
            if (matrix[i][j])
                matrix[i][j] += matrix[i - 1][j];

        // Update result if area with current row (as last
        // row) of rectangle) is more
        result = max(result, largest_rectangle_in_histogram(matrix[i]));
    }
    return result;
} //Time Complexity: O(R x C). and Space Complexity: O(C).
int main()
{
    int row, col;
    cin >> row >> col;
    vector<vector<int>> matrix(row, vector<int>(col));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout << max_rectangle(matrix) << endl;
    return 0;
}