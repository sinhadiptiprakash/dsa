#include <bits/stdc++.h>
using namespace std;
//below is the things and structure neededed for detecting a negative weight cycle using Bellman Ford Algorithm
//which uses dp(bottom up) to actually get single source shortest path in a graph with negative weight
// but here we will use Bellman Ford algo to detect is a negative weight cycle in a graph
//here the function parameter "edges" represent the whole graph
//the function return false if the graph does'nt have any negative weight cycle otherwise true
//along with that the function make a result vector in the parameter passed by reference
//here also the edges are more important than the vertices that's why we use the same addEdge function for adding edge to the graph
bool containsNegativeWeightCycle(int source, vector<vector<int>> &edges, int V)
{
    //distance from starting vertex to itself is 0
    //all the other distances are initialized with INT_MAX for avoiding integer overflow
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;
    // finding the distances of all the vertices using dp
    int u, v, w;
    for (int i = 0; i < V; i++)
    {
        for (auto it : edges)
        {
            int u = it[0], v = it[1], w = it[2];
            if (dist[u] != INT_MAX && dist[v] > dist[u] + w)
                dist[v] = dist[u] + w;
        }
    }
    // checking wheather the graph has a negative weight cycle if so then we simply return true
    // because it wont be possible to compute the distances in a graph which has a negative weight cycle
    for (auto it : edges)
    {
        int u = it[0], v = it[1], w = it[2];
        if (dist[u] != INT_MAX && dist[v] > dist[u] + w)
            return true;
    }
    return false;
}
int main()
{
    return 0;
}