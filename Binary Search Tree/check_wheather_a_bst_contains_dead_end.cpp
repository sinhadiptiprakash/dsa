#include <bits/stdc++.h>
using namespace std;
struct BSTNode
{
    int data;
    BSTNode *left;
    BSTNode *right;
    BSTNode(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
void insert(BSTNode **root, int d)
{
    if (*root == NULL)
    {
        *root = new BSTNode(d);
    }
    else
    {
        if (d < (*root)->data)
        {
            insert(&(*root)->left, d);
        }
        else
        {
            insert(&(*root)->right, d);
        }
    }
}
/*
First of all, it is given that it is a BST and nodes are greater than zero, 
root node can be in the range [1, ∞] and if root val is say, val, 
then left sub-tree can have the value in the range [1, val-1] and right sub-tree the value in range [val+1, ∞]. 
we need to traverse recursively and when the the min and max value of range coincided it means 
that we cannot add any node further in the tree. 
Hence we encounter a dead end.
*/
// Returns true if tree with given root contains
// dead end or not. min and max indicate range
// of allowed values for current node. Initially
// these values are full range.
bool deadEnd(BSTNode *root, int min = 1, int max = INT_MAX)
{
    // if the root is null or the recursion moves
    // after leaf node it will return false i.e no dead end.Points: 2
    if (!root)
        return false;

    // if this occurs means dead end is present.
    if (min == max)
        return true;

    // heart of the recursion lies here.
    return deadEnd(root->left, min, root->data - 1) || deadEnd(root->right, root->data + 1, max);
}
int main()
{
    int n, d;
    cin >> n;
    BSTNode *root = NULL;
    while (n--)
    {
        cin >> d;
        insert(&root, d);
    }

    return 0;
}