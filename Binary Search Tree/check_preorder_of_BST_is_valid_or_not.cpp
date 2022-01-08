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
//using stack approach is similar to finding the next greater element in an arrya for every element
//Approach:
/*
1) Create an empty stack.
2) Initialize root as INT_MIN.
3) Do following for every element pre[i]
     a) If pre[i] is smaller than current root, return false.
     b) Keep removing elements from stack while pre[i] is greater
        then stack top. Make the last removed item as new root (to
        be compared next).
        At this point, pre[i] is greater than the removed root
        (That is why if we see a smaller element in step a), we 
        return false)
     c) push pre[i] to stack (All elements in stack are in decreasing
        order)  
*/
bool isValidPreOrderOfBST(int pre[], int n)
{
    stack<int> stack;
    // Initialize current root as minimum possible value
    int root = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        // If we find a node who is on right side and smaller than root, return false
        if (pre[i] < root)
            return false;
        // If pre[i] is in right subtree of stack top, Keep removing items smaller than pre[i]
        // and make the last removed item as new root.
        while (!stack.empty() && pre[i] > stack.top())
        {
            root = stack.top();
            stack.pop();
        }
        // At this point either stack is empty or pre[i] is smaller than root, push pre[i]
        stack.push(pre[i]);
    }
    return true;
} //time complexity O(N) space complexity O(N)
//we can do it without using stack
/*
The idea is to use the similar concept of “Building a BST using narrowing bound algorithm”.
 We will recursively visit all nodes, but we will not build the nodes. 
 In the end, if the complete array is not traversed, then that means that array can not represent the preorder
  traversal of any binary search tree.
  
*/
// We are actually not building the tree
void buildBST_helper(int &preIndex, int n, int pre[],int min, int max)
{
    if (preIndex >= n)
        return;

    if (min <= pre[preIndex] && pre[preIndex] <= max)
    {
        // build node
        int rootData = pre[preIndex];
        preIndex++;

        // build left subtree
        buildBST_helper(preIndex, n, pre, min, rootData);

        // build right subtree
        buildBST_helper(preIndex, n, pre, rootData, max);
    }
    // else
    // return NULL;
}

bool canRepresentBST(int arr[], int N)
{
    // code here
    int min = INT_MIN, max = INT_MAX;
    int preIndex = 0;

    buildBST_helper(preIndex, N, arr, min, max);

    return preIndex == N;
}
int main()
{
    int pre1[] = {40, 30, 35, 80, 100};
    int n1 = sizeof(pre1) / sizeof(int);
    cout << isValidPreOrderOfBST(pre1, n1) << endl;

    int pre2[] = {40, 30, 35, 20, 80, 100};
    int n2 = sizeof(pre2) / sizeof(int);
    cout << isValidPreOrderOfBST(pre2, n2);
    return 0;
}