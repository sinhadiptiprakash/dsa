#include <bits/stdc++.h>
using namespace std;
struct BinaryTree
{
    char data;
    BinaryTree *left;
    BinaryTree *right;
    BinaryTree(char d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
//using level order traversal
BinaryTree *deSerialize(string levelOrder)
{
    if (levelOrder.size() == 0)
        return NULL;
    if (levelOrder[0] == 'N')
        return NULL;
    queue<pair<BinaryTree *, int>> q;
    BinaryTree *temp;
    int index;
    int n = levelOrder.size();
    BinaryTree *root = new BinaryTree(levelOrder[0]);
    q.push({root, 0});
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        temp = p.first;
        index = p.second;
        int leftChildIndex = 2 * index + 1;
        int rightChildIndex = 2 * index + 2;
        if (leftChildIndex < n && levelOrder[leftChildIndex] != 'N')
        {
            BinaryTree *leftNode = new BinaryTree(levelOrder[leftChildIndex]);
            temp->left = leftNode;
            q.push({temp->left, leftChildIndex});
        }
        if (rightChildIndex < n && levelOrder[leftChildIndex] != 'N')
        {
            BinaryTree *rightNode = new BinaryTree(levelOrder[rightChildIndex]);
            temp->right = rightNode;
            q.push({temp->right, rightChildIndex});
        }
    }
    return root;
} //time complexity O(N)
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
void inOrder(BinaryTree *root)
{
    if (!root)
        return;
    inOrder(root->left);
    cout << root->data << ' ';
    inOrder(root->right);
}
int main()
{
    string levelOrder;
    cin >> levelOrder;
    BinaryTree *root = deSerialize(levelOrder);
    inOrder(root);
    return 0;
}