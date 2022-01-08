#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> *graph(int n, int p, vector<int> &a, vector<int> &b, vector<int> &in, vector<int> &out)
    {
        vector<int> *g = new vector<int>[n + 1];
        for (int i = 0; i < p; i++)
        {
            g[a[i]].push_back(b[i]);
            in[b[i]] += 1;
            out[a[i]] += 1;
        }
        return g;
    }
    void dfs(int src, vector<int> graph[], vector<int> &diameter, vector<bool> &visited, vector<int> &in, vector<int> &out, int &end, int &minDia)
    {
        visited[src] = 1;
        minDia = min(minDia, diameter[src]);
        if (!out[src])
            end = src;
        for (auto v : graph[src])
        {
            if (!visited[v])
                dfs(v, graph, diameter, visited, in, out, end, minDia);
        }
    }
    vector<vector<int>> solve(int n, int p, vector<int> &a, vector<int> &b, vector<int> &d)
    {
        vector<int> in(n + 1, 0), out(n + 1, 0);
        vector<bool> visited(n + 1, 0);
        vector<int> *g = graph(n, p, a, b, in, out);
        vector<int> diameter(n + 1, 101);
        for (int i = 0; i < p; i++)
            diameter[a[i]] = d[i];
        vector<vector<int>> res;
        int t = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i] && out[i] != 0 & in[i] == 0)
            {
                int end, minDia = 102;
                dfs(i, g, diameter, visited, in, out, end, minDia);
                t++;
                res.push_back({i, end, minDia});
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}