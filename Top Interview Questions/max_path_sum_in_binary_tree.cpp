#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
//helper function
int maxPathSum(Node *root, int &res)
{
    if (!root)
        return 0;
    int l = maxPathSum(root->left, res);
    int r = maxPathSum(root->right, res);
    int singleSum = max(max(l, r) + root->data, root->data);
    int max_top = max(singleSum, l + r + root->data);
    res = max(res, max_top);
    return singleSum;
}
//main function
int maximumPathSum(Node *root)
{
    int res = INT_MIN;
    maxPathSum(root, res);
    return res;
}
int main()
{
    return 0;
}