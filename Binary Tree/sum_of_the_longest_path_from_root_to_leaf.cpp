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
void preOrder(BinaryTree *root, int &maxLen, int &maxSum, int len, int sum)
{
    if (!root)
    {
        if (len >= maxLen)
        {
            maxLen = len;
            if (sum > maxSum)
                maxSum = sum;
        }
        return;
    }
    len++;
    maxLen = len > maxLen ? len : maxLen;
    preOrder(root->left, maxLen, maxSum, len, sum + root->data);
    preOrder(root->right, maxLen, maxSum, len, sum + root->data);
}
int sumOfLongRootToLeafPath(BinaryTree *root)
{
    int maxSum = INT_MIN, maxLen = INT_MIN;
    preOrder(root, maxLen, maxSum, 0, 0);
    return maxSum;
}
int main()
{

    return 0;
}