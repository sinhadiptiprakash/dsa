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
bool isValid(vector<vector<int>> &graph, int u, vector<int> color, int c)
{
    for (auto it : graph[u])
    {
        //checking wheather there is any adjacent vertex colored with the same color c
        if (color[it] != 0 && color[it] == c)
            return false;
    }
    return true;
}
//. printing ways we can color a graph by using m colors
//the approach is the same as isMColorable difference here is we are printing the color vector
//the below function is for printing the color vector
void printColor(vector<int> &color)
{
    cout << "one way is" << endl;
    for (int i = 0; i < color.size(); i++)
        cout << "color of vertex " << i << " is " << color[i] << endl;
    cout << endl;
}
//below is the main backtracking function for printing the ways to color a graph with m colors
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
void printWays(vector<vector<int>> &graph, int m, int V)
{
    vector<int> color(V, 0);
    printWaysToColorGraph(graph, 0, color, m, V);
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

    printWays(graph, 3, 10);
    return 0;
}