#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int>> &graph, int src, int des)
{
    graph[src].push_back(des);
    graph[des].push_back(src);
}
bool noCycle(int start, const vector<vector<int>> &graph, vector<bool> &visited, int parent)
{
    visited[start] = true;
    for (auto it : graph[start])
    {
        if (!visited[it])
            noCycle(it, graph, visited, start);
        else if (it != parent)
            return false;
    }
    return true;
}
bool isTree(const vector<vector<int>> &graph)
{
    vector<bool> visited(graph.size(), false);
    bool cycle = noCycle(0, graph, visited, -1);
    // cout << endl;
    for (int i : visited)
        cycle &= i;
    return cycle;
}
int main()
{
    vector<vector<int>> graph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 3, 4);
    cout << isTree(graph) << endl;
    return 0;
}