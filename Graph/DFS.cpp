#include <bits/stdc++.h>
using namespace std;
void dfs(int source, vector<vector<int>> graph, vector<bool> &visited)
{
    visited[source] = true;
    cout << source << ' ';
    for (auto it : graph[source])
    {
        if (!visited[it])
            dfs(it, graph, visited);
    }
}
int main()
{
    return 0;
}