#include <bits/stdc++.h>
using namespace std;
int dp[1000][1000];
//recursive approach
// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n
int mcm(int i, int j, int p[])
{
    if (i >= j)
        return 0;
    int minCost = INT_MAX, cost;

    for (int k = i; k < j; k++)
    {
        cost = mcm(i, k, p) + mcm(k + 1, j, p) + (p[i - 1] * p[k] * p[j]);
        minCost = min(minCost, cost);
    }
    return minCost;
}
// memoization
int mcmMemo(int i, int j, int p[])
{
    if (i >= j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int minCost = INT_MAX, cost;

    for (int k = i; k < j; k++)
    {
        cost = mcmMemo(i, k, p) + mcmMemo(k + 1, j, p) + (p[i - 1] * p[k] * p[j]);
        minCost = min(minCost, cost);
    }
    return dp[i][j] = minCost;
}
//below is the code of BOTTOM-UP DP 0F MCM
int mcmBU(int p[], int n)
{
    /* For simplicity of the program, one extra row and one extra column are allocated in m[][]. 
    0th row and 0th column of m[][] are not used */
    int m[n][n];
    int i, j, k, len, cost;
    /* m[i, j] = Minimum number of scalar multiplications needed to compute the
    matrix A[i]A[i+1]...A[j] = A[i..j] where dimension of A[i] is p[i-1] x p[i] */

    // cost is zero when multiplying
    // one matrix.
    for (i = 1; i < n; i++)
        m[i][i] = 0;

    // len is chain length.
    for (len = 2; len < n; len++)
    {
        for (i = 1; i < n - len + 1; i++)
        {
            j = i + len - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++)
            {
                // cost = cost/scalar multiplications
                cost = m[i][k] + m[k + 1][j] + (p[i - 1] * p[k] * p[j]);
                if (cost < m[i][j])
                    m[i][j] = cost;
            }
        }
    }

    return m[1][n - 1];
}
int main()
{
    int n;
    cin >> n;
    int p[n];
    for (int i = 0; i < n; i++)
        cin >> p[i];
    memset(dp, -1, sizeof(dp));
    cout << mcmBU(p, n) << endl;
    return 0;
}