#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> *getGraphWithOriginalAndReversedEdges(vector<int> graph[], int V)
{
    vector<vector<int>> *newGraph = new vector<vector<int>>[V];
    for (int i = 0; i < V; i++)
    {
        for (auto it : graph[i])
        {
            newGraph[i].push_back({it, 0});
            newGraph[it].push_back({i, 1});
        }
    }
    return newGraph;
}
void addEdge(vector<int> graph[],int u,int v){
    graph[u].push_back(v);
}
int dijkstra(vector<vector<int>> graph[],int V,int source,int des){
    vector<int> cost(V, 1e9);
    set<pair<int, int>> minHeap;
    minHeap.insert({0,source});
    cost[source] = 0;
    while(!minHeap.empty()){
        auto p = *minHeap.begin();
        int vertex = p.second;
        minHeap.erase(minHeap.begin());
        //int weight = p.second;
        for(auto it:graph[vertex]){
            int v = it[0], w = it[1];
            if (cost[v] == 1e9){
                cost[v] = cost[vertex] + w;
                minHeap.insert({cost[v], v});
            }
            else if(cost[v]>cost[vertex]+w){
                minHeap.erase({cost[v], v});
                cost[v] = cost[vertex] + w;
                minHeap.insert({cost[v], v});
            }
        }
    }
    return cost[des];
}
int minReversal(vector<int> graph[],int n,int source,int des){
    vector<vector<int>> *newGraph = getGraphWithOriginalAndReversedEdges(graph,n);
    return dijkstra(newGraph, n, source, des);
}
int main()
{
    int n, e,u,v,w,source,des;
    cin >> n >> e;
    vector<int> *graph=new vector<int>[n];
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v;
        addEdge(graph, u, v);
    }
    cin >> source >> des;
    cout << minReversal(graph, n, source, des) << endl;
    return 0;
}