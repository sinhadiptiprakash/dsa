#include <bits/stdc++.h>
using namespace std;
//.............................................................................................................
//below is the implementation of scc or strongly connected components of a directed graph using kosaraju's algorithm
//simple connected components determining algorithm does'nt work here as it is a directed graph, also scc is related to directed graph only
//below dfs is used to get the finishing time for every vertex,
//finish time: when dfs on all the adjacent vertices of a node is completed
//the stack is used to sort the vertices of the graph in decescending order
void dfsForFinishTime(vector<vector<int>> &graph, int u, vector<bool> &visited, stack<int> &Stack)
{
    visited[u] = true;
    for (auto v : graph[u])
    {
        if (!visited[v])
            dfsForFinishTime(graph, v, visited, Stack);
    }
    Stack.push(u);
}
//below is the function for getting the transpose of a graph, i.e. reversing the direction of a graph
vector<vector<int>> transposeOfGraph(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<vector<int>> transpose(n);
    for (int i = 0; i < n; i++)
        for (auto it : graph[i])
            transpose[it].push_back(i);
    return transpose;
}
//below is the simple dfs on vector<vector<int>> graph representation
void dfs(vector<vector<int>> &transposeGraph, int u, vector<bool> &visited)
{
    visited[u] = true;
    cout << u << " ";
    for (auto v : transposeGraph[u])
        if (!visited[v])
            dfs(transposeGraph, v, visited);
}
//below is the main function for printing the strongly connected components
void sccUsingKosaraju(vector<vector<int>> &graph)
{
    int n = graph.size();
    stack<int> Stack;
    vector<bool> visited(n, false);
    vector<vector<int>> transpose = transposeOfGraph(graph);
    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfsForFinishTime(graph, i, visited, Stack);
    visited.assign(n, false);
    cout << "scc are : " << endl;
    while (!Stack.empty())
    {
        auto node = Stack.top();
        Stack.pop();
        if (!visited[node])
        {
            dfs(transpose, node, visited);
            cout << endl;
        }
    }
}
int main()
{
    return 0;
}