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
vector<int> reverse_level_order(BinaryTree *root)
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
        // we first push node's right in the queue
        // because at the end of the level order traversal we will reverse the result vector
        // so if we don't push right first then the order of elements in each level gonna change
        if (node->right)
            queue.push(node->right);
        if (node->left)
            queue.push(node->left);
    }
    // revese the res
    reverse(res.begin(), res.end());
    return res;
}
int main()
{
    return 0;
}