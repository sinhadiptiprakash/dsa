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
void inOrder(BSTNode *root)
{
    if (!root)
        return;
    inOrder(root->left);
    cout << root->data << ' ';
    inOrder(root->right);
}
// method 1
// as we know first element in PreOrder traversal is the root so we make first element as root
// and find the next Greater element of root, root's left subtree would within root to this next greater element
// and right subtree would be from the next greater element to the end
// do above steps recursively
//below function finds the next greater element of a element at index preStart
int getNextGreater(int pre[], int preStart, int preEnd)
{
    int greater = preStart;
    for (int i = preStart + 1; i <= preEnd; i++)
    {
        if (pre[i] > pre[greater])
        {
            greater = i;
            break;
        }
    }
    return greater;
}
BSTNode *construct_BST_from_preOrder(int pre[], int preStart, int preEnd)
{
    if (preStart > preEnd)
        return NULL;
    BSTNode *root = new BSTNode(pre[preStart]);
    if (preStart == preEnd)
        return root;
    int greater = getNextGreater(pre, preStart, preEnd);
    root->left = construct_BST_from_preOrder(pre, preStart + 1, greater - 1);
    root->right = construct_BST_from_preOrder(pre, greater, preEnd);
    return root;
} //time complexity O(N^2) because getNextGreater is taking O(N) time
// we can optimize the above approach by optimizing the getNextGreater to O(N) using a stack
// that would cost O(N) time as well as O(N) space fro the stack

// another approach by just inserting the elements in BST
BSTNode *constructBSTFromPreOrder(int pre[], int n)
{
    if (n == 0)
        return NULL;
    BSTNode *root = new BSTNode(pre[0]);
    for (int i = 1; i < n; i++)
    {
        insert(&root, pre[i]);
    }
    return root;
} // time complexity O(N^2)

// below method runs in O(N) time
BSTNode *build(int preorder[], int &pos, int n, int min, int max)
{
    if (pos >= n)
        return NULL;
    int val = preorder[pos];
    if (val > max || val < min)
        return NULL;

    BSTNode *node = new BSTNode(val);
    pos++;
    node->left = build(preorder, pos, n, min, val - 1);
    node->right = build(preorder, pos, n, val + 1, max);
    return node;
}

BSTNode *bstFromPreorder(int preorder[], int n)
{
    if (n == 0)
        return NULL;
    int pos = 0;
    return build(preorder, pos, n, INT_MIN, INT_MAX);
}
int main()
{
    int n;
    cin >> n;
    int pre[n];
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }
    BSTNode *root = bstFromPreorder(pre, n);
    inOrder(root);
    return 0;
}