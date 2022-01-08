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
void push(Node **head, int d)
{
    Node *new_node = new Node(d);
    new_node->next = *head;
    *head = new_node;
}
void print(Node *head)
{
    while (head)
    {
        cout << head->data << ' ';
        head = head->next;
    }
    cout << endl;
}
Node *nth_node_from_last(Node *head, int n)
{
    Node *ptr1 = head, *ptr2 = head;
    int i;
    for (i = 0; ptr1 && i < n; i++)
        ptr1 = ptr1->next;
    if (i < n)
        return NULL;
    while (ptr1)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return ptr2;
}
int main()
{
    Node *head = new Node(3);
    push(&head, 2);
    push(&head, 6);
    push(&head, 5);
    push(&head, 11);
    push(&head, 10);
    push(&head, 15);
    push(&head, 12);
    push(&head, 17);
    push(&head, 19);
    print(head);
    Node *res = nth_node_from_last(head, 0);
    if (res)
        cout << res->data << endl;
    else
        cout << "no data" << endl;
    return 0;
}