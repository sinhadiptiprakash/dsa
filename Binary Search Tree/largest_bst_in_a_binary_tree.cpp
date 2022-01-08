#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
struct Info
{
    bool isBST;
    int min;
    int max;
    int size;
};
Info largestBSTInBinaryTree(Node *root, int &largestBST)
{
    if (!root)
        return {true, INT32_MAX, INT32_MIN, 0};
    Info left, right, ret;

    left = largestBSTInBinaryTree(root->left, largestBST);
    right = largestBSTInBinaryTree(root->right, largestBST);

    ret.isBST = (left.max < root->data && right.min > root->data) && left.isBST && right.isBST; //condition to check if curr node and its subtree is a BST
    ret.min = min(left.min, root->data);
    ret.max = max(right.max, root->data);
    ret.size = 1 + left.size + right.size;

    if (ret.isBST && ret.size > largestBST) //if curr node subtree is a BST and greater in size than maxBST till now
        largestBST = ret.size; //store max size BST
    return ret;
}
int largestBst(Node *root)
{
    int largestBST = 0;
    largestBSTInBinaryTree(root, largestBST);
    return largestBST;
}
int main()
{
    return 0;
}