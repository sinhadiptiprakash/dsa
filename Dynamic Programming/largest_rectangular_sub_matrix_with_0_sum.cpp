#include <bits/stdc++.h>
using namespace std;
// same as maximum sum submatrix
pair<int, pair<int, int>> largesSubarrayZeroSum(int tempCol[], int m)
{
    unordered_map<int, int> map;
    int curentSum = 0, maxLen = 0, end;
    for (int i = 0; i < m; i++)
    {
        curentSum += tempCol[i];
        if (curentSum == 0)
        {
            maxLen = i + 1;
            end = i;
        }
        else if (map.find(curentSum) != map.end())
        {
            if (maxLen < i - map[curentSum])
            {
                maxLen = i - map[curentSum];
                end = i;
            }
        }
        else
            map[curentSum] = i;
    }
    return {maxLen, {end - maxLen + 1, end}};
}
void largestSubmatrixZerosum(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int tempCol[m];
    int maxArea = 0, up, down, maxUp, maxDown, maxLeft, maxRight;
    for (int left = 0; left < n; left++)
    {
        memset(tempCol, 0, sizeof(tempCol));
        for (int right = left; right < n; right++)
        {
            for (int i = 0; i < m; i++)
                tempCol[i] += matrix[i][right];
            //now get the maxLen of the largest subarray in tempCol and its starting and ending index
            auto zeroSubarrayInfo = largesSubarrayZeroSum(tempCol, m);
            if (zeroSubarrayInfo.first * (right - left + 1) > maxArea)
            {
                maxArea = zeroSubarrayInfo.first * (right - left + 1);
                maxUp = zeroSubarrayInfo.second.first;
                maxDown = zeroSubarrayInfo.second.second;
                maxLeft = left;
                maxRight = right;
            }
        }
    }
    //printing the the larges submatrix
    for (int i = maxUp; i <= maxDown; i++)
    {
        for (int j = maxLeft; j <= maxRight; j++)
            cout << matrix[i][j] << ' ';
        cout << endl;
    }
} //time complexity O(n*n*m) space complexity O(m)
int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    cout << '\n';
    largestSubmatrixZerosum(matrix);
    return 0;
}