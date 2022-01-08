#include <bits/stdc++.h>
using namespace std;
//graph coloring is nothing but whether all the vertices of a graph can be colored by using only m colors
//keeping the condition: no two adjacent vertices are colored with the same color
//there are mainly three types of graph coloring problems:....
//1. checking wheather a graph's  can be colored by using only m colors
//2. printing ways we can color a graph
//3. min no. of color required to color a graph

void addEdge(vector<vector<int>> &graph, int u, int v)
{
    graph[u].push_back(v);
    //for undirected graph enable the coment line below
    graph[v].push_back(u);
}
//for checking if a color c is valid for the vertex u
bool isValid(vector<vector<int>> &graph, int u, const vector<int> &color, int c)
{
    for (auto it : graph[u])
    {
        //checking wheather there is any adjacent vertex colored with the same color c
        if (color[it] != 0 && color[it] == c)
            return false;
    }
    return true;
}
//1. checking wheather a graph's  can be colored by using only m colors
bool isMColorable(vector<vector<int>> &graph, int u, vector<int> &color, int m, int v)
{
    //if all vertices are colored return true
    if (u == v)
        return true;
    for (int c = 1; c <= m; c++)
    {
        //checking if the color c is valid for vertex u or not
        if (isValid(graph, u, color, c))
        {
            //if c is valid for vertex u assign color c to vertex u
            color[u] = c;
            //checking recursively other vertices by increamenting u
            if (isMColorable(graph, u + 1, color, m, v))
                return true;
            //backtracking
            color[u] = 0;
        }
    }
    return false;
}
bool isMColorable(vector<vector<int>> &graph, int m, int v)
{
    vector<int> color(v + 1, 0);
    return isMColorable(graph, 0, color, m, v);
}
//if a graph is 2 colorable i.e. if a graph can be colored using 2 colors only then the graph is a bipartite graph

//2. printing ways we can color a graph
//the approach is the same as isMColorable difference here is we are printing the color vector
//the below function is for printing the color vector
void printColor(vector<int> &color)
{
    cout << "one way is" << endl;
    for (int i = 0; i < color.size(); i++)
        cout << "color of vertex " << i << " is " << color[i] << endl;
    cout << endl;
}
//below is the main backtracking function for printing the ways
void printWaysToColorGraph(vector<vector<int>> &graph, int u, vector<int> &color, int m, int v)
{
    //checking if the coloring is completed for all vertices then print the colors and return
    if (u == v)
    {
        printColor(color);
        return;
    }
    //else choose a color and check if it is a valid color for vertex u
    for (int c = 1; c <= m; c++)
    {
        if (isValid(graph, u, color, c))
        {
            color[u] = c;
            //recursively call for next vertex
            printWaysToColorGraph(graph, u + 1, color, m, v);
            //backtracking with reseting color of vertex u
            color[u] = 0;
        }
    }
}
//3. min no. of color required to color a graph
int minNumOfColors(vector<vector<int>> &graph, int v)
{
    for (int m = 0; m < v; m++)
        if (isMColorable(graph, m, v))
            return m;
    return -1;
}
//checking a graph is bipartite or not
bool isBipartite(vector<vector<int>> &graph, int v)
{
    //if a graph is 2 colorable then the graph is a bipartite graph
    return isMColorable(graph, 2, v);
}
//below function also checks for bipartite-nes of a graph using BFS(Level-Order-Traversal) to color the graph using two color only
bool isBipartiteUsingBFS(vector<vector<int>> &graph, int v)
{
    vector<int> color(v, 0);
    queue<int> q;
    //we start from the 0 th node and color it with color1 and  push it into q
    color[0] = 1;
    q.push(0);
    int node;
    while (!q.empty())
    {
        node = q.front();
        q.pop();
        for (auto adjacent : graph[node])
        {
            //if there is self loop return false because in bipartite graph the graph is divided into two set
            //such that every vertex from one set connects to the vertex on the other set
            //and there should not be any edge connecting vertices of the same set
            if (adjacent == node)
                return false;
            //if the adjacent vertex is not yet colored yet
            if (!color[adjacent])
            {
                //color it with color1 or color2
                color[adjacent] = 1 - color[node];
                q.push(adjacent);
            }
            //if the adjacent vertex is colored with the same as the node then return false
            else if (color[adjacent] == color[node])
                return false;
        }
    }
    return true;
}
int main()
{
    vector<vector<int>> graph(10);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 0, 5);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 6);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 8);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 9);
    addEdge(graph, 4, 7);
    addEdge(graph, 5, 8);
    addEdge(graph, 5, 9);
    addEdge(graph, 6, 7);
    addEdge(graph, 6, 9);
    addEdge(graph, 7, 8);
    cout << isMColorable(graph, 3, 10) << endl;
    return 0;
}