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
ListNode* middle_node(ListNode *head){
    ListNode *slow = head, *fast = head;
    while(slow && fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
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
    cout << middle_node(head)->val << endl;
    return 0;
}