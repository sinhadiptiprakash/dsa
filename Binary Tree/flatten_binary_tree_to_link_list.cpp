#include <bits/stdc++.h>
using namespace std;
struct BinaryTree
{
    int val;
    BinaryTree *left;
    BinaryTree *right;
    BinaryTree(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};
class Solution
{
    BinaryTree *temp = NULL;
    void recursive(BinaryTree *node)
    {
        if (!node)
            return;
        recursive(node->right);
        recursive(node->left);
        node->right = temp;
        node->left = NULL;
        temp = node;
    }
    // using morris-traversal
    void flatten(BinaryTree *root)
    {
        BinaryTree *cur = root;
        while (cur != NULL)
        {
            if (cur->left != NULL)
            {
                BinaryTree *prev = cur->left;
                while (prev->right)
                {
                    prev = prev->right;
                }
                prev->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
            }
            cur = cur->right;
        }
        return;
    }

public:
    void flatten(BinaryTree *root)
    {
        if (!root)
            return;
        recursive(root);
        // iterative(root);
    }
};