#include <bits/stdc++.h>
using namespace std;
int n, e, x, y;
void makeSet(vector<int> &parent)
{
    int n = parent.size();
    for (int i = 0; i < n; i++)
        parent[i] = i;
}
int findSet(vector<int> &parent, int u)
{
    if (parent[u] != u)
        parent[u] = findSet(parent, parent[u]);
    return parent[u];
}
//unionSet with an extra count array
void unionSet(vector<int> &parent, vector<int> &rank, vector<int> &counts, int x, int y)
{
    int rootX = findSet(parent, x);
    int rootY = findSet(parent, y);
    if (rootX == rootY)
        return;
    if (rank[rootX] > rank[rootY])
    {
        counts[parent[rootX]] = counts[parent[rootX]] + counts[parent[rootY]];
        parent[rootY] = parent[rootX];
    }
    else
    {
        counts[parent[rootY]] = counts[parent[rootX]] + counts[parent[rootY]];
        parent[rootX] = parent[rootY];
        if (rank[rootX] == rank[rootY])
            rank[rootY]++;
    }
}
//using DSU
long long solve()
{
    vector<int> parent(n), rank(n, 0), counts(n, 1);
    makeSet(parent);
    vector<pair<int, int>> edges;
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y;
        unionSet(parent, rank, counts, x, y);
    }
    // with n counts we can have total n*(n-1)/2 no. pairs
    // out of which we have to eliminate the pairs from the same sets
    long long res = 0, sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (parent[i] == i)
        {
            res += sum * counts[i];
            sum += counts[i];
        }
    }
    return res;
}
// we can also do this by using dfs for getting no. of nodes in each connected componets and use the same concept
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> e;
    long long cnt = solve();
    cout << cnt << endl;
    return 0;
}