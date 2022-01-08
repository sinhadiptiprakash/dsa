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
int length(ListNode *head)
{
    int len = 0;
    while (head)
    {
        len++;
        head = head->next;
    }
    return len;
}
ListNode *intersection_point(ListNode *head1, ListNode *head2)
{
    // first of all get the length of the two link list
    int l1 = length(head1);
    int l2 = length(head2);
    int d = 0;
    ListNode *ptr1;
    ListNode *ptr2;
    // we then start with the longer list and move abs(l1-l2) nodes
    // to make starting to ending length of both the list same
    // if first list is lengthier then we should start with first list
    if (l1 > l2)
    {
        d = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else //else we should start with second list
    {
        d = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }
    // now we move lengthier list's head d steps to make both head aligned i.e. same length from start to end
    while (d)
    {
        ptr1 = ptr1->next;
        if (ptr1 == NULL)
            return NULL;
        d--;
    }
    // now both ptr1 and ptr2 is aligned now from here we will move 1 node at a time
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1 == ptr2)
            return ptr1;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return NULL;
}
ListNode *intersection_point2(ListNode *head1, ListNode *head2)
{
    ListNode *tempA = head1;
    ListNode *tempB = head2;
    while (tempA != tempB)
    {
        if (tempA == NULL)
            tempA = head2;
        else
            tempA = tempA->next;
        if (tempB == NULL)
            tempB = head1;
        else
            tempB = tempB->next;
    }
    return tempA;
}

int main()
{
    ListNode *head1 = new ListNode(9);
    ListNode **temp1 = &head1;
    insert_at_beginning(temp1, 9);
    insert_at_beginning(temp1, 8);
    insert_at_beginning(temp1, 7);
    insert_at_beginning(temp1, 105);
    ListNode *intersection = head1;
    insert_at_beginning(temp1, 3);
    // insert_at_beginning(temp1, 1);
    // insert_at_beginning(temp1, 0);

    ListNode **temp2 = &intersection;
    insert_at_beginning(temp2, 6);
    insert_at_beginning(temp2, 5);
    insert_at_beginning(temp2, 5);
    insert_at_beginning(temp2, 2);
    insert_at_beginning(temp2, 0);
    insert_at_beginning(temp2, 0);
    insert_at_beginning(temp2, -1);
    ListNode *res = intersection_point(head1, *temp2);
    cout << res->val << endl;
    return 0;
}