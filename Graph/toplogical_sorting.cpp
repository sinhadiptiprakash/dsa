#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int>> &graph, int u, int v)
{
    // as its a directed acyclic graph(DAG) so we add edge in one direction only
    graph[u].push_back(v);
}
vector<int> getIndegree(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto it : graph[i])
            indegree[it]++;
    }
    return indegree;
}
//kahn's algorithm
vector<int> topologicalSort(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> res;
    vector<int> indegree = getIndegree(graph);
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (!indegree[i])
            q.push(i);
    }
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        res.push_back(temp);
        for (int it : graph[temp])
        {
            if (--indegree[it] == 0)
                q.push(it);
        }
    }
    return res;
}
//using dfs
//In topological sorting, we use a temporary stack. We don’t print the vertex immediately,
//we first recursively call topological sorting for all its adjacent vertices, then push it to a stack.
//Finally, print contents of the stack.
//Note that a vertex is pushed to stack only when all of its adjacent vertices (and their adjacent vertices
//and so on) are already in the stack.
void dfs(int source, vector<vector<int>> &graph, vector<int> &visited, stack<int> &order)
{
    visited[source] = true;
    // first of all visits all the adjacent of the source using dfs
    // and after returning from all push source to the stack
    for (auto it : graph[source])
    {
        if (!visited[it])
            dfs(it, graph, visited, order);
    }
    // after returning from all the dfs calls we push the source to the stack
    // so when we will print the contents of the stack we get the source first then adjacents
    order.push(source);
}
void topologicalSortUsingDFS(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> visited(n, 0);
    stack<int> order;
    // for all unvisited vertices in the graph apply dfs
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            dfs(i, graph, visited, order);
    }
    // printing the order
    while (!order.empty())
    {
        cout << order.top() << ' ';
        order.pop();
    }
    cout << endl;
}
int main()
{
    vector<vector<int>> graph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 3, 2);
    addEdge(graph, 4, 2);
    addEdge(graph, 2, 5);
    addEdge(graph, 3, 5);
    auto order = topologicalSort(graph);
    for (int i : order)
        cout << i << ' ';
    cout << endl;
    topologicalSortUsingDFS(graph);
    return 0;
}