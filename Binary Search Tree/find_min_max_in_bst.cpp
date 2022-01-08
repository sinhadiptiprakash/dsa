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
int min_in_bst(BSTNode *root){
    if(!root)
        return INT_MAX;
    BSTNode *curent = root;
    while(curent && curent->left)
        curent = curent->left;
    return curent->data;
}
int max_in_bst(BSTNode *root){
    if(!root)
        return INT_MIN;
    BSTNode *curent = root;
    while (curent && curent->right)
        curent = curent->right;
    return curent->data;
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
    cout << min_in_bst(root) << endl;
    cout << max_in_bst(root) << endl;
    return 0;
}