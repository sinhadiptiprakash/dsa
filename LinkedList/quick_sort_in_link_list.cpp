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
void SwapValue(ListNode *a, ListNode *b)
{
    int temp = a->val;
    a->val = b->val;
    b->val = temp;
}

ListNode *Partition(ListNode *start, ListNode *end)
{
    int pivotValue = start->val;
    ListNode *p = start;
    ListNode *q = start->next;
    while (q != end)
    {
        if (q->val < pivotValue)
        {
            p = p->next;
            SwapValue(p, q);
        }
        q = q->next;
    }
    SwapValue(p, start);
    return p;
}

void QuickSort(ListNode *start, ListNode *end)
{
    if (start != end)
    {
        ListNode *mid = Partition(start, end);
        QuickSort(start, mid);
        QuickSort(mid->next, end);
    }
}

ListNode *sortList(ListNode *head)
{
    QuickSort(head, NULL);
    return head;
}
int main()
{
    ListNode *head = new ListNode(0);
    ListNode **temp = &head;
    insert_at_beginning(temp, 2);
    insert_at_beginning(temp, 3);
    insert_at_beginning(temp, 0);
    insert_at_beginning(temp, 4);
    insert_at_beginning(temp, 10);
    insert_at_beginning(temp, 2);
    insert_at_beginning(temp, 6);
    insert_at_beginning(temp, 1);
    insert_at_beginning(temp, 1);
    insert_at_beginning(temp, 2);
    insert_at_beginning(temp, 4);
    print_list(head);
    ListNode *res = sortList(head);
    print_list(res);
    return 0;
}