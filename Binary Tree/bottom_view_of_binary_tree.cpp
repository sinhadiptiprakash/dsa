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
vector<int> level_order_traversal(BinaryTree *root)
{
    if (!root)
        return {};
    queue<BinaryTree *> queue;
    vector<int> res;
    queue.push(root);
    BinaryTree *node;
    while (!queue.empty())
    {
        node = queue.front();
        queue.pop();
        res.push_back(node->data);
        if (node->left)
            queue.push(node->left);
        if (node->right)
            queue.push(node->right);
    }
    return res;
}
/*
A node x is there in output if x is the bottommost node at its horizontal distance. 
Horizontal distance of left child of a node x is equal to horizontal distance of x minus 1, 
and that of right child is horizontal distance of x plus 1. 
as we want bottom most node i.e. the farthest node from the root node we always update the distance:node in hash map
otherwise just store the distance:node in hash
*/
vector<int> bottomViewOfBinaryTree(BinaryTree *root)
{
    vector<int> res;
    if (root == NULL)
        return res;
    // hash stores horizontal distance and its corresponding bottom most node in sorted orer
    // i.e. the farthest node from root
    map<int, int> hash;
    // queue stores node and its corresponding horizontal distance from the root
    queue<pair<BinaryTree *, int>> q;
    // as root's horizontal distance is zero we first push rooot with 0 in queue
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<BinaryTree *, int> p = q.front();
        q.pop();
        BinaryTree *temp = p.first;
        int h_distance = p.second;
        // we store/update the distance and its corresponding node
        hash[h_distance] = temp->data;
        // if temp left exists we push temp->left with temp's horizontal distance-1
        if (temp->left)
            q.push(make_pair(temp->left, h_distance - 1));
        // if temp right exists we push temp->right with temp's horizontal distance+1
        if (temp->right)
            q.push(make_pair(temp->right, h_distance + 1));
    }
    // storing the result from the sorted hash
    for (auto i : hash)
    {
        res.push_back(i.second);
    }
    return res;
} //time complexity O(N) space complexity O(N)
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
    node3->right = node6;
    node4->right = node7;
    node5->right = node8;
    node6->right = node9;
    node7->left = node12;
    node12->right = node11;
    node12->left = node10;
    node10->left = node13;

    auto res = bottomViewOfBinaryTree(node1);
    for (int i : res)
        cout << i << ' ';
    return 0;
}