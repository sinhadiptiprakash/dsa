#include <bits/stdc++.h>
using namespace std;
// a node of the doubly linked list
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

// Function to insert a node at the beginning
// of the Doubly Linked List
void push(Node **head_ref, int new_data)
{
    // allocate node
    Node *new_node =
        (Node *)malloc(sizeof(Node));

    // put in the data
    new_node->data = new_data;

    // since we are adding at the beginning,
    // prev is always NULL
    new_node->prev = NULL;

    // link the old list off the new node
    new_node->next = (*head_ref);

    // change prev of head node to new node
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    // move the head to point to the new node
    (*head_ref) = new_node;
}

// Function to print nodes in a given doubly linked list
void printList(Node *head)
{
    // if list is empty
    if (head == NULL)
        cout << "Doubly Linked list empty";

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
void rotate_by_n(Node **head, int n)
{
    Node *temp = *head;
    for (int i = 0; i < n && (*head); i++)
    {
        (*head) = (*head)->next;
    }
    Node *curent = *head;
    (*head)->prev->next = NULL;
    while (curent->next)
    {
        curent = curent->next;
    }
    curent->next = temp;
    temp->prev = curent;
}
int main()
{
    Node *head = NULL;
    push(&head, 12);
    push(&head, 11);
    push(&head, 10);
    push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    printList(head);
    rotate_by_n(&head, 9);
    printList(head);
    return 0;
}