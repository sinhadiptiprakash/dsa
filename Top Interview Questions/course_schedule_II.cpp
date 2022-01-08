#include <bits/stdc++.h>
using namespace std;
vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> graph(numCourses);
    vector<int> indegree(numCourses, 0);
    vector<int> res;
    for (auto v : prerequisites)
    {
        graph[v[1]].push_back(v[0]);
        indegree[v[0]]++;
    }
    queue<int> q;
    for (int i = 0; i < numCourses; i++)
    {
        if (!indegree[i])
            q.push(i);
    }
    while (!q.empty())
    {
        auto u = q.front();
        q.pop();
        res.push_back(u);
        for (auto v : graph[u])
        {
            if (--indegree[v] == 0)
                q.push(v);
        }
    }
    for (int i = 0; i < numCourses; i++)
    {
        if (indegree[i])
            return {};
    }
    return res;
}
int main()
{
    return 0;
}