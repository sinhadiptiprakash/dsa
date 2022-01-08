#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *res = new ListNode(0);
        ListNode *newHead = res;
        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                res->next = l1;
                res = res->next;
                l1 = l1->next;
            }
            else
            {
                res->next = l2;
                res = res->next;
                l2 = l2->next;
            }
        }
        if (l1)
        {
            res->next = l1;
        }
        if (l2)
            res->next = l2;
        return newHead->next;
    }
};
int main()
{
    return 0;
}