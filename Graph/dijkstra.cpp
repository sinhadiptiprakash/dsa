#include <bits/stdc++.h>
using namespace std;
// here the graph is represented as an array of vector<vector<int>> i.e. in each cell of the array there is a vector<vector<int>>
// inside most vector is a 2-element vector which represents an adjacent node and its corresponding weight

//using set as min_heap as set allow us to delete a value from it so we can update a node-distance pair in the min_heap
vector<int> dijkstra(int V, vector<vector<int>> graph[], int source)
{
    vector<int> distance(V, -1);
    set<pair<int, int>> min_heap;
    min_heap.insert({0, source});
    distance[source] = 0;
    while (!min_heap.empty())
    {
        auto p = (*min_heap.begin());
        min_heap.erase(min_heap.begin());
        for (auto adjacentVector : graph[p.second])
        {
            if (distance[adjacentVector[0]] == -1)
            {
                distance[adjacentVector[0]] = distance[p.second] + adjacentVector[1];
                min_heap.insert({distance[adjacentVector[0]], adjacentVector[0]});
            }
            else if (distance[adjacentVector[0]] > distance[p.second] + adjacentVector[1])
            {
                min_heap.erase({distance[adjacentVector[0]], adjacentVector[0]});
                distance[adjacentVector[0]] = distance[p.second] + adjacentVector[1];
                min_heap.insert({distance[adjacentVector[0]], adjacentVector[0]});
            }
        }
    }
    return distance;
}
//using priority queue but in case of priority queue as there are no updating facility available we have to use a
// visited vector to avoid infinite loop or a lot execution time
vector<int> dijkstra(int n, vector<vector<int>> graph[], int source)
{
    int visited[n] = {false};
    vector<int> distance(n, INT_MAX);
    distance[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({distance[source], source});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;

        for (auto adjacentVector : graph[u])
        {
            if (!visited[adjacentVector[0]] && distance[adjacentVector[0]] > distance[u] + adjacentVector[1])
            {
                distance[adjacentVector[0]] = distance[u] + adjacentVector[1];
                pq.push({distance[adjacentVector[0]], adjacentVector[0]});
            }
        }
    }
    return distance;
}
int main()
{
    return 0;
}