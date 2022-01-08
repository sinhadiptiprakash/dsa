#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
//iterative
void inOrder(Node *root)
{
    if (!root)
        return;
    stack<Node *> stack;
    while (1)
    {
        while (root)
        {
            stack.push(root);
            root = root->left;
        }
        if (stack.empty())
            break;
        root = stack.top();
        stack.pop();
        cout << root->data << ' ';
        root = root->right;
    }
}
int main()
{
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);
    Node *node6 = new Node(6);
    Node *node7 = new Node(7);
    Node *node8 = new Node(8);
    Node *node9 = new Node(9);
    Node *node10 = new Node(10);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;
    node5->left = node8;
    node5->right = node9;
    node9->right = node10;
    inOrder(node1);
    cout << endl;
    return 0;
}