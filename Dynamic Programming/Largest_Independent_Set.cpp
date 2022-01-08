// A naive recursive implementation of Largest Independent Set problem
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data,pointer to left child and apointer to right child */
class node
{
public:
    int data;
    node *left, *right;
};
// A utility function to create a node
node *newNode(int data)
{
    node *temp = new node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
// The function returns size of the largest independent set in a given binary tree
int LISS(node *root)
{
    if (root == NULL)
        return 0;

    // Calculate size excluding the current node
    int size_excl = LISS(root->left) + LISS(root->right);

    // Calculate size including the current node
    int size_incl = 1;
    if (root->left)
        size_incl += LISS(root->left->left) + LISS(root->left->right);
    if (root->right)
        size_incl += LISS(root->right->left) + LISS(root->right->right);

    // Return the maximum of two sizes
    return max(size_incl, size_excl);
}
int LISSDP(node *root)
{
}
int main()
{
    // Let us construct the tree given in the above diagram
    node *root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);

    cout << "Size of the Largest"
         << " Independent Set is " << LISS(root);
    return 0;
}
