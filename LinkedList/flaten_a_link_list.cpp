#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *bottom;
    Node(int d)
    {
        data = d;
        next = NULL;
        bottom = NULL;
    }
};
// An utility function to merge two sorted linked lists
Node *merge(Node *a, Node *b)
{
    // if first linked list is empty then second is the answer
    if (!a)
        return b;
    // if second linked list is empty then first is the result
    if (!b)
        return a;
    // compare the data members of the two linked lists and put the larger one in the result
    Node *result;
    if (a->data < b->data)
    {
        result = a;
        result->bottom = merge(a->bottom, b);
    }
    else
    {
        result = b;
        result->bottom = merge(a, b->bottom);
    }
    result->next = NULL;
    return result;
}

Node *flatten(Node *root)
{
    // Base Cases
    if (root == NULL || root->next == NULL)
        return root;
    // recur for list on next
    root->next = flatten(root->next);
    // now merge
    root = merge(root, root->next);
    // return the root
    // it will be in turn merged with its left
    return root;
}
/* Utility function to insert a node at beginning of the
       linked list */
Node *push(Node *head_ref, int data)
{
    /* 1 & 2: Allocate the Node & Put in the data*/
    Node *new_node = new Node(data);
    /* 3-> Make next of new Node as head */
    new_node->bottom = head_ref;
    /* 4-> Move the head to point to new Node */
    head_ref = new_node;
    /*5-> return to link it back */
    return head_ref;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->bottom;
    }
    cout << endl;
}
int main()
{
    return 0;
}