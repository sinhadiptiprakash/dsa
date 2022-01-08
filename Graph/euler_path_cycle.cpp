#include <bits/stdc++.h>
using namespace std;
//euler tour is the traversal without lifting the pencil
//below is the euler path and euler cycle algorithm using backtracking

// Eulerian Path is a path in graph that visits every edge exactly once.
// Eulerian Circuit is an Eulerian Path which starts and ends on the same vertex.
// An Eulerian Graph is graph having an eulerian cricuit/cycle
// a semi-eulerian graph is graph having eulerian path but not having eulerian cycle

// Conditions:
// Eulerian Cycle
// An undirected graph has Eulerian cycle if following two conditions are true.
// ….a) All vertices with non-zero degree are connected. We don’t care about vertices with zero degree because they don’t belong to Eulerian Cycle or Path (we only consider all edges).
// ….b) All vertices have even degree.

// Eulerian Path
// An undirected graph has Eulerian Path if following two conditions are true.
// ….a) Same as condition (a) for Eulerian Cycle
// ….b) If zero or two vertices have odd degree and all other vertices have even degree.
// Note that only one vertex with odd degree is not possible in an undirected graph (sum of all degrees is always even in an undirected graph)

#define V 5

using namespace std;

void removeEdge(vector<int> graph[], int u, int v)
{
    vector<int>::iterator it;
    it = find(graph[v].begin(), graph[v].end(), u);
    *it = -1;
    it = find(graph[u].begin(), graph[u].end(), v);
    *it = -1;
}

void addEdge(vector<int> graph[], int u, int v)
{
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
}

int dfsCount(vector<int> graph[], int u, vector<bool> &visited)
{
    visited[u] = true;
    int count = 1;

    // Recur for all vertices adjacent to this vertex
    for (auto av : graph[u])
    {
        if (av != -1 && !visited[av])
            count += dfsCount(graph, av, visited);
    }
    return count;
}

// The edge u-v is valid in one of the following two cases:
// 1) If v is the only adjacent vertex of u
// 2) If there are multiple adjacents and edge u-v is not a bridge
// To check if u-v is a bridge
// 2.a) count of vertices reachable from u by dfsCount
// 2.b) Remove edge (u, v) and after removing the edge, count vertices reachable from u again with dfsCount
// 2.c) Add the edge back to the graph
// 2.d) If count1 is greater, then edge (u, v) is a bridge
bool isValidNextEdge(vector<int> graph[], int u, int v)
{
    int count = 0;
    for (auto av : graph[u])
    {
        if (av != -1)
            count++;
    }
    if (count == 0)
        return false;
    if (count == 1)
        return true;

    vector<bool> visited(V, false);
    int count1 = dfsCount(graph, u, visited);

    removeEdge(graph, u, v);
    fill(visited.begin(), visited.end(), false);

    int count2 = dfsCount(graph, u, visited);
    addEdge(graph, u, v);

    return (count1 > count2) ? false : true;
}

void eulerCycle(vector<int> graph[], int u)
{
    vector<int>::iterator it;
    for (auto av : graph[u])
    {
        if (av != -1 && isValidNextEdge(graph, u, av))
        {
            cout << u << "-" << av << "  ";
            removeEdge(graph, u, av);
            eulerCycle(graph, av);
        }
    }
}

void dfs(vector<int> graph[], int v, vector<bool> &visited)
{
    visited[v] = true;
    for (auto av : graph[v])
        if (!visited[av])
            dfs(graph, av, visited);
}

bool isConnected(vector<int> graph[])
{
    vector<bool> visited(V, false);

    // Find a vertex with non-zero degree
    int i = 0;
    for (i = 0; i < V; i++)
        if (graph[i].size() != 0)
            break;

    // If there are no edges in the graph, return true
    if (i == V)
        return true;

    // Start DFS traversal from a vertex with non-zero degree
    dfs(graph, i, visited);

    // Check if all non-zero degree vertices are visited
    for (i = 0; i < V; i++)
        if (visited[i] == false && graph[i].size() > 0)
            return false;

    return true;
}

/* The function returns one of the following values
   0 --> If graph is not Eulerian
   1 --> If graph has an Euler path (Semi-Eulerian)
   2 --> If graph has an Euler Circuit (Eulerian)  */
int isEulerian(vector<int> graph[])
{
    // Check if all non-zero degree vertices are connected
    if (isConnected(graph) == false)
        return 0;

    // Count vertices with odd degree
    int odd = 0;
    for (int i = 0; i < V; i++)
        if (graph[i].size() & 1)
            odd++;

    if (odd > 2)
        return 0;

    return (odd == 0) ? 2 : 1;
}

int main()
{
    vector<int> graph[V];

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 3, 4);

    int ret = isEulerian(graph);
    if (ret == 0)
    {
        cout << "Graph is not Euerlian" << endl;
        return 0;
    }
    else if (ret == 1)
        cout << "Graph is Semi-Euerlian i.e has an Euler path" << endl;
    else
        cout << "Graph is Euerlian i.e has a Euler circuit" << endl;

    // Find a vertex with odd degree
    int oddDegreeVertex = 0;
    for (int i = 0; i < V; ++i)
    {
        if (graph[i].size() % 2 != 0)
        {
            oddDegreeVertex = i;
            break;
        }
    }

    cout << "Euler Cycle: ";
    eulerCycle(graph, oddDegreeVertex);
    return 0;
}
