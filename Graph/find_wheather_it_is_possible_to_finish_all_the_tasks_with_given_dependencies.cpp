#include <bits/stdc++.h>
using namespace std;
// to detect a cycle in a directed graph
bool dfs(const vector<int> graph[], int start, vector<bool> &visited, vector<bool> &recursionStack)
{
    visited[start] = true;
    recursionStack[start] = true;
    for (auto it : graph[start])
    {
        if (!visited[it] && dfs(graph, it, visited, recursionStack))
            return true;
        else if (recursionStack[it])
            return true;
    }
    recursionStack[start] = false;
    return false;
}
vector<int> *makeGraph(int numOfTasks, const vector<pair<int, int>> &prerequisites)
{
    vector<int> *graph = new vector<int>[numOfTasks];
    for (auto pre : prerequisites)
    {
        //adding a directed edge
        graph[pre.second].push_back(pre.first);
    }
    return graph;
}
bool isPossibleToFinish(int numOfTasks, vector<pair<int, int>> &prerequisites)
{
    auto graph = makeGraph(numOfTasks, prerequisites);
    vector<bool> visited(numOfTasks, 0), recursionStack(numOfTasks, 0);
    for (int i = 0; i < numOfTasks; i++)
    {
        if (!visited[i] && dfs(graph, i, visited, recursionStack))
            return false;
    }
    return true;
}
int main()
{
    int numOfTasks, edges;
    cin >> numOfTasks >> edges;
    vector<pair<int, int>> prerequisites(edges);
    for (int i = 0; i < edges; i++)
    {
        cin >> prerequisites[i].first >> prerequisites[i].second;
    }
    cout << (isPossibleToFinish(numOfTasks, prerequisites) ? "POSSIBLE" : "IMPOSSIBLE") << endl;
    return 0;
}