#include <bits/stdc++.h>
using namespace std;
//below is the fucntion for getting the articulation points of a graph using tarjan's algorithm
void artiCulationPointsUtil(vector<vector<int>> &graph, int u, vector<int> &parent, vector<bool> &visited, vector<int> &lowestTime, vector<int> &discoveryTime, set<int> &aPoints)
{
    //static variable time is for keeping the discovery time of vertices
    //it is static because it will not be affected in recursive function calls
    static int time = 0;
    //child is for counting the childs the curent node have
    int child = 0;
    visited[u] = true;
    //discoveryTime is for storing the discovery times of vertices in the dfs tree
    //lowestTime[u] time is the earliest node that can be reached from the subtree[u]
    discoveryTime[u] = lowestTime[u] = ++time;
    for (auto v : graph[u])
    {
        if (!visited[v])
        {
            child++;
            parent[v] = u;
            artiCulationPointsUtil(graph, v, parent, visited, lowestTime, discoveryTime, aPoints);
            //backtracking
            //after returning we update the parent's lowestTime by comparing with child's lowestTime
            lowestTime[u] = min(lowestTime[u], lowestTime[v]);
            //first condition of being an articulation point i.e. the node is root node and it has >1 child
            if (parent[u] == -1 && child > 1)
                aPoints.emplace(u);
            //second condition i.e. not a root node and the the curent node can't be reached by any of the ancestor of u
            else if (parent[u] != -1 && lowestTime[v] >= discoveryTime[u])
                aPoints.emplace(u);
        }
        //if the node v is already visited then if it is not the parent of itself that means it is a backEdge
        else if (v != parent[u]) //back edge
            lowestTime[u] = min(discoveryTime[v], lowestTime[u]);
    }
}
//below is the main function which uses the above util function to get the articulation points of a graph g
set<int> articulationPoints(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> parent(n, -1);
    vector<bool> visited(n, false);
    //we have used a set because same value may be put by the recursive calls in a vector
    set<int> aPoints;
    //value lowestTime[v] indicates earliest visited vertex reachable from subtree rooted with v
    vector<int> lowestTime(n), discoveryTime(n);
    for (int i = 0; i < n; i++)
        if (visited[i] == false)
            artiCulationPointsUtil(graph, i, parent, visited, lowestTime, discoveryTime, aPoints);
    return aPoints;
}
int main()
{
    return 0;
}