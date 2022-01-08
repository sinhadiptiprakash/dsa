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
int toSumTree(BinaryTree *Node)
{
    // Base case
    if (Node == NULL)
        return 0;
    // Store the old value
    int old_val = Node->data;
    // Recursively call for left and
    // right subtrees and store the sum as
    // old value of this node
    Node->data = toSumTree(Node->left) + toSumTree(Node->right);
    // Return the sum of values of nodes
    // in left and right subtrees and
    // old_value of this node
    return Node->data + old_val;
}
void convertToSumTree(BinaryTree *root)
{
    toSumTree(root);
}
int main()
{
    BinaryTree *node1 = new BinaryTree(10);
    BinaryTree *node2 = new BinaryTree(-2);
    BinaryTree *node3 = new BinaryTree(6);
    BinaryTree *node4 = new BinaryTree(8);
    BinaryTree *node5 = new BinaryTree(-4);
    BinaryTree *node6 = new BinaryTree(7);
    BinaryTree *node7 = new BinaryTree(5);

    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;

    level_order_traversal(node1);
    convertToSumTree(node1);
    level_order_traversal(node1);
    return 0;
}