//Approach:
// Return a pair for each node in the binary tree such that the first of the pair indicates maximum sum
// when the data of a node is included and the second indicates maximum sum when the data of a particular node
//  is not included.

// C++ program to find maximum sum in Binary Tree
// such that no two nodes are adjacent.
#include <iostream>
using namespace std;

class BinaryTree
{
public:
    int data;
    BinaryTree *left, *right;
    BinaryTree(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

pair<int, int> maxSumHelper(BinaryTree *root)
{
    if (!root)
    {
        return {0, 0};
    }
    pair<int, int> leftSum = maxSumHelper(root->left);
    pair<int, int> rightSum = maxSumHelper(root->right);
    pair<int, int> sum;

    // This node is included (Left and right children
    // are not included)
    sum.first = leftSum.second + rightSum.second + root->data;

    // This node is excluded (Either left or right
    // child is included)
    sum.second = max(leftSum.first, leftSum.second) +
                 max(rightSum.first, rightSum.second);

    return sum;
}

int maxSum(BinaryTree *root)
{
    pair<int, int> res = maxSumHelper(root);
    return max(res.first, res.second);
}

int main()
{
    BinaryTree *root = new BinaryTree(10);
    root->left = new BinaryTree(1);
    root->left->left = new BinaryTree(2);
    root->left->left->left = new BinaryTree(1);
    root->left->right = new BinaryTree(3);
    root->left->right->left = new BinaryTree(4);
    root->left->right->right = new BinaryTree(5);
    cout << maxSum(root);
    return 0;
}