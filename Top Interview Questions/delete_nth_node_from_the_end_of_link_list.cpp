#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int v)
    {
        val = v;
        next = NULL;
    }
};
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *slow, *fast = head, *slowPrev = NULL;
    ListNode *newHead = head;
    int i = 0;
    while (fast && i < n)
    {
        fast = fast->next;
        i++;
    }
    slow = head;
    while (fast)
    {
        slowPrev = slow;
        slow = slow->next;
        fast = fast->next;
    }
    if (slowPrev && slow)
        slowPrev->next = slow->next;
    else
        return slow->next;
    return newHead;
}
int main()
{
    return 0;
}