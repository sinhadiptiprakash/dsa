#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};

vector<int> rightView(Node *root)
{
    if (!root)
        return {};
    vector<int> res;
    queue<Node *> q;
    Node *previousLast;
    q.push(root);
    // NULL indicates the ending of the curent level
    q.push(NULL);
    Node *temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (!temp)
        {
            //if the curent level ends we make isStart=true i.e. we will pick the first element of the next level
            if (!q.empty())
            {
                res.push_back(previousLast->data);
                q.push(NULL);
            }
            else
                break;
        }
        else
        {
            previousLast = temp;
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
    res.push_back(previousLast->data);
    return res;
}

int main()
{
    return 0;
}