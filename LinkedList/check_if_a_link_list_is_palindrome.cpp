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
ListNode *reverse_list(ListNode *head)
{
    ListNode *prev = NULL, *curr = head, *next;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
bool is_palindrome(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // if no of nodes is odd
    // then fast -> next must be null
    if (fast)
    {
        ListNode *p = head, *q = reverse_list(slow);
        while (q->next)
        {
            if (p->val != q->val)
                return false;
            p = p->next;
            q = q->next;
        }
        return true;
    }
    ListNode *p = head, *q = reverse_list(slow);
    while (q)
    {
        if (p->val != q->val)
            return false;
        p = p->next;
        q = q->next;
    }
    return true;
}
int main()
{
    ListNode *head = new ListNode(0);
    ListNode **temp = &head;
    insert_at_beginning(temp, 3);
    insert_at_beginning(temp, 0);
    insert_at_beginning(temp, 4);
    insert_at_beginning(temp, 4);
    insert_at_beginning(temp, 0);
    insert_at_beginning(temp, 3);
    insert_at_beginning(temp, 0);
    print_list(head);
    cout << is_palindrome(head) << endl;
    return 0;
}