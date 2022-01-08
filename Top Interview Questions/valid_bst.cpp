#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int v)
    {
        val = v;
        left = NULL;
        right = NULL;
    }
};
long long int max(long long int a, long long int b)
{
    return (a > b ? a : b);
}
long long int min(long long int a, long long int b)
{
    return (a < b ? a : b);
}
// setting the limit/range
bool isBST(TreeNode *root, long min, long max)
{
    if (root == nullptr)
        return true;
    return (root->val > min && root->val < max && isBST(root->left, min, root->val) && isBST(root->right, root->val, max));
}
bool isValidBST(TreeNode *root)
{
    return isBST(root, LONG_MIN, LONG_MAX);
}

// utilizing the fact that root->val is always greater than the max in the left subtree and smaller than the min at the right subtree
bool isBST(TreeNode *root, long long int &minVal, long long int &maxVal)
{
    if (!root)
    {
        minVal = 1e12;
        maxVal = -1e12;
        return true;
    }
    long long int leftMin, leftMax;
    long long int rightMin, rightMax;
    bool left = isBST(root->left, leftMin, leftMax);
    bool right = isBST(root->right, rightMin, rightMax);
    bool res = false;
    if (left && right)
    {
        if (root->val > leftMax && root->val < rightMin)
            res = true;
    }
    minVal = min(leftMin, min(root->val, rightMin));
    maxVal = max(leftMax, max(root->val, rightMax));
    return res;
}
bool isValidBST(TreeNode *root)
{
    long long int minVal, maxVal;
    return isBST(root, minVal, maxVal);
}
int main()
{
    TreeNode *root = new TreeNode(32);
    TreeNode *node1 = new TreeNode(26);
    TreeNode *node2 = new TreeNode(47);
    TreeNode *node3 = new TreeNode(19);
    TreeNode *node4 = new TreeNode(56);
    TreeNode *node5 = new TreeNode(27);
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node2->right = node4;
    node3->right = node5;
    bool res = isValidBST(root);
    cout << (res ? "BST" : "NOT A BST") << endl;
    return 0;
}