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
bool is_circular(ListNode *head)
{
    ListNode *fast = head;
    while (fast && fast->next)
    {
        if (fast->next == head || fast->next->next == head)
            return true;
        fast = fast->next->next;
    }
    return false;
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
    // print_list(head);
    cout << is_circular(head) << endl;
    return 0;
}