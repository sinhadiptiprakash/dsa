#include <bits/stdc++.h>
using namespace std;
// my approach

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class BSTIterator
{
public:
    TreeNode *head;
    TreeNode *tail;
    void flatten(TreeNode *root)
    {
        if (!root)
            return;
        flatten(root->left);
        if (!head)
            head = root;
        root->left = tail;
        if (tail)
            tail->right = root;
        tail = root;
        flatten(root->right);
    }
    BSTIterator(TreeNode *root)
    {
        head = NULL, tail = NULL;
        flatten(root);
    }

    int next()
    {
        int data = head->val;
        head = head->right;
        return data;
    }

    bool hasNext()
    {
        if (head == tail->right)
            return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
int main()
{
    return 0;
}