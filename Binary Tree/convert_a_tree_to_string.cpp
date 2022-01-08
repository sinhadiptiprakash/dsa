#include <bits/stdc++.h>
using namespace std;
struct BinaryTree
{
    int data;
    BinaryTree *left;
    BinaryTree *right;
};
class Solution
{
public:
    string tree2str(BinaryTree *cur)
    {
        if (!cur)
            return "";

        // Leaf
        if (!cur->left && !cur->right)
            return to_string(cur->data);

        // Not leaf
        string l = "";
        if (!cur->left)
            l = "()";
        else
        {
            l = "(" + tree2str(cur->left) + ")";
        }

        string r = "";
        if (cur->right)
            r = "(" + tree2str(cur->right) + ")";

        return to_string(cur->data) + l + r;
    }
};