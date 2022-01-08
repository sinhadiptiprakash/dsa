#include <bits/stdc++.h>
using namespace std;
// binary tree node
struct BinaryTree
{
    int data;
    BinaryTree *left, *right;
    BinaryTree(int x)
    {
        data = x;
        left = right = NULL;
    }
};
BinaryTree *lca(BinaryTree *root, int n1, int n2)
{
    if (!root)
        return NULL;
    if (root->data == n1 || root->data == n2)
        return root;
    BinaryTree *left = lca(root->left, n1, n2);
    BinaryTree *right = lca(root->right, n1, n2);
    if (left && right)
        return root;
    return (left ? left : right);
}
int main()
{
    BinaryTree *node1 = new BinaryTree(1);
    BinaryTree *node2 = new BinaryTree(2);
    BinaryTree *node3 = new BinaryTree(3);
    BinaryTree *node4 = new BinaryTree(1);
    BinaryTree *node5 = new BinaryTree(2);
    BinaryTree *node6 = new BinaryTree(1);
    BinaryTree *node7 = new BinaryTree(2);
    BinaryTree *node8 = new BinaryTree(-1);
    BinaryTree *node9 = new BinaryTree(3);

    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;
    node7->right = node8;
    node8->right = node9;

    int k = 4;
    BinaryTree *LCA = lca(node1, 3, -1);
    cout << LCA->data << endl;
    return 0;
}