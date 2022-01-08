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
ListNode *intersection(ListNode *head1, ListNode *head2)
{
    ListNode *result = new ListNode(INT_MAX);
    ListNode *res = result;
    while (head1 && head2)
    {
        if (head1->val == head2->val)
        {
            if (head1->val != res->val)
            {
                res->next = new ListNode(head1->val);
                res = res->next;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        else if (head1->val < head2->val)
            head1 = head1->next;
        else
            head2 = head2->next;
    }
    return result->next;
}
int main()
{
    ListNode *head1 = new ListNode(9);
    ListNode **temp1 = &head1;
    insert_at_beginning(temp1, 9);
    insert_at_beginning(temp1, 8);
    insert_at_beginning(temp1, 7);
    insert_at_beginning(temp1, 5);
    insert_at_beginning(temp1, 3);
    insert_at_beginning(temp1, 1);
    insert_at_beginning(temp1, 0);
    print_list(head1);

    ListNode *head2 = new ListNode(8);
    ListNode **temp2 = &head2;
    insert_at_beginning(temp2, 6);
    insert_at_beginning(temp2, 5);
    insert_at_beginning(temp2, 5);
    insert_at_beginning(temp2, 2);
    insert_at_beginning(temp2, 0);
    insert_at_beginning(temp2, 0);
    insert_at_beginning(temp2, -1);
    print_list(head2);
    ListNode *res = intersection(head1, head2);
    print_list(res);
    return 0;
}