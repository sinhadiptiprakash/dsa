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
// keep track of the Last added leftmost element's horizontal distance as well as last added rightmost element's horizontal distance
// a node is included in result if its horizontal distance is less than last added leftmost element
// or its horizontal distance is greater than the last added rightmost element
// i.e. if it is outside the last level's domain then it will be visible from top
// horizontal distance of left child of node X= horizontal distance of X-1
// horizontal distance of right child of node X= horizontal distance of X+1
vector<int> topViewOfBinaryTree(BinaryTree *root)
{
    vector<int> res;
    queue<pair<BinaryTree *, int>> q;
    // lastLeft is last added leftmost element
    int lastLeft, lastRight;
    q.push({root, 0});
    pair<BinaryTree *, int> temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        // we handle hte special case of root element
        if (temp.first == root)
        {
            res.push_back(temp.first->data);
            lastLeft = 0, lastRight = 0;
            if (temp.first->left)
            {
                q.push({temp.first->left, -1});
            }
            if (temp.first->right)
            {
                q.push({temp.first->right, 1});
            }
        }
        else
        {
            // if horizontal distance of curent node is less than last added leftmost node we include it in result
            // as well as update the lastLeft
            if (temp.second < lastLeft)
            {
                lastLeft = temp.second;
                res.insert(res.begin(), temp.first->data);
            }
            if (temp.second > lastRight)
            {
                lastRight = temp.second;
                res.push_back(temp.first->data);
            }
            if (temp.first->left)
            {
                q.push({temp.first->left, temp.second - 1});
            }
            if (temp.first->right)
            {
                q.push({temp.first->right, temp.second + 1});
            }
        }
    }
    return res;
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
    node3->right = node6;
    node4->right = node7;
    node5->right = node8;
    node6->right = node9;
    node7->left = node12;
    node12->right = node11;
    node12->left = node10;
    node10->left = node13;

    auto res = topViewOfBinaryTree(node1);
    for (int i : res)
        cout << i << ' ';
    return 0;
}