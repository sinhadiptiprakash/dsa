#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
// Function to insert a node at the beginning
// of the Linked List
void push(Node **head_ref, int new_data)
{
    // allocate node
    Node *new_node = (Node *)malloc(sizeof(Node));

    // put in the data
    new_node->data = new_data;
    // link the old list off the new node
    new_node->next = (*head_ref);
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

void sortList(Node **head)
{
    int count[3] = {0, 0, 0}; // Initialize count of '0', '1' and '2' as 0
    Node *ptr = *head;

    /* count total number of '0', '1' and '2'
    * count[0] will store total number of '0's
    * count[1] will store total number of '1's
    * count[2] will store total number of '2's */
    while (ptr != NULL)
    {
        count[ptr->data] += 1;
        ptr = ptr->next;
    }

    int i = 0;
    ptr = *head;

    /* Let say count[0] = n1, count[1] = n2 and count[2] = n3
    * now start traversing list from head node,
    * 1) fill the list with 0, till n1 > 0
    * 2) fill the list with 1, till n2 > 0
    * 3) fill the list with 2, till n3 > 0 */
    while (ptr != NULL)
    {
        if (count[i] == 0)
            ++i;
        else
        {
            ptr->data = i;
            --count[i];
            ptr = ptr->next;
        }
    }
}
int main()
{
    Node *head = NULL;
    push(&head, 0);
    push(&head, 2);
    push(&head, 1);
    push(&head, 2);
    push(&head, 2);
    push(&head, 1);
    push(&head, 2);
    push(&head, 2);
    push(&head, 0);
    push(&head, 2);
    push(&head, 2);
    push(&head, 1);
    printList(head);
    sortList(&head);
    printList(head);
    return 0;
}