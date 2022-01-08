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

/*Method 1 (Insert elements of the first tree to second) 
Take all elements of first BST one by one, and insert them into the second BST. 
Inserting an element to a self balancing BST takes Logn time. where n is size of the BST. */
/*Method 2 (Merge Inorder Traversals) 
1) Do inorder traversal of first tree and store the traversal in one temp array arr1[]. 
    This step takes O(m) time. 
2) Do inorder traversal of second tree and store the traversal in another temp array arr2[]. 
    This step takes O(n) time. 
3) The arrays created in step 1 and 2 are sorted arrays. Merge the two sorted arrays into one array 
    of size m + n. This step takes O(m+n) time. 
4) Construct a balanced tree from the merged array using the technique discussed in the convert bst to balance bst problem
    . This step takes O(m+n) time.
Time complexity of this method is O(m+n) which is better than method 1. This method takes O(m+n) time even if the input BSTs are not balanced. */

/*
Method 3 (In-Place Merge using DLL) 
We can use a Doubly Linked List to merge trees in place. Following are the steps.
1) Convert the given two Binary Search Trees into doubly linked list in place. 
2) Merge the two sorted Linked Lists.
3) Build a Balanced Binary Search Tree from the merged list created in step 2.
Time complexity of this method is also O(m+n) and this method does conversion in 
*/
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