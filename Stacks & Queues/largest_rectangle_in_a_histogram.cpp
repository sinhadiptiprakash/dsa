#include <bits/stdc++.h>
using namespace std;
// using stack
int largestRectangleArea(vector<int> &heights)
{
    int maxArea = 0;
    int height = 0;
    int area = 0;
    stack<int> st;
    st.push(-1); // to align with width calculation
    for (int i = 0; i < heights.size(); ++i)
    {
        while (st.top() != -1 && (heights[i] < heights[st.top()]))
        {
            height = heights[st.top()];
            st.pop();
            // as we are pushing when the curent height is greater than or equal to stack top
            // so if we get height at i is less than the top of the stack, we can say that from index stack.top
            // to i the bars have at least the height of heights[stack.top] as we are pushing heights>= stack.top
            // so the width is i-stack.top-1 and height of this sub rectangle is at least heights[st.top]
            area = height * (i - st.top() - 1);
            maxArea = (maxArea > area) ? maxArea : area;
        }
        st.push(i);
    }
    while (st.top() != -1)
    {
        height = heights[st.top()];
        st.pop();
        area = height * (heights.size() - st.top() - 1);
        maxArea = maxArea > area ? maxArea : area;
    }
    return maxArea;
}
// we can get rid of the last while loop outside the for loop by just appending a 0 in the heights vector
// so at last when we hit a zero in the heights we will run the same while loop in the for loop and make the stack empty
// as we don't have contents in the stack we don't need the while loop outside the for loop
int main()
{
    vector<int> heights = {3, 2};
    cout << largestRectangleArea(heights) << endl;
    return 0;
}