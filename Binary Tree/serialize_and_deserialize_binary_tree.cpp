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
// using PreOrder Traversal
class PreOrder
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {

        string s;
        if (!root)
            return "N";
        string leftResult = serialize(root->left);
        string rightResult = serialize(root->right);
        string currentResult = to_string(root->val);
        return currentResult + "," + leftResult + "," + rightResult;
    }

    // Decodes your encoded data to tree.

    TreeNode *helper(stringstream &s)
    {
        string str;
        getline(s, str, ','); // getline is going to take data until ',' is met and will store data in the str
        if (str == "N")
        {
            return NULL;
        }
        TreeNode *root = new TreeNode(stoi(str));
        root->left = helper(s);
        root->right = helper(s);
        return root;
    }

    TreeNode *deserialize(string data)
    {

        stringstream X(data);
        return helper(X);
    }
};
//using Level Order Traversal
class LeveOrder
{
public:
    string serialize(TreeNode *root)
    {
        if (!root)
            return "";
        string s = "";
        queue<TreeNode *> q;
        q.push(root);
        while (q.size())
        {
            root = q.front();
            q.pop();
            if (root == NULL)
                s += "#,";
            else
                s += (to_string(root->val) + ',');
            if (root)
            {
                q.push(root->left);
                q.push(root->right);
            }
        }
        return s;
    }
    TreeNode *deserialize(string data)
    {
        if (data.size() == 0)
            return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode *> q;
        q.push(root);
        while (q.size())
        {
            TreeNode *node = q.front();
            q.pop();
            getline(s, str, ',');
            if (str == "#")
                node->left = NULL;
            else
            {
                TreeNode *leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }
            getline(s, str, ',');
            if (str == "#")
                node->right = NULL;
            else
            {
                TreeNode *rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};
int main()
{
    return 0;
}