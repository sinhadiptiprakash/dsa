#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int>> &graph, int u, int v)
{
    // as its a directed acyclic graph(DAG) so we add edge in one direction only
    graph[u].push_back(v);
}
//topological sorting using dfs
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
//below function is for getting the maximum length path from source
int longestPatInDAG(int source, vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> visited(n, 0);
    stack<int> order;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            dfs(i, graph, visited, order);
    }
    vector<int> distance(n, INT_MIN);
    distance[source] = 0;
    // now in topological order process each and every vertex and its adjacent to fix the longest distances
    int max_length = 0;
    while (!order.empty())
    {
        int u = order.top();
        order.pop();
        if (distance[u] != INT_MIN)
        {
            for (auto v : graph[u])
            {
                // assuming the weight of each edge is 1 if the weights are different for each node
                // then change 1 to weight of edge u-v
                if (distance[v] < distance[u] + 1)
                    distance[v] = distance[u] + 1;
                //update max_length so far on the go
                max_length = max(max_length, distance[v]);
            }
        }
    }
    return max_length;
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
    cout << longestPatInDAG(0, graph) << endl;
    return 0;
}