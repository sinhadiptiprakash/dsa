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
// using inOrder traversal with range and a counter
void inOrder(BSTNode *root, int l, int h, int &count)
{
    if (!root)
        return;
    inOrder(root->left, l, h, count);
    if (root->data >= l && root->data <= h)
        count++;
    if (root->data > h)
        return;
    inOrder(root->right, l, h, count);
}
//Function to count number of nodes in BST that lie in the given range.
int getCount(BSTNode *root, int l, int h)
{
    int count = 0;
    inOrder(root, l, h, count);
    return count;
} //time complexity O(N)
// another appraoch using recursion and utilizing the BST property
int getCountEfficient(BSTNode *root, int l, int h)
{
    if (!root)
        return 0;
    int count = (root->data <= h && root->data >= l) ? 1 : 0;
    if (h <= root->data)
        return count + getCountEfficient(root->left, l, h);
    if (l >= root->data)
        return count + getCountEfficient(root->right, l, h);
    return count + getCountEfficient(root->left, l, h) + getCountEfficient(root->right, l, h);
}

int main()
{
    return 0;
}