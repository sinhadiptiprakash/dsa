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
// A simple function to print leaf nodes of a binary tree
void Leaves(BinaryTree *root, vector<int> &leaves)
{
    if (root == NULL)
        return;
    Leaves(root->left, leaves);
    // Print it if it is a leaf node
    if (!(root->left) && !(root->right))
        leaves.push_back(root->data);
    Leaves(root->right, leaves);
}

// A function to print all left boundary nodes, except a leaf node.
// Print the nodes in TOP DOWN manner
void BoundaryLeft(BinaryTree *root, vector<int> &leftBoundary)
{
    if (root == NULL)
        return;

    if (root->left)
    {
        // to ensure top down order, print the node
        // before calling itself for left subtree
        leftBoundary.push_back(root->data);
        BoundaryLeft(root->left, leftBoundary);
    }
    else if (root->right)
    {
        leftBoundary.push_back(root->data);
        BoundaryLeft(root->right, leftBoundary);
    }
    // do nothing if it is a leaf node, this way we avoid
    // duplicates in output
}

// A function to print all right boundary nodes, except a leaf node
// Print the nodes in BOTTOM UP manner
void BoundaryRight(BinaryTree *root, vector<int> &rightBoundary)
{
    if (root == NULL)
        return;

    if (root->right)
    {
        // to ensure bottom up order, first call for right
        // subtree, then print this node
        BoundaryRight(root->right, rightBoundary);
        rightBoundary.push_back(root->data);
    }
    else if (root->left)
    {
        BoundaryRight(root->left, rightBoundary);
        rightBoundary.push_back(root->data);
    }
    // do nothing if it is a leaf node, this way we avoid
    // duplicates in output
}

// A function to do boundary traversal of a given binary tree
vector<int> boundary_traversal(BinaryTree *root)
{
    if (root == NULL)
        return {};
    vector<int> result = {root->data};

    // get the left boundary in top-down manner. in leftBoundary
    BoundaryLeft(root->left, result);

    // get all leaf nodes
    Leaves(root->left, result);
    Leaves(root->right, result);

    // get the right boundary in bottom-up manner
    BoundaryRight(root->right, result);
    return result;
} //time complexity O(N) space complexity O(log(N))
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

    auto res = boundary_traversal(node1);
    for (int i : res)
        cout << i << ' ';
    return 0;
}