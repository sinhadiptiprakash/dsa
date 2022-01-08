#include <bits/stdc++.h>
using namespace std;

int maximumPath(int n, vector<vector<int>> &matrix)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != 0)
            {
                if (j == 0)
                    matrix[i][j] += max(matrix[i - 1][j], matrix[i - 1][j + 1]);
                else if (j == n - 1)
                    matrix[i][j] += max(matrix[i - 1][j], matrix[i - 1][j - 1]);
                else
                    matrix[i][j] += max(matrix[i - 1][j], max(matrix[i - 1][j - 1], matrix[i - 1][j + 1]));
            }
        }
    }
    int maxVal = 0;
    for (int i = 0; i < n; i++)
    {
        maxVal = max(matrix[n - 1][i], maxVal);
    }
    return maxVal;
} //time complexity O(N^2) space O(1)
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout << maximumPath(n, matrix) << endl;
    return 0;
}