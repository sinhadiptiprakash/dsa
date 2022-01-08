#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
};
//using heap
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    deque<TreeNode *> dq;
    dq.push_back(root);
    int i = 0;
    TreeNode *temp = new TreeNode();
    while (!dq.empty())
    {
        int s = dq.size();
        vector<int> ll;
        if (i % 2 == 0)
        {
            while (s--)
            {
                temp = dq.front();
                dq.pop_front();
                ll.push_back(temp->val);
                if (temp->left != NULL)
                    dq.push_back(temp->left);
                if (temp->right != NULL)
                    dq.push_back(temp->right);
            }
        }
        else
        {
            while (s--)
            {
                temp = dq.back();
                dq.pop_back();
                ll.push_back(temp->val);
                if (temp->right != NULL)
                    dq.push_front(temp->right);
                if (temp->left != NULL)
                    dq.push_front(temp->left);
            }
        }
        ans.push_back(ll);
        i++;
    }
    return ans;
}
int main()
{
    return 0;
}