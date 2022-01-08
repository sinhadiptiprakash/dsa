#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int>> &graph, int u, int v)
{
    // as its a directed acyclic graph(DAG) so we add edge in one direction only
    graph[u].push_back(v);
}
vector<int> getIndegree(const vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto it : graph[i])
        {
            indegree[it]++;
        }
    }
    return indegree;
}
vector<int> topologicalSort(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> time(n, 0);
    vector<int> indegree = getIndegree(graph);
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (!indegree[i])
        {
            q.push(i);
            time[i] = 1;
        }
    }
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for (int it : graph[temp])
        {
            if (--indegree[it] == 0)
            {
                time[it] = time[temp] + 1;
                q.push(it);
            }
        }
    }
    return time;
}
int main()
{
    int n, e, u, v;
    cin >> n >> e;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v;
        addEdge(graph, u, v);
    }
    auto time = topologicalSort(graph);
    for (int i : time)
        cout << i << ' ';
    cout << endl;
    return 0;
}