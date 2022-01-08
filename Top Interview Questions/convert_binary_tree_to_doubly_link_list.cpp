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
void level_order_traversal(BinaryTree *root)
{
    if (!root)
        return;
    queue<BinaryTree *> queue;
    vector<int> res;
    queue.push(root);
    BinaryTree *node;
    while (!queue.empty())
    {
        node = queue.front();
        queue.pop();
        cout << node->data << ' ';
        if (node->left)
            queue.push(node->left);
        if (node->right)
            queue.push(node->right);
    }
    cout << endl;
}
/*
Algorithm:

Traverse the tree in inorder fashion.
While visiting each node, keep track of DLL’s head and tail pointers, insert each visited node to the end of DLL using tail pointer.
Return head of the list.
*/
void convertBinaryTreeToDLL(BinaryTree *root, BinaryTree **head, BinaryTree **tail)
{
    if (root == NULL)
        return;
    convertBinaryTreeToDLL(root->left, head, tail);
    if (*head == NULL)
        *head = root;
    root->left = *tail;
    if (*tail != NULL)
        (*tail)->right = root;
    *tail = root;
    convertBinaryTreeToDLL(root->right, head, tail);
}

// The main function that first calls convertBinaryTreeToDLL
BinaryTree *convertBinaryTreeToDLL(BinaryTree *root)
{
    // Base case
    if (root == NULL)
        return root;
    BinaryTree *head = NULL;
    BinaryTree *tail = NULL;
    convertBinaryTreeToDLL(root, &head, &tail);
    return head;
}

int main()
{
    BinaryTree *node1 = new BinaryTree(1);
    BinaryTree *node2 = new BinaryTree(2);
    BinaryTree *node3 = new BinaryTree(3);
    BinaryTree *node4 = new BinaryTree(4);
    BinaryTree *node5 = new BinaryTree(5);
    BinaryTree *node6 = new BinaryTree(6);
    BinaryTree *node7 = new BinaryTree(7);
    BinaryTree *node8 = new BinaryTree(8);
    BinaryTree *node9 = new BinaryTree(9);
    BinaryTree *node10 = new BinaryTree(10);
    BinaryTree *node11 = new BinaryTree(11);
    BinaryTree *node12 = new BinaryTree(12);
    BinaryTree *node13 = new BinaryTree(13);

    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node4->right = node7;
    node5->right = node8;
    node6->right = node9;
    node7->left = node12;
    node12->right = node11;
    node12->left = node10;
    node10->left = node13;
    level_order_traversal(node1);
    BinaryTree *newNode = convertBinaryTreeToDLL(node1);
    while (newNode)
    {
        cout << newNode->data << ' ';
        newNode = newNode->right;
    }
    return 0;
}