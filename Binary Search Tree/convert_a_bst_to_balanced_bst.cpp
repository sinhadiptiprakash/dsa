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
    cout << root->data << ' ';
    inOrder(root->right);
}
void inOrder(BSTNode *root, vector<int> &inorder)
{
    if (!root)
        return;
    inOrder(root->left, inorder);
    inorder.push_back(root->data);
    inOrder(root->right, inorder);
}
BSTNode *bstToBalancedBST(vector<int> &inorder, int start, int end)
{
    if (start > end)
        return NULL;
    int mid = (end + start) / 2;
    BSTNode *root = new BSTNode(inorder[mid]);
    root->left = bstToBalancedBST(inorder, start, mid - 1);
    root->right = bstToBalancedBST(inorder, mid + 1, end);
    return root;
}
BSTNode *bstToBalancedBST(BSTNode *root)
{
    vector<int> inorder;
    inOrder(root, inorder);
    return bstToBalancedBST(inorder, 0, inorder.size() - 1);
} //time complexty is O(N)
int height(BSTNode *root)
{
    if (!root)
        return 0;
    return 1 + max(height(root->left), height(root->right));
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
    inOrder(root);
    cout << endl;
    cout << "before balance height is " << height(root) << endl;
    BSTNode *balancedBST = bstToBalancedBST(root);
    inOrder(balancedBST);
    cout << endl;
    cout << "after balancing height is " << height(balancedBST) << endl;
    return 0;
}