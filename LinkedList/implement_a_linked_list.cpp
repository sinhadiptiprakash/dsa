#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
int list_length(ListNode *head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return count;
}
bool is_empty(ListNode *head)
{
    return head == NULL;
}
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
void delete_list(ListNode **head)
{
    ListNode *temp;
    while ((*head))
    {
        temp = (*head);
        temp->next = NULL;
        (*head) = (*head)->next;
        delete (temp);
    }
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
    delete_at_beginning(temp);
    print_list(head);
    delete_node(&head, 4);
    print_list(head);
    return 0;
}