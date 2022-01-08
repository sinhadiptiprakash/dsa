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
    unordered_map<string, int> mp;
    vector<TreeNode *> v;
    string serialize(TreeNode *root)
    {
        if (root == NULL)
            return "#";
        string s = "";
        s += to_string(root->val) + ',' + serialize(root->left) + ',' + serialize(root->right);
        mp[s]++;
        if (mp[s] == 2)
            v.push_back(root);
        return s;
    }

    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        serialize(root);
        return v;
    }
};
int main()
{
    return 0;
}