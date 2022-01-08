#include <bits/stdc++.h>
using namespace std;
// declaration of Binary tree node
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int d) : data(d), left(NULL), right(NULL){};
};
//using dfs and stack
stack<Node *> dfs(Node *root, int node, stack<Node *> st)
{
    if (!root)
        return st;
    st.push(root);
    if (root->data == node)
        return st;
    auto temp = dfs(root->left, node, st);
    if (!temp.empty() && temp.top()->data == node)
        return temp;
    return dfs(root->right, node, st);
}
Node *kthAncestor(Node *root, int node, int k)
{
    stack<Node *> st;
    stack<Node *> path = dfs(root, node, st);
    int count = 0;
    while (!path.empty() && count < k)
    {
        path.pop();
        count++;
    }
    if (path.empty())
        return NULL;
    return path.top();
}
// another approach using dfs
Node *kthAncestorDFS(Node *root, int node, int &k, Node *temp)
{
    // Base case
    if (!root)
        return NULL;
    if (root->data == node ||
        (temp = kthAncestorDFS(root->left, node, k, temp)) ||
        (temp = kthAncestorDFS(root->right, node, k, temp)))
    {
        if (k > 0)
            k--;
        else if (k == 0)
        {
            // print the kth ancestor
            cout << "Kth ancestor is: " << root->data;
            // return NULL to stop further backtracking
            return NULL;
        }
        // return current node to previous call
        return root;
    }
    return NULL;
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

    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node5->left = node6;
    node5->right = node7;
    Node *temp;
    int k = 2;
    auto res = kthAncestorDFS(node1, 6, k, temp);
    if (res)
        cout << res->data << endl;
    return 0;
}