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

void remove_duplicates(ListNode *head)
{
    ListNode *current = head;
    while (current && current->next)
    {
        if (current->next->val == current->val)
            current->next = current->next->next;
        else
            current = current->next;
    }
}
int main()
{
    ListNode *head = new ListNode(20);
    ListNode **temp = &head;
    insert_at_beginning(temp, 20);
    insert_at_beginning(temp, 19);
    insert_at_beginning(temp, 18);
    insert_at_beginning(temp, 18);
    insert_at_beginning(temp, 16);
    ListNode *temp2 = head;
    insert_at_beginning(temp, 14);
    insert_at_beginning(temp, 14);
    insert_at_beginning(temp, 10);
    insert_at_beginning(temp, 10);
    print_list(head);
    remove_duplicates(head);
    print_list(head);
    return 0;
}