#include <bits/stdc++.h>
using namespace std;
/*An important part to understanding the Bellman Ford 's working is that at each step, 
the relaxations lead to the discovery of new shortest paths to nodes. 
After the first iteration over all the vertices, the algorithm finds out all the shortest paths
 from the source to nodes which can be reached with one hop (one edge). 
 That makes sense because the only edges we' ll be able to relax are the ones 
 that are directly connected to the source as all the other nodes have shortest distances set to inf initially.
 Similarly, after the (K+1)th step, Bellman-Ford will find the shortest distances for all the nodes 
 that can be reached from the source using a maximum of K stops.
*/
bool bellManFord(int source, vector<vector<int>> &edges, int V)
{
    //all the other distances are initialized with INT_MAX
    // initializing the distance of all vertices to the source to INT_MAX is called OVER ESTIMATION PROCESS
    vector<int> dist(V, INT_MAX);
    //distance from starting vertex to itself is 0
    dist[source] = 0;
    // finding the distances of all the vertices using dp
    int u, v, w;

    // N.B:  we have to run the RELAXTION process for V-1 times because:
    // n−1 is the maximal length of a shortest path in the graph
    // After k iterations of the Bellman–Ford algorithm,
    // you know the minimum distance between any two vertices, when restricted to paths of length at most k.
    // This is why you need n−1 iterations.
    // Negative weights have absolutely nothing to do with it.
    for (int i = 0; i < V - 1; i++)
    {
        bool needUpdate = false;
        // below step is called RELAXATION
        for (auto it : edges)
        {
            int u = it[0], v = it[1], w = it[2];
            if (dist[u] != INT_MAX && dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                needUpdate = true;
            }
        }
    }
    // checking wheather the graph has a negative weight cycle if so then we simply return false
    // because it wont be possible to compute the distances in a graph which has a negative weight cycle
    for (auto it : edges)
    {
        int u = it[0], v = it[1], w = it[2];
        if (dist[u] != INT_MAX && dist[v] > dist[u] + w)
            return false;
    }
    return true;
}
int main()
{
    return 0;
}