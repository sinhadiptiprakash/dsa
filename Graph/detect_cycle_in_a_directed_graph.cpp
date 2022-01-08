#include <bits/stdc++.h>
using namespace std;
//using DFS
bool DFS(vector<int> graph[], int source, bool visited[], bool recursionStack[])
{
    visited[source] = true;
    recursionStack[source] = true;
    for (int adjacent : graph[source])
    {
        if (!visited[adjacent])
        {
            if (DFS(graph, adjacent, visited, recursionStack))
                return true;
        }
        else if (recursionStack[adjacent])
            return true;
    }
    recursionStack[source] = false;
    return false;
}
bool isCyclic(int V, vector<int> graph[])
{
    bool visited[V + 1] = {0}, recursionStack[V + 1] = {0};
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (DFS(graph, i, visited, recursionStack))
                return true;
        }
    }
    return false;
}
//using BFS
int main()
{
    return 0;
}