#include <bits/stdc++.h>
using namespace std;
void make_set(vector<int> &parent)
{
    for (int i = 0; i < parent.size(); i++)
        parent[i] = i;
}
int find_set(vector<int> &parent, int x)
{
    //below process optimize the time beccause it is finding the set also assigning childs to their correct parent
    if (x != parent[x])
        parent[x] = find_set(parent, parent[x]);
    return parent[x];
}
//union by rank
void union_set(vector<int> &parent, vector<int> &rank, int x, int y)
{
    int rootX = find_set(parent, x);
    int rootY = find_set(parent, y);
    if (rootX == rootY)
        return;
    if (rank[rootX] > rank[rootY])
        parent[rootY] = rootX;
    else
    {
        parent[rootX] = rootY;
        if (rank[rootX] == rank[rootY])
            rank[rootY]++;
    }
}
//edges are in the form of a vector of which 0th element represents weight
vector<vector<int>> krushkalMST(vector<vector<int>> &edges, int V)
{
    vector<vector<int>> mst;
    vector<int> parent(V);
    vector<int> rank(V, 0);
    make_set(parent);
    sort(edges.begin(), edges.end());
    for (int i = 0; i < edges.size(); i++)
    {
        int rootU = find_set(parent, edges[i][1]), rootV = find_set(parent, edges[i][2]);
        if (rootU != rootV)
        {
            mst.push_back(edges[i]);
            union_set(parent, rank, rootU, rootV);
        }
    }
    return mst;
}
int main()
{
    int n, u, v, w, V;
    cin >> V >> n;
    vector<vector<int>> edges;
    for (int i = 0; i < n; i++)
    {
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }
    cout << "Krushkal's MST is:" << endl;
    auto mst = krushkalMST(edges, V);
    for (auto v : mst)
        // source destination weight
        cout << v[1] << ' ' << v[2] << ' ' << v[0] << endl;
    return 0;
}