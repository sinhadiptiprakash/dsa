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
// below is the function for getting the middle element of a link list
ListNode *getMid(ListNode *head)
{
    ListNode *midPrev = nullptr;
    while (head && head->next)
    {
        midPrev = (midPrev == nullptr) ? head : midPrev->next;
        head = head->next->next;
    }
    ListNode *mid = midPrev->next;
    midPrev->next = nullptr;
    return mid;
}
ListNode *merge_sorted_list(ListNode *list1, ListNode *list2)
{
    ListNode dummyHead(0);
    ListNode *ptr = &dummyHead;
    while (list1 && list2)
    {
        if (list1->val < list2->val)
        {
            ptr->next = list1;
            list1 = list1->next;
        }
        else
        {
            ptr->next = list2;
            list2 = list2->next;
        }
        ptr = ptr->next;
    }
    if (list1)
        ptr->next = list1;
    else
        ptr->next = list2;

    return dummyHead.next;
}

ListNode *merge_sort(ListNode *head)
{
    if (!head || !head->next)
        return head;
    ListNode *mid = getMid(head);
    ListNode *left = merge_sort(head);
    ListNode *right = merge_sort(mid);
    return merge_sorted_list(left, right);
}

int main()
{
    ListNode *head = new ListNode(0);
    ListNode **temp = &head;
    insert_at_beginning(temp, 3);
    insert_at_beginning(temp, 0);
    insert_at_beginning(temp, 4);
    insert_at_beginning(temp, 10);
    insert_at_beginning(temp, 2);
    insert_at_beginning(temp, 6);
    insert_at_beginning(temp, 1);
    print_list(head);

    ListNode *sorted_list = merge_sort(head);
    print_list(sorted_list);
    return 0;
}