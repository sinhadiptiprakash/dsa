#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maximumPath(int n, vector<vector<int>> matrix)
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
    }
};
int main()
{
    return 0;
}