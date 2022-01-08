#include <bits/stdc++.h>
using namespace std;
struct BSTNode
{
    int data;
    BSTNode *left;
    BSTNode *right;
    BSTNode(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
void insert(BSTNode **root, int d)
{
    if (*root == NULL)
    {
        *root = new BSTNode(d);
    }
    else
    {
        if (d < (*root)->data)
        {
            insert(&(*root)->left, d);
        }
        else
        {
            insert(&(*root)->right, d);
        }
    }
}
void inOrder(BSTNode *root, unordered_set<int> &in)
{
    if (!root)
        return;
    inOrder(root->left, in);
    in.insert(root->data);
    inOrder(root->right, in);
}
int countPairs(BSTNode *root1, BSTNode *root2, int x)
{
    unordered_set<int> in1, in2;
    inOrder(root1, in1);
    inOrder(root2, in2);
    int count = 0;
    for (auto it : in1)
    {
        if (in2.find(x - it) != in2.end())
            count++;
    }
    return count;
} //time complexity O(N) space complexity O(N)
int main()
{
    int n, d;
    cin >> n;
    BSTNode *root = NULL;
    while (n--)
    {
        cin >> d;
        insert(&root, d);
    }

    return 0;
}