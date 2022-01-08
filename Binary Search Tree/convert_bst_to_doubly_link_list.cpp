// A C++ program for in-place
// conversion of Binary Tree to DLL
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data,
and left and right pointers */
class node
{
public:
    int data;
    node *left;
    node *right;
};

/* This is the core function to convert
Tree to list.*/
void bintree2listUtil(node *root, node **head, node **tail)
{
    if (root == NULL)
        return;

    node *left = root->left;
    node *right = root->right;

    bintree2listUtil(root->left, head, tail);

    if (*head == NULL)
    {
        *head = root;
    }

    root->left = *tail;

    if (*tail != NULL)
    {
        (*tail)->right = root;
    }

    *tail = root;

    bintree2listUtil(root->right, head, tail);
}

// The main function that first calls
// bintree2listUtil()
node *bintree2list(node *root)
{
    // Base case
    if (root == NULL)
        return root;

    node *head = NULL;
    node *tail = NULL;

    bintree2listUtil(root, &head, &tail);

    return head;
}

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
node *newNode(int data)
{
    node *new_node = new node();
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return (new_node);
}

/* Function to print nodes in a given doubly linked list */
void printList(node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->right;
    }
}
int main()
{
    // Let us create the tree shown in above diagram
    node *root = newNode(10);
    root->left = newNode(12);
    root->right = newNode(15);
    root->left->left = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);

    // Convert to DLL
    node *head = bintree2list(root);

    // Print the converted list
    printList(head);

    return 0;
}
