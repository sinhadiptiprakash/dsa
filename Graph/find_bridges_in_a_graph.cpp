#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int>> &graph, int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}
// same as finding articulation points except here condition 1. in articulation point
// i.e node with more than one child is an articulation point is not needed here because we are dealing with edges
void bridgesInGraph(vector<vector<int>> &graph, int u, vector<bool> &visited, vector<int> &parent, vector<int> &lowestTime, vector<int> &discoveryTime, set<pair<int, int>> &bridges)
{
    static int time = 0;
    visited[u] = true;
    lowestTime[u] = discoveryTime[u] = ++time;
    for (auto v : graph[u])
    {
        if (!visited[v])
        {
            parent[v] = u;
            bridgesInGraph(graph, v, visited, parent, lowestTime, discoveryTime, bridges);
            lowestTime[u] = min(lowestTime[u], lowestTime[v]);
            if (lowestTime[v] > discoveryTime[u])
                bridges.insert({u, v});
        }
        else if (v != parent[u])
        {
            lowestTime[u] = min(lowestTime[u], discoveryTime[v]);
        }
    }
}
set<pair<int, int>> findBridgesInGraph(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> parent(n, -1), lowestTime(n), discoveryTime(n);
    vector<bool> visited(n, 0);
    set<pair<int, int>> bridges;
    bridgesInGraph(graph, 0, visited, parent, lowestTime, discoveryTime, bridges);
    return bridges;
}
int main()
{
    vector<vector<int>> g1(5);
    addEdge(g1, 1, 0);
    addEdge(g1, 0, 2);
    addEdge(g1, 2, 1);
    addEdge(g1, 0, 3);
    addEdge(g1, 3, 4);
    auto bridges1 = findBridgesInGraph(g1);
    for (auto it : bridges1)
        cout << it.first << ' ' << it.second << endl;

    cout << "\nBridges in second graph \n";
    vector<vector<int>> g2(4);
    addEdge(g2, 0, 1);
    addEdge(g2, 1, 2);
    addEdge(g2, 2, 3);
    auto bridges2 = findBridgesInGraph(g2);
    for (auto it : bridges2)
        cout << it.first << ' ' << it.second << endl;

    cout << "\nBridges in third graph \n";
    vector<vector<int>> g3(7);
    addEdge(g3, 0, 1);
    addEdge(g3, 1, 2);
    addEdge(g3, 2, 0);
    addEdge(g3, 1, 3);
    addEdge(g3, 1, 4);
    addEdge(g3, 1, 6);
    addEdge(g3, 3, 5);
    addEdge(g3, 4, 5);
    auto bridges3 = findBridgesInGraph(g3);
    for (auto it : bridges3)
        cout << it.first << ' ' << it.second << endl;

    return 0;
}