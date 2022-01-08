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
int height(BinaryTree *node)
{
    if (!node)
        return 0;
    return 1 + max(height(node->left), height(node->right));
}
bool isBalanced(BinaryTree *root)
{
    // Edge case
    if (!root)
        return true;

    // We know a node is height balanced if difference between its left and right subtree is <= 1
    // So we return false if either the height difference between its left and right subtree is more than 1, or its left or right subtrees are not balanced
    if ((abs(height(root->left) - height(root->right)) > 1) || !isBalanced(root->left) || !isBalanced(root->right))
    {
        return false;
    }

    return true;
} //time complexity is O(N^2)
/*
Optimized implementation: Above implementation can be optimized by calculating the height in the same recursion 
 rather than calling a height() function separately. This optimization reduces time complexity to O(n). 
*/
bool isBalanced(BinaryTree *root, int &height)
{

    /* lh --> Height of left subtree
    rh --> Height of right subtree */
    int lh = 0, rh = 0;

    /* l will be true if left subtree is balanced
    and r will be true if right subtree is balanced */
    int l = 0, r = 0;

    if (root == NULL)
    {
        height = 0;
        return 1;
    }

    /* Get the heights of left and right subtrees in lh and rh
    And store the returned values in l and r */
    l = isBalanced(root->left, lh);
    r = isBalanced(root->right, rh);

    /* Height of current node is max of heights of left and
    right subtrees plus 1*/
    height = (lh > rh ? lh : rh) + 1;

    /* If difference between heights of left and right
    subtrees is more than 2 then this node is not balanced
    so return 0 */
    if (abs(lh - rh) >= 2)
        return 0;

    /* If this node is balanced and left and right subtrees
    are balanced then return true */
    else
        return l && r;
} //time complexity O(N)
int main()
{
    BinaryTree *node1 = new BinaryTree(1);
    BinaryTree *node2 = new BinaryTree(2);
    BinaryTree *node3 = new BinaryTree(3);
    BinaryTree *node4 = new BinaryTree(4);
    BinaryTree *node5 = new BinaryTree(5);
    BinaryTree *node6 = new BinaryTree(6);
    BinaryTree *node7 = new BinaryTree(7);
    BinaryTree *node8 = new BinaryTree(8);
    BinaryTree *node9 = new BinaryTree(9);
    BinaryTree *node10 = new BinaryTree(10);
    BinaryTree *node11 = new BinaryTree(11);
    BinaryTree *node12 = new BinaryTree(12);
    BinaryTree *node13 = new BinaryTree(13);

    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->right = node6;
    node4->right = node7;
    node5->right = node8;
    node6->right = node9;
    node7->left = node12;
    node12->right = node11;
    node12->left = node10;
    node10->left = node13;

    return 0;
}