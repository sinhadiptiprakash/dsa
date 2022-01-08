// C++ program to find largest BST in a
// Binary Tree.
#include <bits/stdc++.h>
using namespace std;
struct BSTNode
{
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
    BSTNode(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
// to store the information of each and every node
struct Info
{
    bool isBST;
    int min;
    int max;
    int size;
};
Info largestBSTInBinaryTree(BSTNode *root, int &largestBST)
{
    if (!root)
    {
        return {true, INT32_MAX, INT32_MIN, 0};
    }
    Info left, right, ret;

    left = largestBSTInBinaryTree(root->left, largestBST);
    right = largestBSTInBinaryTree(root->right, largestBST);

    ret.isBST = (left.max < root->data && right.min > root->data) && left.isBST && right.isBST; //condition to check if curr node and its subtree is a BST
    ret.min = min(left.min, root->data);
    ret.max = max(right.max, root->data);
    ret.size = 1 + left.size + right.size;

    if (ret.isBST && ret.size > largestBST) //if curr node subtree is a BST and greater in size than maxBST till now
    {
        largestBST = ret.size; //store max size BST
    }
    return ret;
}

int largestBSTInBST(BSTNode *root)
{
    int largestBST = 0;
    largestBSTInBinaryTree(root, largestBST);
    return largestBST;
}
int main()
{
    struct BSTNode *root = new BSTNode(60);
    root->left = new BSTNode(65);
    root->right = new BSTNode(70);
    root->left->left = new BSTNode(50);
    cout << largestBSTInBST(root) << endl;
    return 0;
}