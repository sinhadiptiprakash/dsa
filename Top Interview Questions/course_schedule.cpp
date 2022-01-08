#include <bits/stdc++.h>
using namespace std;
//dfs && detect cycle in a directed graph because we can have Topological ordering of only DAG
vector<vector<int>> buildGraph(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> graph(numCourses);
    for (auto v : prerequisites)
    {
        graph[v[1]].push_back(v[0]);
    }
    return graph;
}
bool isCyclic(int u, vector<bool> &visited, vector<bool> &stack, vector<vector<int>> &graph)
{
    visited[u] = true;
    stack[u] = true;
    for (auto v : graph[u])
    {
        if (!visited[v])
        {
            if (isCyclic(v, visited, stack, graph))
                return true;
        }
        else if (stack[v])
            return true;
    }
    stack[u] = false;
    return false;
}
bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    auto graph = buildGraph(numCourses, prerequisites);
    vector<bool> visited(numCourses, 0), stack(numCourses, 0);
    for (int u = 0; u < numCourses; u++)
    {
        if (isCyclic(u, visited, stack, graph))
            return false;
    }
    return true;
}
//using Kahn's algo for topological sorting
bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{

    vector<int> indegree(numCourses, 0);
    vector<vector<int>> adj(numCourses);

    for (auto i : prerequisites)
    {
        adj[i[1]].push_back(i[0]);
        indegree[i[0]]++;
    }

    queue<int> q;
    //vector<int> res;

    for (int i = 0; i < indegree.size(); i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        //res.push_back(v);
        for (auto i : adj[v])
        {
            indegree[i]--;
            if (indegree[i] == 0)
                q.push(i);
        }
    }

    for (int i = 0; i < indegree.size(); i++)
    {
        if (indegree[i] > 0)
            return false;
    }
    return true;
}
int main()
{
    return 0;
}