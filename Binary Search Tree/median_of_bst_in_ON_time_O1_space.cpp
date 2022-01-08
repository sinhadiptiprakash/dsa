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
// below inOrder traversal counts total no. of nodes in a bst
void countNodes(BSTNode *root, int &count)
{
    if (!root)
        return;
    countNodes(root->left, count);
    count++;
    countNodes(root->right, count);
}
//below inOrder traversal get the median
void inOrder(BSTNode *root, int n, int &k, int &prev, double &ans)
{
    if (!root)
        return;
    inOrder(root->left, n, k, prev, ans);
    k--;
    if (k == 0)
    {
        if (n % 2 == 0)
        {
            ans = (prev + root->data) / 2.0;
        }
        else
            ans = prev;
        return;
    }
    prev = root->data;
    inOrder(root->right, n, k, prev, ans);
}
double medianOfBST(BSTNode *root)
{
    int n = 0;
    countNodes(root, n);
    int k = (n + 1) / 2 + 1;
    int prev;
    double ans;
    inOrder(root, n, k, prev, ans);
    return ans;
}
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
    cout << medianOfBST(root) << endl;
    return 0;
}