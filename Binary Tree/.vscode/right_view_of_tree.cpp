#include <bits/stdc++.h>
using namespace std;
struct BinaryTree
{
    int data;
    BinaryTree *left;
    BinaryTree *right;
    BinaryTree(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
//using recursion
vector<int> rightSideView(BinaryTree *root)
{
    vector<int> ans;
    int maxLevel = -1;
    dfs(root, ans, 0, maxLevel);
    return ans;
}

void dfs(BinaryTree *root, vector<int> &ans, int level, int &maxLevel)
{
    if (root == nullptr)
        return;
    if (maxLevel < level)
    {
        ans.push_back(root->data);
        maxLevel = level;
    }
    dfs(root->right, ans, level + 1, maxLevel);
    dfs(root->left, ans, level + 1, maxLevel);
}

//using level order traversal; we only pich the first element of each level. *****my code
vector<int> leftViewOfBinaryTree(BinaryTree *root)
{
    if (!root)
        return {};
    vector<int> res;
    queue<BinaryTree *> q;
    BinaryTree *previousLast;
    q.push(root);
    // NULL indicates the ending of the curent level
    q.push(NULL);
    BinaryTree *temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (!temp)
        {
            //if the curent level ends we make isStart=true i.e. we will pick the first element of the next level
            if (!q.empty())
            {
                res.push_back(previousLast->data);
                q.push(NULL);
            }
            else
                break;
        }
        else
        {
            previousLast = temp;
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
    res.push_back(previousLast->data);
    return res;
}
int main()
{
    return 0;
}