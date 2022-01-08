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

void split_list(ListNode *head, ListNode **head1_ref, ListNode **head2_ref)
{
    ListNode *slow = head, *fast = head;

    while (fast->next != head && fast->next->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    *head1_ref = head;
    *head2_ref = slow->next;

    ListNode *temp = slow->next;

    slow->next = head;

    ListNode *curr = *head2_ref;

    while (curr->next != head)
    {
        curr = curr->next;
    }

    curr->next = *head2_ref;
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
    ListNode *head1_ref, *head2_ref;
    split_list(head, &head1_ref, &head2_ref);
    return 0;
}