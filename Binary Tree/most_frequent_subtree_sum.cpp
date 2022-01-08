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
    int preOrder(TreeNode *root, unordered_map<int, int> &mp)
    {
        if (!root)
            return 0;
        int curentSum = root->val + preOrder(root->left, mp) + preOrder(root->right, mp);
        mp[curentSum]++;
        return curentSum;
    }
    vector<int> findFrequentTreeSum(TreeNode *root)
    {
        unordered_map<int, int> mp;
        preOrder(root, mp);
        vector<int> res;
        int maxFreq = 0;
        for (auto iter : mp)
            maxFreq = max(maxFreq, iter.second);
        for (auto iter : mp)
        {
            if (iter.second == maxFreq)
                res.push_back(iter.first);
        }
        return res;
    }
};
int main()
{
    return 0;
}