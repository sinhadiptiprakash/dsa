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
vector<int> level_order_traversal(BinaryTree *root)
{
    if (!root)
        return {};
    queue<BinaryTree *> queue;
    vector<int> res;
    queue.push(root);
    BinaryTree *node;
    while (!queue.empty())
    {
        node = queue.front();
        queue.pop();
        res.push_back(node->data);
        if (node->left)
            queue.push(node->left);
        if (node->right)
            queue.push(node->right);
    }
    return res;
}
int main()
{
    return 0;
}