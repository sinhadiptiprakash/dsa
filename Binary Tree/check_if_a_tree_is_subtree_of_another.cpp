#include <bits/stdc++.h>
using namespace std;
struct BinaryTree
{
    int data;
    BinaryTree *left;
    BinaryTree *right;
};
//recursive way
bool isIdentical(BinaryTree *r1, BinaryTree *r2)
{
    if (!r1 && !r2)
        return true;
    if (!r1 || !r2)
        return false;
    return (r1->data == r2->data) &&
           isIdentical(r1->left, r2->left) &&
           isIdentical(r1->right, r2->right);
}

bool isSubtree(BinaryTree *root, BinaryTree *subRoot)
{
    if (!subRoot)
        return true;
    if (!root)
        return false;
    if (isIdentical(root, subRoot))
        return true;
    return (isSubtree(root->left, subRoot) ||
            isSubtree(root->right, subRoot));
}

// optimized way
void inOrder(BinaryTree *root, vector<int> &in)
{
    if (!root)
    {
        in.push_back(INT_MAX);
        return;
    }
    inOrder(root->left, in);
    in.push_back(root->data);
    inOrder(root->right, in);
}
void preOrder(BinaryTree *root, vector<int> &pre)
{
    if (!root)
    {
        pre.push_back(INT_MAX);
        return;
    }
    pre.push_back(root->data);
    preOrder(root->left, pre);
    preOrder(root->right, pre);
}
bool isSubarray(vector<int> main, vector<int> sub)
{
    int n = main.size();
    int m = sub.size();
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (main[i] == sub[j])
        {
            i++, j++;
            if (j >= m)
                return true;
        }
        else
        {
            //start from the next element of the previous start
            i = i - j + 1;
            j = 0;
        }
    }
    return false;
}
bool isSubTree(BinaryTree *main, BinaryTree *sub)
{
    vector<int> pre_main, pre_sub, in_main, in_sub;
    inOrder(main, in_main);
    inOrder(sub, in_sub);
    preOrder(main, pre_main);
    preOrder(sub, pre_sub);
    return isSubarray(pre_main, pre_sub) && isSubarray(in_main, in_sub);
}
int main()
{

    return 0;
}