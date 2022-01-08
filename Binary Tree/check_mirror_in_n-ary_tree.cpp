#include <bits/stdc++.h>
using namespace std;
int checkMirrorTree(int n, int e, int A[], int B[])
{
    // code here
    vector<int> v1[n + 1];
    vector<int> v2[n + 1];
    for (int i = 0; i < 2 * e; i += 2)
    {
        v1[A[i]].push_back(A[i + 1]);
        v2[B[i]].push_back(B[i + 1]);
    }
    for (int i = 1; i <= n; i++)
    {
        reverse(v2[i].begin(), v2[i].end());
    }
    for (int i = 1; i <= n; i++)
    {
        if (v1[i] != v2[i])
            return 0;
    }
    return 1;
}
int main()
{
    return 0;
}