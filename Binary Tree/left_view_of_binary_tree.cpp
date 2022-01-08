#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
// recursion
void leftViewUtil(struct Node *root,int level, int *max_level)
{
    // Base Case
    if (root == NULL)
        return;

    // If this is the first Node of its level
    if (*max_level < level)
    {
        cout << root->data << " ";
        *max_level = level;
    }

    // Recur for left subtree first,
    // then right subtree
    leftViewUtil(root->left, level + 1, max_level);
    leftViewUtil(root->right, level + 1, max_level);
}

// A wrapper over leftViewUtil()
void leftViewRecursive(struct Node *root)
{
    int max_level = 0;
    leftViewUtil(root, 1, &max_level);
}
vector<int> leftView(Node *root)
{
    if (!root)
        return {};
    vector<int> res = {root->data};
    queue<Node *> q;
    bool isStart = false;
    q.push(root);
    q.push(NULL);
    Node *temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (!temp)
        {
            if (!q.empty())
            {
                isStart = true;
                q.push(NULL);
            }
            else
                break;
        }
        else
        {
            if (isStart)
            {
                res.push_back(temp->data);
                isStart = false;
            }
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
    return res;
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
    Node *node11 = new Node(11);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->right = node9;
    node5->right = node6;
    node6->left = node7;
    node6->right = node8;
    node9->left = node10;
    node9->right = node11;

    auto res = leftView(node1);
    for (auto i : res)
        cout << i << ' ';
    cout << endl;
    return 0;
}