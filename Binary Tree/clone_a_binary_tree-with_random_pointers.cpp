#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right, *random;
    Node(int d)
    {
        data = d;
        left = right = random = NULL;
    }
};
// below function copies the tree wholly without the copies of random pointers
Node *getCloneWithoutRandom(Node *root, unordered_map<Node *, Node *> &mp)
{
    if (!root)
        return NULL;
    mp[root] = new Node(root->data);
    mp[root]->left = getCloneWithoutRandom(root->left, mp);
    mp[root]->right = getCloneWithoutRandom(root->right, mp);
    return mp[root];
}
void fixRandoms(Node *root, unordered_map<Node *, Node *> &mp)
{
    if (!root)
        return;
    mp[root]->random = mp[root->random];
    fixRandoms(root->left, mp);
    fixRandoms(root->right, mp);
}
Node *cloneTree(Node *root)
{
    if (!root)
        return NULL;
    // key is original node value is corresponding copied node
    unordered_map<Node *, Node *> mp;
    Node *clonedRoot = getCloneWithoutRandom(root, mp);
    fixRandoms(root, mp);
    return clonedRoot;
}
int main()
{
    return 0;
}