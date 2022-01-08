#include <bits/stdc++.h>
using namespace std;
//its a very important problem on TOPOLOGICAL SORTING
// Appraoch:
// 1. create a graph from the given sorted list of word
// for creating a graph from the word list for every pair of word in the list compare each and every character of the words
// find the first mismatching character then make an edge from mismatch character of word[i-1] to mismatch character of word[i]
//2. find the topological sorting of the created graph
void addEdge(vector<vector<int>> &graph, int u, int v)
{
    graph[u].push_back(v);
}
vector<vector<int>> makeGraph(int N, string dict[], int k)
{
    vector<vector<int>> graph(k);
    for (int i = 0; i < N - 1; i++)
    {
        string word1 = dict[i], word2 = dict[i + 1];
        int len = min(word1.length(), word2.length());
        for (int j = 0; j < len; j++)
        {
            if (word1[j] != word2[j])
            {
                addEdge(graph, word1[j] - 'a', word2[j] - 'a');
                break;
            }
        }
    }
    return graph;
}
vector<int> getIndegree(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto it : graph[i])
            indegree[it]++;
    }
    return indegree;
}
string topologicalSort(vector<vector<int>> &graph)
{
    int n = graph.size();
    queue<int> q;
    vector<int> indegree = getIndegree(graph);
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    string res = "";
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        res.push_back('a' + temp);
        for (auto it : graph[temp])
        {
            if (--indegree[it] == 0)
                q.push(it);
        }
    }
    return res;
}
string alienDictionary(int n, int k, string dict[])
{
    auto graph = makeGraph(n, dict, k);
    return topologicalSort(graph);
}
int main()
{
    string dict[] = {"baa", "abcd", "abca", "cab", "cad"};
    int k = 4;
    int n = 5;
    cout << alienDictionary(n, k, dict) << endl;
}