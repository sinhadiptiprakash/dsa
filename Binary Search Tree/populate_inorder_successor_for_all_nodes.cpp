#include <bits/stdc++.h>
using namespace std;
struct BSTNode
{
    int data;
    BSTNode *left;
    BSTNode *right;
    BSTNode *next;
    BSTNode(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};
void insert(BSTNode **root, int d)
{
    if (*root == NULL)
        *root = new BSTNode(d);
    else
    {
        if (d < (*root)->data)
            insert(&(*root)->left, d);
        else
            insert(&(*root)->right, d);
    }
}
void inOrder(BSTNode *root)
{
    if (!root)
        return;
    inOrder(root->left);
    if (root->next)
        cout << root->next->data << ' ';
    else
        cout << -1 << ' ';
    inOrder(root->right);
}
// using a vector to the inOrder traversal nodes
void inOrder(BSTNode *root, vector<BSTNode *> &v)
{
    if (!root)
        return;
    inOrder(root->left, v);
    v.push_back(root);
    inOrder(root->right, v);
}
void populateInOrderSuccessors(BSTNode *root)
{
    vector<BSTNode *> v;
    inOrder(root, v);
    int n = v.size();
    for (int i = 0; i < n - 1; i++)
        v[i]->next = v[i + 1];
    v[n - 1]->next = NULL;
}
// recursive way
void inorder(BSTNode *root, BSTNode **prev)
{
    if (!root)
        return;
    inorder(root->left,prev);
    if ((*prev))
        (*prev)->next = root;
    (*prev) = root;
    inorder(root->right, prev);
}
void populateNext(BSTNode *root)
{
    BSTNode *prev = NULL;
    inorder(root, &prev);
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
    populateInOrderSuccessors(root);
    inOrder(root);
    return 0;
}