#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};
class Solution
{
public:
    int diameter_of_tree(Node *root, int &height)
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
        // Get the heights of left and right subtrees in lh and
        // rh And store the returned values in ldiameter and ldiameter
        ldiameter = diameter_of_tree(root->left, lh);
        rdiameter = diameter_of_tree(root->right, rh);
        // Height of current node is max of heights of left and right subtrees plus 1
        height = max(lh, rh) + 1;
        return max(lh + rh + 1, max(ldiameter, rdiameter));
    }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node *root)
    {
        int height = 0;
        return diameter_of_tree(root, height);
    }
};
int main()
{
    return 0;
}