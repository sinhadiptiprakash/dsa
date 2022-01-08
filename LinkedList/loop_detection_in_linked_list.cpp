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
// using floyd cycle finding algorithm
bool contains_loop(ListNode *head)
{
    ListNode *slow_pointer = head, *fast_pointer = head;

    while (slow_pointer && fast_pointer && fast_pointer->next)
    {
        slow_pointer = slow_pointer->next;
        fast_pointer = fast_pointer->next->next;
        if (slow_pointer == fast_pointer)
        {
            return 1;
        }
    }
    return 0;
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
    // as temp stores the address of the head we can write temp as &head
    insert(&head, 100, 6);
    //making the linked list cyclic
    // while (head->next)
    // {
    //     head = head->next;
    // }
    head->next = middle;
    //print_list(head);
    cout << contains_loop(head) << endl;
    return 0;
}