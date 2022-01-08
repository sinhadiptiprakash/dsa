#include <bits/stdc++.h>
using namespace std;
//using tarzan's algo for finding the bridges/articulation points in a graph
class Solution
{
public:
    void dfs(vector<vector<int>> &graph, int u, vector<bool> &visited, vector<int> &parent, vector<int> &low, vector<int> &disc, vector<vector<int>> &bridges)
    {
        static int time = 0;
        low[u] = disc[u] = time++;
        visited[u] = true;
        for (auto v : graph[u])
        {
            if (!visited[v])
            {
                parent[v] = u;
                dfs(graph, v, visited, parent, low, disc, bridges);
                low[u] = min(low[u], low[v]);
                if (low[v] > disc[u])
                {
                    bridges.push_back({u, v});
                }
            }
            else if (parent[u] != v)
            {
                low[u] = min(low[u], disc[v]);
            }
        }
    }
    vector<vector<int>> buildGraph(int n, vector<vector<int>> &connections)
    {
        vector<vector<int>> graph(n);
        for (auto vec : connections)
        {
            int u = vec[0], v = vec[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        return graph;
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<vector<int>> graph = buildGraph(n, connections);
        vector<vector<int>> bridges;
        vector<int> parent(n, -1);
        vector<int> low(n), disc(n);
        vector<bool> visited(n, false);
        dfs(graph, 0, visited, parent, low, disc, bridges);
        return bridges;
    }
};
int main()
{
    return 0;
}