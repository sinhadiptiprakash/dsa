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
void delete_at_beginning(ListNode **head)
{
    ListNode *temp = *head;
    *head = temp->next;
    delete temp;
}
// position here is 0 based indexing
void delete_node(ListNode **head, int position)
{
    if (position == 1)
    {
        delete_at_beginning(head);
        return;
    }
    int count = 0;
    ListNode *curent = *head;
    ListNode *before;
    while (curent && count < position)
    {
        count++;
        before = curent;
        curent = curent->next;
    }
    ListNode *temp = curent;
    before->next = curent->next;
    delete temp;
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
//recursive approach
ListNode *reverse_list_in_groups(ListNode *head, int k)
{
    //base case
    if (!head)
        return NULL;
    ListNode *curent, *prev = NULL, *next;
    int count = 0;
    curent = head;
    // reverse the first sublist of k size
    while (curent && count < k)
    {
        next = curent->next;
        curent->next = prev;
        prev = curent;
        curent = next;
        count++;
    }
    // now next points the k+1 the node and head stores the starting node of this k-length sublist
    // so head->next should points to the starting of the next reversed k-length sublist
    if (next)
        head->next = reverse_list_in_groups(next, k);
    // as prev points to the starting of the reversed list
    return prev;
}
ListNode *reverse_list_in_groups_iterative(ListNode *head, int k)
{
    ListNode *curent, *curent_start, *prev = NULL, *next, *new_head = NULL, *dummy_node;
    int count = 0;
    curent = head;
    //here we have created a dummy node actually this dummy node indicates
    // the last node in the last reversed k-length sublist
    // as initially we dont have any reversed list so it will point to null initially
    dummy_node = new ListNode(0);
    while (curent)
    {
        //first of all we reverse the k-length sublist by just simple iterative appraoch of reversing a linked list
        prev = NULL;
        // we store the curent_start because this curent_start will be the next dummy node
        // because this is the start of the curent sublist and after reversal it will be at the end of this k-length sublist
        curent_start = curent;
        count = 0;
        while (curent && count < k)
        {
            next = curent->next;
            curent->next = prev;
            prev = curent;
            curent = next;
            count++;
        }
        //now we have reversed the curent sublist of length k started from the curent_start
        // but after reversing the the starting node of this sublist will be prev

        // if we are storing prev for the first time then this will be our new_head of the whole reversed linked list
        if (!new_head)
            new_head = prev;

        // now previously revered list's last node's next will be starting of the curent reversed sublist of size k
        dummy_node->next = prev;
        // and dummy node will be the starting node of this sublist of size k before reversing
        dummy_node = curent_start;
        // curent should point to the next to reverse the next k-size sublist
        curent = next;
    }
    // this step is very important
    // at the end the last node of the whole reversed list should point to NULL
    // as dummy_node is the last node of the whole list
    dummy_node->next = NULL;
    return new_head;
}

// for leetcode submission that is if the last segment to be reversed is less than k size, it should be unaltered
// then this apporach
ListNode *reverseKGroup(ListNode *head, int k)
{
    int i;
    bool flag = false;
    ListNode *curent, *prev, *start, *next, *newHead = NULL;
    ListNode *dummy = new ListNode(0);
    curent = head;
    while (curent)
    {
        prev = NULL;
        start = curent;
        i = 0;
        while (i < k && curent)
        {
            next = curent->next;
            curent->next = prev;
            prev = curent;
            curent = next;
            i++;
        }
        if (i < k)
        {
            flag = true;
            break;
        }
        dummy->next = prev;
        if (!newHead)
            newHead = prev;
        dummy = start;
        start = next;
    }
    if (flag)
    {
        curent = prev;
        prev = NULL;
        while (curent)
        {
            next = curent->next;
            curent->next = prev;
            prev = curent;
            curent = next;
        }
        dummy->next = prev;
    }
    return newHead;
}
int main()
{
    ListNode *head = new ListNode(10);
    ListNode **temp = &head;
    insert_at_beginning(temp, 11);
    insert_at_beginning(temp, 12);
    insert_at_beginning(temp, 13);
    insert_at_beginning(temp, 14);
    insert_at_beginning(temp, 15);
    insert_at_beginning(temp, 16);
    // as temp stores the address of the head we can write temp as &head
    insert(&head, 100, 6);
    print_list(head);
    ListNode *rest = reverse_list_in_groups_iterative(head, 5);
    print_list(rest);
    return 0;
}