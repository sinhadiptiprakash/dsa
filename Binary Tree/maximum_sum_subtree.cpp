#include <bits/stdc++.h>
using namespace std;

// Structure of a tree node.
struct BinaryTree
{
    int data;
    BinaryTree *left, *right;
};

// Function to create new tree node.
BinaryTree *newNode(int data)
{
    BinaryTree *temp = new BinaryTree;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Helper function to find largest
// subtree sum recursively.
int maxSubtreeSum(BinaryTree *root, int &ans)
{
    // If current node is null then
    // return 0 to parent node.
    if (root == NULL)
        return 0;

    // Subtree sum rooted at current node.
    int currSum = root->data +
                  maxSubtreeSum(root->left, ans) + maxSubtreeSum(root->right, ans);

    // Update answer if current subtree
    // sum is greater than answer so far.
    ans = max(ans, currSum);

    // Return current subtree sum to
    // its parent node.
    return currSum;
}

// Function to find largest subtree sum.
int findLargestSubtreeSum(BinaryTree *root)
{
    // If tree does not exist,
    // then answer is 0.
    if (root == NULL)
        return 0;

    // Variable to store maximum subtree sum.
    int ans = INT_MIN;

    // Call to recursive function to
    // find maximum subtree sum.
    maxSubtreeSum(root, ans);

    return ans;
}

// Driver function
int main()
{
    /*
               1
             /   \
            /     \
          -2       3
          / \     /  \
         /   \   /    \
        4     5 -6     2
    */

    BinaryTree *root = newNode(1);
    root->left = newNode(-2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(2);

    cout << findLargestSubtreeSum(root) << endl;
    return 0;
}