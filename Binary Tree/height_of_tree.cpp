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
//recursive
int height(BinaryTree *root)
{
    if (!root)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}
//using level order traversal
int height(BinaryTree *root)
{
    if (!root)
        return 0;
    queue<BinaryTree *> q;
    q.push(root);
    q.push(NULL); //NUll denotes end of the level
    int level = 0;
    while (!q.empty())
    {
        BinaryTree *node = q.front();
        q.pop();
        if (!node)
        {
            level++;
            if (!q.empty())
            {
                q.push(NULL);
            }
            else
                break;
        }
        else
        {
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }
    return level;
}
int main()
{
    return 0;
}