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
//recursive approach
void leftViewRecursive(BinaryTree *root, int level, int &maxLevel)
{
    //base case
    if (!root)
        return;
    // If this is the first Node of its level
    if (level > maxLevel)
    {
        cout << root->data << ' ';
        maxLevel = level;
    }
    // Recur for left subtree first, then right subtree
    leftViewRecursive(root->left, level + 1, maxLevel);
    leftViewRecursive(root->right, level + 1, maxLevel);
}
void leftView(BinaryTree *root)
{
    int max_level = 0;
    leftViewRecursive(root, 1, max_level);
}
//using level order traversal; we only pich the first element of each level. *****my code
vector<int> leftViewOfBinaryTree(BinaryTree *root)
{
    if (!root)
        return {};
    vector<int> res = {root->data};
    queue<BinaryTree *> q;
    bool isStart = false;
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
                isStart = true;
                q.push(NULL);
            }
            else
                break;
        }
        else
        {
            if (isStart)
            {
                // after picking the first element of this level we will make isstart false to not take other elements of this level
                res.push_back(temp->data);
                isStart = false;
            }
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
    return res;
}
int main()
{
    return 0;
}