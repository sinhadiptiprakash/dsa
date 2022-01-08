#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void insert_at_beginning(ListNode **head, int data)
{
    ListNode *temp = new ListNode(data);
    temp->next = *head;
    *head = temp;
}
// the position here is for 0 based indexing
void insert(ListNode **head, int data, int position)
{
    if (position == 1)
    {
        insert_at_beginning(head, data);
        return;
    }
    ListNode *newNode = new ListNode(data);
    int count = 0;
    ListNode *curent = *head;
    ListNode *before;
    while (curent && count < position)
    {
        before = curent;
        curent = curent->next;
        count++;
    }
    before->next = newNode;
    newNode->next = curent;
}
void print_list(ListNode *head)
{
    while (head)
    {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << endl;
}
// using floyd cycle finding algorithm get the starting point first
void remove_loop(ListNode *head)
{
    ListNode *slow_pointer = head, *fast_pointer = head;
    bool contains_loop = false;
    // first detect wheather the linked list contains a loop or cycle in it
    while (slow_pointer && fast_pointer && fast_pointer->next)
    {
        slow_pointer = slow_pointer->next;
        fast_pointer = fast_pointer->next->next;
        if (slow_pointer == fast_pointer)
        {
            contains_loop = true;
            break;
        }
    }
    // if the linked list contains a loop
    if (contains_loop)
    {
        // if the linked list contains a cycle we initialize slow pointer to again head
        //and at this point we increament both slow and fast pointer by one until they point the same node
        slow_pointer = head;
        ListNode *before;
        while (slow_pointer != fast_pointer)
        {
            before = slow_pointer;
            slow_pointer = slow_pointer->next;
            fast_pointer = fast_pointer->next;
        }
        // now slow and fast pointer is pointing the starting node of the loop
        // before is pointing to the node just before the starting node of the loop
        // so first of all we disconnect the link between main list and the loop
        before->next = NULL;
        ListNode *loop_start = slow_pointer->next, *temp;
        // now we cut the cycle to form a linear linked list
        slow_pointer->next = NULL;
        // now loop start is the start of that linear linked list that was made from the loop
        // now we are deleting all the nodes of this linear linked list
        while (loop_start)
        {
            temp = loop_start;
            loop_start = loop_start->next;
            temp->next = NULL;
            delete (temp);
        }
    }
}

int main()
{
    ListNode *head = new ListNode(10);
    ListNode **temp = &head;
    insert_at_beginning(temp, 11);
    insert_at_beginning(temp, 12);
    insert_at_beginning(temp, 13);
    ListNode *middle = head;
    insert_at_beginning(temp, 14);
    insert_at_beginning(temp, 15);
    insert_at_beginning(temp, 16);

    // for making the linked list cyclic
    ListNode *temp2 = head;
    while (temp2->next)
    {
        temp2 = temp2->next;
    }
    // connecting the last node to the middle node to form a cycle
    temp2->next = middle;
    remove_loop(head);
    print_list(head);
    return 0;
}