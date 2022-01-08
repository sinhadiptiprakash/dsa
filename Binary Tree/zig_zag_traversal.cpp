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
// using level order traversal
vector<int> zigzag_traversal(BinaryTree *root)
{
    if (!root)
        return {};
    vector<int> res, level;
    queue<BinaryTree *> q;
    BinaryTree *temp;
    bool flag = true;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (!temp)
        {
            if (flag)
            {
                for (int i : level)
                    res.push_back(i);
            }
            else
            {
                for (int i = level.size() - 1; i >= 0; i--)
                    res.push_back(level[i]);
            }
            flag = !flag;
            level.clear();
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            level.push_back(temp->data);
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
    // node7->left = node12;
    // node12->right = node11;
    // node12->left = node10;
    // node10->left = node13;

    vector<int> res = zigzag_traversal(node1);
    for (int i : res)
        cout << i << ' ';
    return 0;
}