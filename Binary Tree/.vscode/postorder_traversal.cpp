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
void postorder_traversal(BinaryTree *root)
{
    if (!root)
        return;
    postorder_traversal(root->left);
    cout << root->data << ' ';
    postorder_traversal(root->right);
}
// iterative using stack
void postorder_traversal_iterative(BinaryTree *root)
{
    if (!root)
        return;
    stack<BinaryTree *> stack;
    BinaryTree *previous = NULL;
    do
    {
        while (root)
        {
            stack.push(root);
            root = root->left;
        }
        while (!root && !stack.empty())
        {
            root = stack.top();
            if (!root->right || previous == root->right)
            {
                cout << root->data << ' ';
                stack.pop();
                previous = root;
                root = NULL;
            }
            else
                root = root->right;
        }
    } while (!stack.empty());
} //time complexity O(N) space O(N)
int main()
{
    return 0;
}