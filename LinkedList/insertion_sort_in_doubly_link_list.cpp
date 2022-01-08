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
/*
Naive Approach: Sort the given doubly linked list using the insertion sort technique. 
While inserting each element in the sorted part of the list, 
there will be at most k swaps to place the element 
to its correct position since it is at most k steps away from its correct position.
*/
void insertion_sort(Node **head)
{
    Node *curent = (*head)->next, *start;
    while (curent != NULL)
    {
        Node *next = curent->next;
        if (curent->data < curent->prev->data)
        {
            Node *temp = curent->prev;
            temp->next = curent->next;
            if (curent->next)
                curent->next->prev = temp;
            start = *head;
            while (start && start->data < curent->data)
            {
                start = start->next;
            }
            if (!start->prev)
            {
                start->prev = curent;
                curent->next = start;
                curent->prev = NULL;
                *head = curent;
            }
            else
            {
                start->prev->next = curent;
                curent->prev = start->prev;
                start->prev = curent;
                curent->next = start;
            }
        }
        curent = next;
    }
} //time complexity O(N*N) and space complexity O(1)

// Driver program to test above
int main()
{
    Node *head = NULL;
    push(&head, 8);
    push(&head, 8);
    push(&head, 8);
    push(&head, 8);
    push(&head, 8);
    push(&head, 56);
    push(&head, 12);
    push(&head, 2);
    push(&head, 2);
    push(&head, 6);
    push(&head, 3);
    push(&head, 3);
    printList(head);
    insertion_sort(&head);
    printList(head);
    return 0;
}