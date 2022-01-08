#include <bits/stdc++.h>
using namespace std;
void bfs(int source, vector<list<int>> &graph)
{
    vector<bool> visited(graph.size(), 0);
    queue<int> q;
    q.push(source);
    visited[source] = true;
    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();
        cout << vertex << ' ';
        for (auto it : graph[vertex])
        {
            if (!visited[it])
            {
                q.push(it);
                visited[it] = true;
            }
        }
    }
}
int main()
{
    return 0;
}