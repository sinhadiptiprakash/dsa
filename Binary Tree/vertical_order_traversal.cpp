#include <bits/stdc++.h>
using namespace std;
struct BinaryTree
{
    int data;
    BinaryTree *left;
    BinaryTree *right;
};
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//recursion
void getVerticalOrder(BinaryTree *root, int hd, map<int, vector<int>> &m)
{
    // Base case
    if (root == NULL)
        return;

    // Store current node in map 'm'
    m[hd].push_back(root->data);

    // Store nodes in left subtree
    getVerticalOrder(root->left, hd - 1, m);

    // Store nodes in right subtree
    getVerticalOrder(root->right, hd + 1, m);
}

// The main function to print vertical order of a binary tree
// with the given root
void printVerticalOrder(BinaryTree *root)
{
    // Create a map and store vertical order in map using
    // function getVerticalOrder()
    map<int, vector<int>> m;
    int hd = 0;
    getVerticalOrder(root, hd, m);

    // Traverse the map and print nodes at every horizontal
    // distance (hd)
    map<int, vector<int>>::iterator it;
    for (it = m.begin(); it != m.end(); it++)
    {
        for (int i = 0; i < it->second.size(); ++i)
            cout << it->second[i] << " ";
        cout << endl;
    }
}

//for gfg practice
vector<int> verticalTraversal(BinaryTree *root)
{
    vector<int> ans;
    // for getting the vectors sorted on horizontal distances
    map<int, vector<int>> mp;
    queue<pair<BinaryTree *, int>> q;
    BinaryTree *temp;
    int horizontal_distance;
    q.push({root, 0});
    while (!q.empty())
    {
        auto pair = q.front();
        q.pop();
        temp = pair.first;
        horizontal_distance = pair.second;
        mp[horizontal_distance].push_back(temp->data);
        if (temp->left)
            q.push({temp->left, horizontal_distance - 1});
        if (temp->right)
            q.push({temp->right, horizontal_distance + 1});
    }
    for (auto value : mp)
    {
        for (int i : value.second)
            ans.push_back(i);
    }
    return ans;
}
int main()
{
    return 0;
}