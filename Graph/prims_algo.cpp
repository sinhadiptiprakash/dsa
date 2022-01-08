#include <bits/stdc++.h>
using namespace std;
struct comp
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.second > b.second;
    }
};
//below is the implementation of Prim's minimum spanning tree
//the algorithms is pretty similar to the dijkstra's algorithm, diff. is we here keep the weights only as distances
//and that's why this algo can be easily implemented using a priority queue directly
//it returns the spanning tree path of the graph,we can return the distance table as well
vector<vector<int>> primsMST(vector<vector<int>> graph[], int V)
{
    //key is for storing the processed vertex's weights
    //parent is for storing the parent of a vertex
    //inMST is for storing the included vertex in the mst
    //result will store in the following format:<source,des,weight>
    //here I have used a map we can use vector or array as well
    int source = 0;
    vector<int> key(V, INT_MAX), parent(V, -1);
    vector<bool> inMST(V, 0);
    vector<vector<int>> result;
    pair<int, int> p;
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
    key[source] = 0;
    pq.push({source, 0});
    while (!pq.empty())
    {
        p = pq.top();
        pq.pop();
        int vertex = p.first;
        //checking wheather the vertex is processed so far has connected to a parent and the vertex is
        //not included in the mst or not, then we include this vertex to the result with the weight and include in Mst
        if (parent[vertex] != -1 && !inMST[vertex])
            result.push_back({parent[vertex], vertex, key[vertex]});
        inMST[vertex] = true;
        for (auto adjacent : graph[vertex])
        {
            //if this adjacent vertex is not included and (the adjacent is not yet processed
            // i.e. not in the key or the weight of this vertex so far is greater than the curent weight from top.first )
            int adj_vertex = adjacent[0], weight = adjacent[1];
            if (!inMST[adj_vertex] && key[adj_vertex] > weight)
            {
                //update the parent,key, and add push(adjacent vertex,weight)
                parent[adj_vertex] = vertex;
                key[adj_vertex] = weight;
                pq.push(make_pair(adj_vertex, key[adj_vertex]));
            }
        }
    }
    return result;
}
int main()
{
    int u, v, w;
    vector<vector<int>> graph[9];
    for (int i = 0; i < 14; i++)
    {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    cout << "PRIM'S MST" << endl;
    auto mst = primsMST(graph, 9);
    for (auto v : mst)
        cout << v[0] << ' ' << v[1] << ' ' << v[2] << endl;
    return 0;
}