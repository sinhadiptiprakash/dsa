#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    void dfs(TreeNode *root, int targetSum, vector<vector<int>> &res, vector<int> temp, int sum)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
        {

            if (sum + root->val == targetSum)
            {
                temp.push_back(root->val);
                res.push_back(temp);
            }
            return;
        }
        temp.push_back(root->val);
        dfs(root->left, targetSum, res, temp, sum + root->val);
        dfs(root->right, targetSum, res, temp, sum + root->val);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> res;
        dfs(root, targetSum, res, {}, 0);
        return res;
    }
};