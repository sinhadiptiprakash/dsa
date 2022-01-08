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
void level_order_traversal(BinaryTree *root)
{
    if (!root)
        return;
    queue<BinaryTree *> queue;
    queue.push(root);
    BinaryTree *node;
    while (!queue.empty())
    {
        node = queue.front();
        queue.pop();
        cout << node->data << ' ';
        if (node->left)
            queue.push(node->left);
        if (node->right)
            queue.push(node->right);
    }
    cout << endl;
}
void postOrder(BinaryTree *root)
{
    if (!root)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << ' ';
}

int findIndex(int *inorder, int start, int end, int element)
{
    int i = start;
    for (i; i <= end; i++)
    {
        if (inorder[i] == element)
            break;
    }
    return i;
}
BinaryTree *buildTree(int *preorder, int *inorder, int inOrderStart, int inOrderEnd, int &preOrderIndex)
{
    if (inOrderStart > inOrderEnd)
        return NULL;
    BinaryTree *root = new BinaryTree(preorder[preOrderIndex]);
    int inorderdex = findIndex(inorder, inOrderStart, inOrderEnd, preorder[preOrderIndex]);
    preOrderIndex++;
    root->left = buildTree(preorder, inorder, inOrderStart, inorderdex - 1, preOrderIndex);
    root->right = buildTree(preorder, inorder, inorderdex + 1, inOrderEnd, preOrderIndex);
    return root;
}
BinaryTree *buildTree(int in[], int pre[], int n)
{
    int preOrderIndex = 0;
    return buildTree(pre, in, 0, n - 1, preOrderIndex);
}
int main()
{
    int in[] = {3, 1, 4, 0, 5, 2};
    int pre[] = {0, 1, 3, 4, 2, 5};
    int n = sizeof(in) / sizeof(int);
    BinaryTree *root = buildTree(in, pre, n);
    level_order_traversal(root);
    return 0;
}