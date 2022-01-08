#include <bits/stdc++.h>
using namespace std;
//on adjacency matrix representation
void floyd_warshall(vector<vector<int>> &dist)
{
    int n = dist.size();
    //distance from start to itself is zero i.e. dist[i][i]=0, base case of dp
    for (int i = 0; i < n; i++)
        dist[i][i] = 0;
    //for every intermediate vertex k we are computing distances between vertex i and j
    //i.e. wheather choosing k as an intermediate vertex leads us to shortest distance or not
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                //avoiding the overflow condition
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}
int main()
{
    return 0;
}