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
/*
The diameter of a tree T is the largest of the following quantities:
    the diameter of T’s left subtree.
    the diameter of T’s right subtree.
    the longest path between leaves that goes through the root of T 
    (this can be computed from the heights of the subtrees of T)
*/
int diameter_of_tree(BinaryTree *root, int &height)
{
    // lh --> Height of left subtree
    // rh --> Height of right subtree
    int lh = 0, rh = 0;
    // ldiameter  --> diameter of left subtree
    // rdiameter  --> Diameter of right subtree
    int ldiameter = 0, rdiameter = 0;
    if (root == NULL)
    {
        height = 0;
        return 0; // diameter is also 0
    }
    // Get the heights of left and right subtrees in lh and rh
    // And store the returned values in ldiameter and ldiameter
    ldiameter = diameter_of_tree(root->left, lh);
    rdiameter = diameter_of_tree(root->right, rh);
    // Height of current node is max of heights of left and right subtrees plus 1
    height = max(lh, rh) + 1;
    return max(lh + rh + 1, max(ldiameter, rdiameter));
} //time complexity O(N) space complexity O(N) for recursive overhead
int diameterOfTree(BinaryTree *root)
{
    int height = 0;
    return diameter_of_tree(root, height);
}
int main()
{
    return 0;
}