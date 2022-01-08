#include <bits/stdc++.h>
using namespace std;
struct BinaryTree
{
    int data;
    BinaryTree *left;
    BinaryTree *right;
    BinaryTree(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

int sum(BinaryTree *root)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return root->data;
    return sum(root->left) + sum(root->right) + root->data;
}
bool isSumTree(BinaryTree *root)
{
    if (!root)
        return true;
    if (!root->left && !root->right)
        return true;
    return (root->data == sum(root->left) + sum(root->right)) && isSumTree(root->left) && isSumTree(root->right);
} //time complexity O(N^2)

/*
Method 2 (Tricky) 
Method 1 uses sum() to get the sum of nodes in left and right subtrees. 
Method 2 uses the following rules to get the sum directly. 
1)If the node is a leaf node then the sum of the subtree rooted with this node is equal to the value of this node. 
2) If the node is not a leaf node then the sum of the subtree rooted with this node is twice the value of this node 
(Assuming that the tree rooted with this node is SumTree).
*/
int isLeaf(BinaryTree *node)
{
    if (node == NULL)
        return 0;
    if (node->left == NULL && node->right == NULL)
        return 1;
    return 0;
}

/* returns 1 if SumTree property holds for the given
    tree */
int isSumTree2(BinaryTree *node)
{
    int ls; // for sum of nodes in left subtree
    int rs; // for sum of nodes in right subtree

    /* If node is NULL or it's a leaf node then
       return true */
    if (node == NULL || isLeaf(node))
        return 1;

    if (isSumTree2(node->left) && isSumTree2(node->right))
    {

        // Get the sum of nodes in left subtree
        if (node->left == NULL)
            ls = 0;
        else if (isLeaf(node->left))
            ls = node->left->data;
        else
            ls = 2 * (node->left->data);

        // Get the sum of nodes in right subtree
        if (node->right == NULL)
            rs = 0;
        else if (isLeaf(node->right))
            rs = node->right->data;
        else
            rs = 2 * (node->right->data);

        /* If root's data is equal to sum of nodes in left
           and right subtrees then return 1 else return 0*/
        return (node->data == ls + rs);
    }
    return 0;
}
int main()
{

    return 0;
}