#include <bits/stdc++.h>
using namespace std;
// similar to finding largest submatrix with 0 sum

// below is the function which returns the maximum subarrya having equal no. of 0s and 1s
// get the maximum subarray with equal no. of 0s and 1s we will use the technique
// of getting the largest subarray with 0 sum by taking -1 as 0 and 1 as 1
pair<int, int> largestEqualZeroOne(int tempCol[], int m)
{
    int sum = 0, maxLen = 0, end;
    unordered_map<int, int> map;
    for (int i = 0; i < m; i++)
    {
        sum += tempCol[i];
        if (sum == 0)
        {
            maxLen = i + 1;
            end = i;
        }
        else if (map.find(sum) != map.end())
        {
            if (maxLen < i - map[sum])
            {
                maxLen = i - map[sum];
                end = i;
            }
        }
        else
            map[sum] = i;
    }
    // returns the maxLen and its ending index of the subarray
    return {maxLen, end};
}
void largestSubmatrixWithEqualZeroOne(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int maxArea = 0, maxUp, maxDown, maxLeft, maxRight;
    int tempCol[m];
    for (int left = 0; left < n; left++)
    {
        memset(tempCol, 0, sizeof(tempCol));
        for (int right = left; right < n; right++)
        {
            for (int i = 0; i < m; i++)
                tempCol[i] += (matrix[i][right] == 0 ? -1 : matrix[i][right]);
            auto maxSubarrayInfo = largestEqualZeroOne(tempCol, m);
            if (maxSubarrayInfo.first * (right - left + 1) > maxArea)
            {
                maxArea = maxSubarrayInfo.first * (right - left + 1);
                maxLeft = left;
                maxRight = right;
                maxUp = maxSubarrayInfo.second - maxSubarrayInfo.first + 1;
                maxDown = maxSubarrayInfo.second;
            }
        }
    }
    // printing that submatrix
    cout << maxArea << endl;
    for (int i = maxUp; i <= maxDown; i++)
    {
        for (int j = maxLeft; j <= maxRight; j++)
            cout << matrix[i][j] << ' ';
        cout << endl;
    }
}
int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    largestSubmatrixWithEqualZeroOne(matrix);
    return 0;
}