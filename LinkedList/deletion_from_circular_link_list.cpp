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

void print_list(ListNode *head)
{
    while (head)
    {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << endl;
}
void delete_node(ListNode **head, int pos)
{
    ListNode *curent = *head;
    if (*head == NULL)
        return;
    if (pos <= 1)
    {
        while (curent->next != *head)
        {
            curent = curent->next;
        }
        curent->next = (*head)->next;
        ListNode *temp = *head;
        *head = (*head)->next;
        delete (temp);
    }
    else
    {
        int count = 1;
        ListNode *previous;
        while (count < pos && curent->next != *head)
        {
            previous = curent;
            curent = curent->next;
            count++;
        }
        previous->next = curent->next;
        delete (curent);
    }
}
int main()
{
    ListNode *head = new ListNode(0);
    ListNode *last = head;
    ListNode **temp = &head;
    insert_at_beginning(temp, 3);
    insert_at_beginning(temp, 0);
    insert_at_beginning(temp, 4);
    insert_at_beginning(temp, 10);
    insert_at_beginning(temp, 2);
    insert_at_beginning(temp, 6);
    insert_at_beginning(temp, 1);
    insert_at_beginning(temp, 1);
    last->next = head;
    delete_node(temp, 3);
    last->next = NULL;
    print_list(head);
    return 0;
}