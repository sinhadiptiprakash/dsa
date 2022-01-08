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
// inOrder successor is the min. value in right subtree for getting the min value at right side
BSTNode *minValue(BSTNode *node)
{
    BSTNode *curent = node;
    // as the bottom left most node is the mininmum
    while (curent && curent->left)
        curent = curent->left;
    return curent;
}
BSTNode *delete_key(BSTNode *root, int key)
{
    if (!root)
        return root;
    // if key is less than root->data we should go for deleting in the left subtree
    if (key < root->data)
        root->left = delete_key(root->left, key);
    // else we go for the right subtree
    else if (key > root->data)
        root->right = delete_key(root->right, key);
    // else if the root->data is the key i.e. root is the node to be deleted
    else
    {
        // if root does'nt have any subtree return null because after deleting root there will be nothing
        if (!root->left && !root->right)
            return NULL;
        // if root does'nt have its left subtree then we should make root->right as root and delete root
        else if (!root->left)
        {
            BSTNode *temp = root->right;
            delete (root);
            return temp;
        }
        // similarly if root does'nt have its right subtree then we should make root->left as root and delete root
        else if (!root->right)
        {
            BSTNode *temp = root->left;
            delete (root);
            return temp;
        }
        // now if root has both the sub tree then we should replace the root->data with the root's inOrderSucessor's data
        // inOrder sucessor of a node is nothing but minnimum element in its right subtree

        // Find nOrder successor as well as the parent of that inOrder Successor
        BSTNode *successorParent = root;
        BSTNode *inOrderSuccessor = root->right;
        while (inOrderSuccessor->left)
        {
            successorParent = inOrderSuccessor;
            inOrderSuccessor = inOrderSuccessor->left;
        }
        // Delete successor.  Since successor is always left child of its parent
        // we can safely make successor's right child as left of its parent.
        // If there is no inOrderSuccssor, then assign inOrderSuccssor->right to successorParent->right
        if (successorParent != root)
            successorParent->left = inOrderSuccessor->right;
        else
            successorParent->right = inOrderSuccessor->right;
        // Copy Successor Data to root
        root->data = inOrderSuccessor->data;
        // Delete Successor and return root
        delete (inOrderSuccessor);
    }
    return root;
}
void inOrder(BSTNode *root)
{
    if (!root)
        return;
    inOrder(root->left);
    cout << root->data << ' ';
    inOrder(root->right);
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
    inOrder(root);
    delete_key(root, 7);
    cout << endl;
    inOrder(root);
    return 0;
}