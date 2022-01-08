#include <bits/stdc++.h>
using namespace std;
struct BSTNode
{
    int data;
    BSTNode *left;
    BSTNode *right;
    BSTNode(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
// below insert function inserts a data in bst and store the inOrder successor of it in inOrderSuccessor
void insert(BSTNode **root, int d, int &inOrderSuccessor)
{
    if (*root == NULL)
        *root = new BSTNode(d);
    else
    {
        if (d < (*root)->data)
        {
            inOrderSuccessor = (*root)->data;
            insert(&(*root)->left, d, inOrderSuccessor);
        }
        else
            insert(&(*root)->right, d, inOrderSuccessor);
    }
}

// MY APPROACHES
//using sorting
vector<int> replaceByLeastGreater(int a[], int n)
{
    vector<pair<int, int>> temp;
    for (int i = 0; i < n; i++)
    {
        temp.push_back({a[i], i});
    }
    sort(temp.begin(), temp.end());
    vector<int> res(n, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (temp[j].first > a[temp[i].second] && temp[j].second > temp[i].second)
            {
                res[temp[i].second] = temp[j].first;
                break;
            }
        }
    }
    return res;
} //worst case time complexity O(N^2) as we run a loop inside it but in average case or best case it would be O(Nlog(N)) space complexity O(N)
// we can do it better by using nextGreater element to find the next greater index of the curent element's index
vector<int> nextGreaterIndex(vector<pair<int, int>> &temp)
{
    int n = temp.size();
    vector<int> res(n, -1);
    stack<int> stack;
    for (int i = 0; i < n; i++)
    {
        if (stack.empty() || temp[i].second < stack.top())
            stack.push(temp[i].second);
        else
        {
            while (!stack.empty() && temp[i].second > stack.top())
            {
                res[stack.top()] = temp[i].second;
                stack.pop();
            }
            stack.push(temp[i].second);
        }
    }
    return res;
}
//now we will be optimize the above code of replacing the curent element with least greater element on its right
vector<int> replaceByLeastGreaterUsingStack(int a[], int n)
{
    vector<pair<int, int>> temp;
    for (int i = 0; i < n; i++)
    {
        temp.push_back({a[i], i});
    }
    sort(temp.begin(), temp.end());
    vector<int> indexes = nextGreaterIndex(temp);
    vector<int> res(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (indexes[temp[i].second] != -1)
            res[temp[i].second] = a[indexes[temp[i].second]];
    }
    return res;
} //time complexity O(N*log(N)) space complexity O(N)

// GFG APPROACH:
//another approach using BST
// Approach: we start inserting the elements from right side of the array
//and after inserting we replace it with its inOrder successor
//if not found any inOrder successor replace it with -1
vector<int> replaceByLeastGreaterUsingBST(int a[], int n)
{
    BSTNode *root = NULL;
    for (int i = n - 1; i >= 0; i--)
    {
        int inOrderSuccessor = -1;
        insert(&root, a[i], inOrderSuccessor);
        //now find inOrder successor for this node
        a[i] = inOrderSuccessor;
    }
    vector<int> res(n);
    for (int i = 0; i < n; i++)
        res[i] = a[i];
    return res;
} //time complexity O(Nlog(N)) and space complexity O(1);
int main()
{
    int a[] = {8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28};
    int n = sizeof(a) / sizeof(int);
    auto res = replaceByLeastGreaterUsingBST(a, n);
    for (int i : res)
        cout << i << ' ';
    cout << endl;
    return 0;
}