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
bool isIsomorphic(BinaryTree *node1, BinaryTree *node2)
{
    if (!node1 && !node2)
        return true;
    if (!node1 || !node2)
        return false;
    if (node1->data != node2->data)
        return false;
    return ((isIsomorphic(node1->left, node2->left) && isIsomorphic(node1->right, node2->right)) ||
            (isIsomorphic(node1->left, node2->right) && isIsomorphic(node1->right, node2->left)));
}
int main()
{
    return 0;
}