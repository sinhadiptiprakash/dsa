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
void inorder_traversal(BinaryTree *root)
{
    if (!root)
        return;
    inorder_traversal(root->left);
    cout << root->data << ' ';
    inorder_traversal(root->right);
}
// iterative using stack
void inorder_traversal_iterative(BinaryTree *root)
{
    if (!root)
        return;
    stack<BinaryTree *> stack;
    while (1)
    {
        while (root)
        {
            stack.push(root);
            root = root->left;
        }
        if (stack.empty())
            break;
        root = stack.top();
        stack.pop();
        cout << root->data<<' ';
        root = root->right;
    }
} //time complexity O(N) space O(N)
int main()
{
    return 0;
}