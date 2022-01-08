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
void inOrder(BSTNode *root)
{
    if (!root)
        return;
    inOrder(root->left);
    cout << root->data << ' ';
    inOrder(root->right);
}
BSTNode *LCA(BSTNode *root, int n1, int n2)
{
    if (!root)
        return NULL;
    if (n1 < root->data && n2 < root->data)
        return LCA(root->left, n1, n2);
    if (n1 > root->data && n2 > root->data)
        return LCA(root->right, n1, n2);
    return root;
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
    BSTNode *node = LCA(root, 4, 5);
    cout << node->data << endl;
    return 0;
}