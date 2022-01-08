#include <bits/stdc++.h>
using namespace std;

//utility function to print contents of a vector from index i to it's end
void printVector(const vector<int> &v, int i)
{
    for (int j = i; j < v.size(); j++)
        cout << v[j] << " ";
    cout << endl;
}

// binary tree node
struct BinaryTree
{
    int data;
    BinaryTree *left, *right;
    BinaryTree(int x)
    {
        data = x;
        left = right = NULL;
    }
};

// This function prints all paths that have sum k
void printPaths(BinaryTree *root, vector<int> &path, int k)
{
    // empty node
    if (!root)
        return;

    // add current node to the path
    path.push_back(root->data);

    // check if there's any k sum path that terminates at this node
    // Traverse the entire path as there can be negative elements too
    int sum = 0;
    // we are starting from end because we want to know which node we get the sum from
    for (int j = path.size() - 1; j >= 0; j--)
    {
        sum += path[j];

        // If path sum is k, print the path
        if (sum == k)
            // j is the starting node or root of this path
            printVector(path, j);
    }
    // check if there's any k sum path in the left sub-tree.
    printPaths(root->left, path, k);
    // check if there's any k sum path in the right sub-tree.
    printPaths(root->right, path, k);

    // Remove the current element from the path
    path.pop_back();
}

// A wrapper over printPaths()
void printKPaths(BinaryTree *root, int k)
{
    vector<int> path;
    printPaths(root, path, k);
}

int main()
{
    BinaryTree *root = new BinaryTree(1);
    root->left = new BinaryTree(3);
    root->left->left = new BinaryTree(2);
    root->left->right = new BinaryTree(1);
    root->left->right->left = new BinaryTree(1);
    root->right = new BinaryTree(-1);
    root->right->left = new BinaryTree(4);
    root->right->left->left = new BinaryTree(1);
    root->right->left->right = new BinaryTree(2);
    root->right->right = new BinaryTree(5);
    root->right->right->right = new BinaryTree(2);

    int k = 5;
    printKPaths(root, k);

    return 0;
}