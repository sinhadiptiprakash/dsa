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
// This function finds predecessor and successor of data in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(BSTNode *root, BSTNode *&pre, BSTNode *&suc, int key)
{
    BSTNode *p = NULL, *s = NULL;
    while (root && root->data != key)
    {
        if (root->data < key)
        {
            p = root;
            root = root->right;
        }
        else
        {
            s = root;
            root = root->left;
        }
    }
    if (!root)
    {
        pre = p;
        suc = s;
        return;
    }
    if (!root->right)
        suc = s;
    else
    {
        BSTNode *curr = root->right;
        while (curr->left)
            curr = curr->left;
        suc = curr;
    }
    if (!root->left)
        pre = p;
    else
    {
        BSTNode *curr = root->left;
        while (curr->right)
            curr = curr->right;
        pre = curr;
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    BSTNode *root = NULL;
    for (int i = 0; i < n; i++)
    {
        insert(&root, a[i]);
    }
    return 0;
}