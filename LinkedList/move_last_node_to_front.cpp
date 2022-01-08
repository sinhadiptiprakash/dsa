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
void move_last_node_to_front(ListNode **head)
{
    ListNode *curent = *head, *before;
    while (curent->next)
    {
        before = curent;
        curent = curent->next;
    }
    //very important point
    before->next = NULL;
    curent->next = *head;
    *head = curent;
}
int main()
{
    ListNode *head = new ListNode(100);
    ListNode **temp = &head;
    insert_at_beginning(temp, 12);
    insert_at_beginning(temp, 13);
    insert_at_beginning(temp, 14);
    insert_at_beginning(temp, 10);
    insert_at_beginning(temp, 15);
    insert_at_beginning(temp, 16);
    insert_at_beginning(temp, 16);
    print_list(head);
    move_last_node_to_front(temp);
    print_list(head);
    return 0;
}