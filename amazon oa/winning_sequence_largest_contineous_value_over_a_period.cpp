#include <bits/stdc++.h>
using namespace std;
int maxValueOverAPeriod(vector<int> &ratings)
{
    int n = ratings.size();
    vector<int> prefixSum(n);
    prefixSum[0] = ratings[0];
    for (int i = 1; i < n; i++)
        prefixSum[i] = prefixSum[i - 1] + ratings[i];
    stack<int> stack;
    stack.push(-1);
    int minRating, maxArea = 0, area = 0, start;
    for (int i = 0; i < n; i++)
    {
        while (stack.top() != -1 && ratings[i] < ratings[stack.top()])
        {
            int rating = ratings[stack.top()];
            stack.pop();
            area = rating * (i - stack.top() - 1);
            if (area >= maxArea)
            {
                maxArea = area;
                minRating = rating;
                start = stack.top() + 1;
            }
        }
        stack.push(i);
    }
    while (stack.top() != -1)
    {
        int rating = ratings[stack.top()];
        stack.pop();
        area = rating * (n - stack.top() - 1);
        if (area >= maxArea)
        {
            maxArea = area;
            minRating = rating;
            start = stack.top() + 1;
        }
    }
    //now the start of the maximum contineous area is start
    // height of the maximum contineous area is minRating
    // width of the maximum contigeous area is area/minRating
    int width = maxArea / minRating;
    // so the maxArea ends at start+width-1 th index
    int contSum = prefixSum[start + width - 1] - prefixSum[start - 1];
    return contSum * minRating;
}
// time complexity O(N) space complexity O(N)
int main()
{
    int n;
    cin >> n;
    vector<int> ratings(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ratings[i];
    }
    cout << maxValueOverAPeriod(ratings) << endl;
    return 0;
}