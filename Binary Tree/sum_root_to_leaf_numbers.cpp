#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int v){
        val = v;
        left = NULL;
        right = NULL;
    }
};
void sum(TreeNode *root, long long int num, int &res)
{
    if (!root)
        return;
    if (!root->left && !root->right)
    {
        num = num * 10 + root->val;
        res += num;
        return;
    }
    sum(root->left, num * 10 + root->val, res);
    sum(root->right, num * 10 + root->val, res);
}
int sumNumbers(TreeNode *root)
{
    int res = 0;
    sum(root, 0, res);
    return res;
}
int main()
{
    return 0;
}