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
void inOrder(BSTNode *root)
{
    if (!root)
        return;
    inOrder(root->left);
    cout << root->data << ' ';
    inOrder(root->right);
}
//using stack
BSTNode *constructBSTFromPreorder(int pre[], int n)
{
    stack<BSTNode *> stack;
    BSTNode *root = new BSTNode(pre[0]);
    stack.push(root);
    BSTNode *temp;
    for (int i = 1; i < n; i++)
    {
        temp = NULL;

        /* Keep on popping while the next value is greater than
        stack's top value. */
        while (!stack.empty() && pre[i] > stack.top()->data)
        {
            temp = stack.top();
            stack.pop();
        }
        // Make this greater value as the right child
        // and push it to the stack
        if (temp != NULL)
        {
            temp->right = new BSTNode(pre[i]);
            stack.push(temp->right);
        }
        // If the next value is less than the stack's top
        // value, make this value as the left child of the
        // stack's top node. Push the new node to stack
        else
        {
            stack.top()->left = new BSTNode(pre[i]);
            stack.push(stack.top()->left);
        }
    }

    return root;
}
// recursive approach
// below function will be required to get the pivot index
int findIndex(int element, int pre[], int low, int high)
{
    int index = -1;
    for (int i = low; i <= high; i++)
    {
        if (pre[i] > element)
        {
            index = i;
            break;
        }
    }
    return index;
}
// we can also minimize the above searching for index of the next greater element using stack by just using next greater element concept
BSTNode *buildTree(int pre[], int low, int high)
{
    if (low > high)
        return NULL;
    BSTNode *root = new BSTNode(pre[low]);
    int midIndex = findIndex(pre[low], pre, low + 1, high);
    if (midIndex != -1)
    {
        root->left = buildTree(pre, low + 1, midIndex - 1);
        root->right = buildTree(pre, midIndex, high);
    }
    return root;
}
int main()
{
    int pre[] = {10, 5, 1, 7, 40, 50};
    int n = sizeof(pre) / sizeof(int);
    BSTNode *root = buildTree(pre, 0, n - 1);
    inOrder(root);
    return 0;
}