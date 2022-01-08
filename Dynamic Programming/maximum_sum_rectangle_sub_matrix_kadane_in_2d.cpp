#include <bits/stdc++.h>
using namespace std;
// for better under standing about the logic behind this approach watch tushar's video
// below function is used to get the maximum sum of a subarray of a col and its starting and ending index
pair<int, pair<int, int>> kadane(vector<int> &tempCol)
{
    int m = tempCol.size();
    int curentSum = tempCol[0], maxSum = tempCol[0], left = 0, right = 0, r;
    for (int i = 1; i < m; i++)
    {
        if (curentSum + tempCol[i] < tempCol[i])
        {
            curentSum = tempCol[i];
            left = i;
        }
        else
        {
            curentSum += tempCol[i];
            r = i;
        }
        if (maxSum < curentSum)
        {
            right = r;
            maxSum = curentSum;
        }
    }
    return {maxSum, {left, right}};
}
int maxSumSubmatrix(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> tempCol(m);
    int curentSum, maxSum = INT_MIN, maxSumUp, maxSumDown, maxSumLeft, maxSumRight;
    for (int left = 0; left < n; left++)
    {
        for (int i = 0; i < m; i++)
            tempCol[i] = 0;
        for (int right = left; right < n; right++)
        {
            //first of all make sum of previous tempCol with ith col
            for (int i = 0; i < m; i++)
                tempCol[i] += matrix[i][right];
            // now get the get the maxSum, starting index of maxSum and ending index of maxSum
            // by applying Kadane's algorithm in tempCol
            auto maxSumInfo = kadane(tempCol);
            curentSum = maxSumInfo.first;
            if (curentSum > maxSum)
            {
                maxSum = curentSum;
                maxSumUp = maxSumInfo.second.first;
                maxSumDown = maxSumInfo.second.second;
                maxSumLeft = left;
                maxSumRight = right;
            }
        }
    }
    return maxSum;
    // we can also get the location of the of the submatrix by maxSumUp,maxSumDown,maxSumLeft,maxSumRight
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
    cout << maxSumSubmatrix(matrix) << endl;
    // int n;
    // cin >> n;
    // vector<int> arr(n);
    // for (int i = 0; i < n;i++)
    //     cin >> arr[i];
    // auto res = kadane(arr);
    // cout << res.first << ' ' << res.second.first << ' ' << res.second.second << endl;
    return 0;
}