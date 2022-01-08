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

ListNode *reverse(ListNode *head)
{
    ListNode *curent = head, *res = head, *prev_node = NULL, *next_node;
    while (curent)
    {
        next_node = curent->next;
        curent->next = prev_node;
        prev_node = curent;
        curent = next_node;
    }
    return prev_node;
}
ListNode *add_two_numbers(ListNode *head1, ListNode *head2)
{
    //first of all reverse both the link lists
    head1 = reverse(head1);
    head2 = reverse(head2);
    ListNode *first = head1, *second = head2;
    ListNode *result = new ListNode(0);
    ListNode *res = result;
    int carry = 0, sum = 0;
    while (first && second)
    {
        sum = first->val + second->val + carry;
        res->next = new ListNode(sum % 10);
        carry = sum / 10;
        res = res->next;
        first = first->next;
        second = second->next;
    }
    while (first)
    {
        sum = first->val + carry;
        res->next = new ListNode(sum % 10);
        carry = sum / 10;
        res = res->next;
        first = first->next;
    }
    while (second)
    {
        sum = second->val + carry;
        res->next = new ListNode(sum % 10);
        carry = sum / 10;
        res = res->next;
        second = second->next;
    }
    if (carry)
    {
        res->next = new ListNode(carry);
    }
    //as the fist node of result is containing a 0 so we should ignore that and reverse the rest
    // as we have reversed previously so to maintain the correct order again reverse it again and return
    return reverse(result->next);
}
int main()
{
    ListNode *head1 = new ListNode(9);
    ListNode **temp1 = &head1;
    insert_at_beginning(temp1, 2);
    insert_at_beginning(temp1, 3);
    insert_at_beginning(temp1, 4);
    insert_at_beginning(temp1, 0);
    insert_at_beginning(temp1, 5);
    insert_at_beginning(temp1, 6);
    insert_at_beginning(temp1, 6);
    print_list(head1);

    ListNode *head2 = new ListNode(9);
    ListNode **temp2 = &head2;
    insert_at_beginning(temp2, 3);
    insert_at_beginning(temp2, 3);
    insert_at_beginning(temp2, 7);
    insert_at_beginning(temp2, 0);
    insert_at_beginning(temp2, 9);
    insert_at_beginning(temp2, 6);
    insert_at_beginning(temp2, 5);
    print_list(head2);
    ListNode *res = add_two_numbers(head1, head2);
    print_list(res);
    return 0;
}