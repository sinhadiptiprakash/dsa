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
bool areLeavesAtSameLevel(BinaryTree *root)
{
    if (!root)
        return true;
    queue<BinaryTree *> q;
    int leafLevel = -1, level = 0;
    q.push(root);
    q.push(NULL);
    BinaryTree *temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (!temp && !q.empty())
        {
            q.push(NULL);
            level++;
        }
        else
        {
            if (!temp->left && !temp->right)
            {
                if (leafLevel == -1 || leafLevel == level)
                    leafLevel = level;
                else
                    return false;
            }
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
    return true;
}
int main()
{

    return 0;
}