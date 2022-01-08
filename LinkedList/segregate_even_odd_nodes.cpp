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
Node *segregate_even_odd(Node *head)
{
    Node *last_even = new Node(0), *last_odd = new Node(0), *even = last_even, *odd = last_odd;
    while (head)
    {
        if (head->data & 1)
        {
            odd->next = head;
            odd = odd->next;
        }
        else
        {
            even->next = head;
            even = even->next;
        }
        head = head->next;
    }
    if (even)
        even->next = last_odd->next;
    if (odd)
        odd->next = NULL;
    return last_even->next;
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
    Node *res = segregate_even_odd(head);
    print(res);
    return 0;
}