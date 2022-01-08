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
void inOrder(BSTNode *root, int &k, int &ans)
{
    if (!root)
        return;
    inOrder(root->left, k, ans);
    k--;
    if (k == 0)
    {
        ans = root->data;
        return;
    }
    if (k < 0)
        return;
    inOrder(root->right, k, ans);
}
// Return the Kth smallest element in the given BST
int KthSmallestElement(BSTNode *root, int K)
{
    int k = K, ans = -1;
    inOrder(root, k, ans);
    return ans;
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