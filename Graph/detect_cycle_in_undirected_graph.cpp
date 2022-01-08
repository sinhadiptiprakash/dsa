#include <bits/stdc++.h>
using namespace std;
//using DFS
bool isCycle(int source, int parent, vector<int> adj[], vector<bool> &visited)
{
    visited[source] = true;
    for (int it : adj[source])
    {
        if (!visited[it])
        {
            if (isCycle(it, source, adj, visited))
                return true;
        }
        else if (visited[it] && parent != it)
            return true;
    }
    return false;
}
//using BFS
bool isCyclic(int source, vector<bool> &visited, int V, vector<int> adj[])
{
    // Set parent vertex for every vertex as -1.
    vector<int> parent(V, -1);
    // Create a queue for BFS
    queue<int> q;
    // Mark the current node as visited and enqueue it
    visited[source] = true;
    q.push(source);

    while (!q.empty())
    {
        // Dequeue a vertex from queue and print it
        int u = q.front();
        q.pop();

        // Get all adjacent vertices of the dequeued vertex u. If a adjacent has not been visited,
        // then mark it visited and enqueue it. We also mark parent so that parent is not considered
        // for cycle.
        for (auto v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
                parent[v] = u;
            }
            else if (parent[u] != v)
                return true;
        }
    }
    return false;
}
bool isCycle(int V, vector<int> adj[])
{
    vector<bool> visited(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            if (isCycle(i, -1, adj, visited))
                return true;
    }
    return false;
}
int main()
{
    return 0;
}