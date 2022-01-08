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
//using map
void remove_duplicates(ListNode *head)
{
    unordered_set<int> set;
    ListNode *curent = head, *before;
    while (curent)
    {
        if (set.find(curent->val) != set.end())
            before->next = curent->next;
        else
        {
            set.insert(curent->val);
            before = curent;
        }
        curent = curent->next;
    }
}
int main()
{
    ListNode *head = new ListNode(10);
    ListNode **temp = &head;
    insert_at_beginning(temp, 10);
    insert_at_beginning(temp, 10);
    insert_at_beginning(temp, 12);
    insert_at_beginning(temp, 13);
    insert_at_beginning(temp, 14);
    insert_at_beginning(temp, 10);
    insert_at_beginning(temp, 15);
    insert_at_beginning(temp, 16);
    insert_at_beginning(temp, 16);
    print_list(head);
    remove_duplicates(head);
    print_list(head);
    return 0;
}