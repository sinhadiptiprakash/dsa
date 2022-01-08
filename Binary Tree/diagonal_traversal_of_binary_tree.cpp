#include <bits/stdc++.h>
using namespace std;
struct BinaryTree
{
    int data;
    BinaryTree *left;
    BinaryTree *right;
    BinaryTree(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
//recursive way
void diagonalPrintUtil(BinaryTree *root, int d, map<int, vector<int>> &map)
{
    // Base case
    if (!root)
        return;
    // Store all nodes of same line together as a vector
    map[d].push_back(root->data);
    // Increase the vertical distance if left child
    diagonalPrintUtil(root->left, d + 1, map);
    // Vertical distance remains same for right child
    diagonalPrintUtil(root->right, d, map);
}
// Print diagonal traversal of given binary tree
vector<int> diagonalPrint(BinaryTree *root)
{
    // create a map of vectors to store Diagonal elements
    vector<int> res;
    map<int, vector<int>> map;
    diagonalPrintUtil(root, 0, map);
    for (auto it : map)
    {
        vector<int> v = it.second;
        for (auto it : v)
            res.push_back(it);
    }
    return res;
}
// using level order traversal
vector<int> diagonal_traversal(BinaryTree *root)
{
    vector<int> result;
    if (!root)
        return result;
    // The leftQueue will be a queue which will store all left pointers while traversing the tree,
    // and will be utilized when at any point right pointer becomes NULL
    queue<BinaryTree *> leftQueue;
    BinaryTree *node = root;
    while (node)
    {
        // Add current node to output
        result.push_back(node->data);
        // If left child available, add it to queue
        if (node->left)
            leftQueue.push(node->left);
        // if right child, transfer the node to right
        if (node->right)
            node = node->right;
        else
        {
            // If left child Queue is not empty, utilize it to traverse further
            if (!leftQueue.empty())
            {
                node = leftQueue.front();
                leftQueue.pop();
            }
            else
            {
                // All the right childs traversed and no left child left
                node = NULL;
            }
        }
    }
    return result;
}
//using level Order traversal
vector<int> diagonalTraversal(BinaryTree *root){
    map<int, vector<int>> mp;
    queue<pair<BinaryTree *, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        auto temp = q.front();
        q.pop();
        mp[temp.second].push_back(temp.first->data);
        if(temp.first->left)
            q.push({temp.first->left, temp.second +1});
        if(temp.first->right)
            q.push({temp.first->right,temp.second});
    }
    vector<int> res;
    for(auto it:mp){
        for (auto i:it.second)
            res.push_back(i);
    }
    return res;
}
int main()
{
    BinaryTree *node1 = new BinaryTree(1);
    BinaryTree *node2 = new BinaryTree(2);
    BinaryTree *node3 = new BinaryTree(3);
    BinaryTree *node4 = new BinaryTree(4);
    BinaryTree *node5 = new BinaryTree(5);
    BinaryTree *node6 = new BinaryTree(6);
    BinaryTree *node7 = new BinaryTree(7);
    BinaryTree *node8 = new BinaryTree(8);
    BinaryTree *node9 = new BinaryTree(9);
    BinaryTree *node10 = new BinaryTree(10);
    BinaryTree *node11 = new BinaryTree(11);
    BinaryTree *node12 = new BinaryTree(12);
    BinaryTree *node13 = new BinaryTree(13);

    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->right = node6;
    node4->right = node7;
    node5->right = node8;
    node6->right = node9;
    node7->left = node12;
    node12->right = node11;
    node12->left = node10;
    node10->left = node13;

    vector<int> res = diagonalTraversal(node1);
    for (int i : res)
        cout << i << ' ';
    return 0;
}