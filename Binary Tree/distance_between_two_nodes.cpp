#include <bits/stdc++.h>
using namespace std;
// declaration of Binary tree node
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int d) : data(d), left(NULL), right(NULL){};
};
Node *lca(Node *root, int n1, int n2)
{
    if (!root)
        return NULL;
    if (root->data == n1 || root->data == n2)
        return root;
    Node *left = lca(root->left, n1, n2);
    Node *right = lca(root->right, n1, n2);
    if (left && right)
        return root;
    return (left ? left : right);
}
int preOrder(Node *root, int x, int level)
{
    if (!root)
        return -1;
    if (root->data == x)
        return level;
    int distance = preOrder(root->left, x, level + 1);
    if (distance != -1)
        return distance;
    distance = preOrder(root->right, x, level + 1);
    return distance;
}
int findDist(Node *root, int a, int b)
{
    Node *LCA = lca(root, a, b);
    return preOrder(LCA, a, 0) + preOrder(LCA, b, 0);
}
int main()
{
    return 0;
}