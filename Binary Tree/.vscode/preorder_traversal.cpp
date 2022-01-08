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
void preorder_traversal(BinaryTree *root)
{
    if (!root)
        return;
    cout << root->data << ' ';
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}
// iterative using stack
void preorder_traversal_iterative(BinaryTree *root)
{
    if (!root)
        return;
    stack<BinaryTree *> stack;
    while (1)
    {
        while (root)
        {
            cout << root->data << ' ';
            stack.push(root);
            root = root->left;
        }
        if (stack.empty())
            break;
        root = stack.top();
        stack.pop();
        root = root->right;
    }
} //time complexity O(N) space O(N)
int main()
{
    return 0;
}