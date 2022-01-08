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
class Solution
{
public:
    vector<TreeNode *> v;

    void solve(TreeNode *root)
    {
        if (root == NULL)
            return;
        solve(root->left);
        v.push_back(root);
        solve(root->right);
    }
    TreeNode *fun(int st, int en)
    {
        if (st > en)
            return NULL;
        int mid = st + (en - st) / 2;

        TreeNode *root = v[mid];
        root->left = fun(st, mid - 1);
        root->right = fun(mid + 1, en);

        return root;
    }
    TreeNode *balanceBST(TreeNode *root)
    {
        solve(root);
        int n = v.size();
        TreeNode *ans = fun(0, n - 1);
        return ans;
    }
};
int main()
{
    return 0;
}