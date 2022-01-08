#include <bits/stdc++.h>
using namespace std;
// a node of the doubly linked list
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
//function to push a new node with given data at the front of the Doubly link list
void push(Node **head_ref, int new_data)
{
    Node *new_node =
        (Node *)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = (*head_ref);
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
    (*head_ref) = new_node;
}
// function to insert a node at the beginging
// of the Doubly Linked List
void push(Node **head_ref, Node *new_node)
{
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
Node *reverse_in_groups(Node *head, int k)
{
    Node *current = head;
    Node *next = NULL;
    Node *newHead = NULL;
    int count = 0;
    // reversing the current group of k or less than k nodes
    // by adding them at the beginning of list 'newHead'
    while (current != NULL && count < k)
    {
        next = current->next;
        push(&newHead, current);
        current = next;
        count++;
    }
    // if next group exists then making the desired adjustments in the link
    if (next != NULL)
    {
        head->next = reverse_in_groups(next, k);
        head->next->prev = head;
    }
    // pointer to the new head of the reversed group
    return newHead;
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
    Node *res = reverse_in_groups(head, 3);
    printList(res);
    return 0;
}