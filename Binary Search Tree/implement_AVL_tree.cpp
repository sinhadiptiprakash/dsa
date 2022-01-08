#include <bits/stdc++.h>
using namespace std;
struct AVLTree
{
    int data;
    AVLTree *left;
    AVLTree *right;
    int height;
    AVLTree(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
        height = 0;
    }
};
// when we insert a node in the left subtree of the left child of node X then we need LeftLeft single rotation to balance it
// LeftLeft rotation rotate the unbalanced node in opposite direction i.e. in the right direction
int height(AVLTree *root)
{
    if (!root)
        return 0;
    return root->height;
}
AVLTree *LLRotation(AVLTree *X)
{
    AVLTree *W = X->left;
    X->left = W->right;
    W->right = X;
    //now update the heights
    X->height = max(height(X->left), height(X->right)) + 1;
    W->height = max(height(W->left), X->height) + 1;
    return W;
}
// when we insert a node in the right subtree of the node w's right child, we need RR single rotation to balance it
// RightRight rotation rotate the unbalanced node in opposite direction i.e. in the left direction
AVLTree *RRRotation(AVLTree *W)
{
    AVLTree *X = W->right;
    W->right = X->left;
    X->left = W;
    W->height = max(height(W->left), height(W->right)) + 1;
    X->height = max(W->height, height(X->right)) + 1;
    return X;
}
// when we insert a node in the left subtree of the right child of the node Z, then we need Double rotation to balance it
// LeftRight rotation means rotate the Z's leftchild LLRotation and in Z's leftChild's right Subtree with RR rotation
AVLTree *LRRotation(AVLTree *Z)
{
    Z->left = LLRotation(Z->left);
    return RRRotation(Z);
}
AVLTree *RLRotation(AVLTree *X)
{
    X->right = RRRotation(X->right);
    return LLRotation(X);
}
AVLTree *insert(AVLTree *root, int data)
{
    if (!root)
        return new AVLTree(data);
    if (data < root->data)
    {
        root->left = insert(root->left, data);
        // if we need balancing
        if (height(root->left) - height(root->right) == 2)
        {
            if (data < root->left->data)
            {
                root = LLRotation(root);
            }
            else
                root = LRRotation(root);
        }
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
        //if we need balancing
        if (height(root->right) - height(root->left) == 2)
        {
            if (data < root->right->data)
                root = RRRotation(root);
            else
                root = RLRotation(root);
        }
    }
    root->height = max(height(root->left), height(root->right)) + 1;
    return root;
}
void inOrder(AVLTree *root)
{
    if (!root)
        return;
    inOrder(root->left);
    cout << root->data << ' ';
    inOrder(root->right);
}
int main()
{
    int n, d;
    cin >> n;
    AVLTree *root = NULL;
    while (n--)
    {
        cin >> d;
        root = insert(root, d);
    }
    inOrder(root);
    return 0;
}