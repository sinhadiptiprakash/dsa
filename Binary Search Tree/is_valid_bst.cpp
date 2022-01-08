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
// using inorder traversal
void inOrder(BSTNode *root, vector<int> &v)
{
    if (!root)
        return;
    inOrder(root->left, v);
    v.push_back(root->data);
    inOrder(root->right, v);
}
bool isValidBST(BSTNode *root)
{
    vector<int> v;
    inOrder(root, v);
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] <= v[i - 1])
            return false;
    }
    return true;
}
// using recursion
bool solve(BSTNode *root, long min, long max)
{
    if (root == NULL)
        return true;
    if (root->data > min && root->data < max &&
        solve(root->left, min, root->data) &&
        solve(root->right, root->data, max))
        return true;
    else
        return false;
}

bool isValidBST(BSTNode *root)
{
    if (solve(root, LLONG_MIN, LLONG_MAX))
        return true;
    return false;
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