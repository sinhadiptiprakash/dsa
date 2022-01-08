#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};
struct comp
{
    bool operator()(const pair<Node *, int> &a, const pair<Node *, int> &b)
    {
        return a.first->data > b.first->data;
    }
};
Node *merge_k_soted_lists(Node *arr[], int k)
{
    priority_queue<pair<Node *, int>, vector<pair<Node *, int>>, comp> min_heap;
    for (int i = 0; i < k; i++)
    {
        if (arr[i])
        {
            min_heap.push({arr[i], i});
            arr[i] = arr[i]->next;
        }
    }
    Node *dummy = new Node(0);
    Node *res = dummy;
    while (!min_heap.empty())
    {
        auto temp = min_heap.top();
        min_heap.pop();
        dummy->next = temp.first;
        dummy = dummy->next;
        if (arr[temp.second])
        {
            min_heap.push({arr[temp.second], temp.second});
            arr[temp.second] = arr[temp.second]->next;
        }
    }
    return res->next;
} //time coplexity O(N*log(K)) and space complexity O(K)
//where N is the maximum no. of nodes in an individual list and k is the no. of lists
int main()
{
    return 0;
}