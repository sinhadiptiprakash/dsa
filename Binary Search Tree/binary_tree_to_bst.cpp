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
void inOrder(BSTNode *&root, int &index, vector<int> order)
{
    if (!root)
        return;
    inOrder(root->left, index, order);
    root->data = order[index++];
    inOrder(root->right, index, order);
}
void inOrder(BSTNode *root, vector<int> &order)
{
    if (!root)
        return;
    inOrder(root->left, order);
    order.push_back(root->data);
    inOrder(root->right, order);
}
BSTNode *binaryTreeToBST(BSTNode *root)
{
    vector<int> order;
    inOrder(root, order);
    sort(order.begin(), order.end());
    int index = 0;
    inOrder(root, index, order);
    return root;
} //time complexity O(Nlog(N)) space complexity O(N)
int main()
{
    return 0;
}