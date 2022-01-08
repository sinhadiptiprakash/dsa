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
//recursive
BinaryTree *mirror_of_tree(BinaryTree *root)
{
    if (!root)
        return NULL;
    BinaryTree *leftNode, *rightNode;
    leftNode = mirror_of_tree(root->right);
    rightNode = mirror_of_tree(root->left);
    root->left = leftNode;
    root->right = rightNode;
    return root;
}
//using level order traversal
BinaryTree *mirror_of_tree_iterative(BinaryTree *root)
{
    if (!root)
        return NULL;
    // in queue we push the nodes which we did'nt swap child subtrees of
    queue<BinaryTree *> q;
    q.push(root);
    BinaryTree *node, *temp;
    while (!q.empty())
    {
        node = q.front();
        q.pop();
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
        // swapping the node's left and right subtree;
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
    return root;
}//time complexity O(N)
int main()
{
    return 0;
}