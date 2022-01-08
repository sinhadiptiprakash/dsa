#include <bits/stdc++.h>
using namespace std;
void dfs(int source, const vector<vector<int>> &graph, vector<bool> &visited)
{
    visited[source] = true;
    for (auto it : graph[source])
    {
        if (!visited[it])
            dfs(it, graph, visited);
    }
}
int makeConnected(int n, vector<vector<int>> &connections)
{
    if (connections.size() < n - 1)
        return -1;
    vector<vector<int>> graph(n);
    for (auto &i : connections)
    {
        graph[i[0]].push_back(i[1]);
        graph[i[1]].push_back(i[0]);
    }
    vector<bool> visited(n);
    int components = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, graph, visited);
            components++;
        }
    }
    return components-1;
}
int main()
{
    int n, u, v;
    cin >> n;
    int edges;
    cin >> edges;
    vector<vector<int>> connections(edges);
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        connections[i]={u, v};
    }
    cout << makeConnected(n, connections) << endl;
    return 0;
}