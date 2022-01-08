#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int data;
    ListNode *next;
    ListNode(int d)
    {
        data = d;
        next = NULL;
    }
};
//recursive
ListNode *swapNodesInPairs(ListNode *head)
{
    if (!head || !head->next)
        return head;
    ListNode *second = head->next, *rest;
    if (second)
        rest = second->next;
    second->next = head;
    rest = swapNodesInPairs(rest);
    head->next = rest;
    return second;
}
// iterative using the approach like reversing a link list in groups
ListNode *swapNodesInPairsIterative(ListNode *head)
{
    if (!head || !head->next)
        return head;
    ListNode *curent = head, *start, *next, *prev = NULL;
    ListNode *dummy = new ListNode(0);
    ListNode *newHead = dummy;
    while (curent)
    {
        prev = NULL;
        start = curent;
        int i = 0;
        while (curent && i < 2)
        {
            next = curent->next;
            curent->next = prev;
            prev = curent;
            curent = next;
            i++;
        }
        dummy->next = prev;
        dummy = start;
    }
    return newHead->next;
}
int main()
{
    return 0;
}