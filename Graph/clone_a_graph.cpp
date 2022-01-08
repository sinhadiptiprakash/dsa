#include <bits/stdc++.h>
using namespace std;
// declaration of graph node
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};
class Solution
{
public:
    // dry run to get the logic
    void dfs(Node *copy, Node *node, vector<Node *> &vis)
    {
        vis[copy->val] = copy;
        for (auto i : node->neighbors)
        {
            if (!vis[i->val])
            {
                Node *cpy = new Node(i->val);
                (copy->neighbors).push_back(cpy);
                dfs(cpy, i, vis);
            }
            else
                (copy->neighbors).push_back(vis[i->val]);
        }
    }
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return NULL;
        vector<Node *> vis(101, NULL);
        Node *copy = new Node(node->val);
        dfs(copy, node, vis);
        return copy;
    }
};