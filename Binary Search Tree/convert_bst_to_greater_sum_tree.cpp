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
    int getSum(TreeNode *root)
    {
        if (!root)
            return 0;
        return root->val + getSum(root->left) + getSum(root->right);
    }
    void convert(TreeNode *root, int &prevNum, int &sum)
    {
        if (!root)
            return;
        convert(root->left, prevNum, sum);
        int temp = root->val;
        sum -= prevNum;
        root->val = sum;
        prevNum = temp;
        convert(root->right, prevNum, sum);
    }
    TreeNode *convertBST(TreeNode *root)
    {
        int sum = 0, prevNum = 0;
        sum = getSum(root);
        convert(root, prevNum, sum);
        return root;
    }
};
int main()
{
    return 0;
}