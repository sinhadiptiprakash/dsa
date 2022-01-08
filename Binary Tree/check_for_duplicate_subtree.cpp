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
//serialize the binary tree through preOrder and store serialized strings for every node in Unordered map
string preorder(BinaryTree *root, unordered_map<string, int> &mp)
{
    string s;
    if (!root)
    {
        s += "$";
        return s;
    }
    s += root->data;
    s += preorder(root->left, mp);
    s += preorder(root->right, mp);
    mp[s]++;
    return s;
}
bool dupSub(BinaryTree *root)
{
    unordered_map<string, int> mp;
    preorder(root, mp);
    for (auto i : mp)
        if (i.second >= 2 && i.first.length() > 3)
            return true;
    return false;
}
int main()
{
    return 0;
}