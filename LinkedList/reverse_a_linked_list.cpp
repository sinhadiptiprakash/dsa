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
// the position here is for 0 based indexing
void insert(ListNode **head, int data, int position)
{
    if (position == 1)
    {
        insert_at_beginning(head, data);
        return;
    }
    ListNode *newNode = new ListNode(data);
    int count = 0;
    ListNode *curent = *head;
    ListNode *before;
    while (curent && count < position)
    {
        before = curent;
        curent = curent->next;
        count++;
    }
    before->next = newNode;
    newNode->next = curent;
}
void delete_at_beginning(ListNode **head)
{
    ListNode *temp = *head;
    *head = temp->next;
    delete temp;
}
// position here is 0 based indexing
void delete_node(ListNode **head, int position)
{
    if (position == 1)
    {
        delete_at_beginning(head);
        return;
    }
    int count = 0;
    ListNode *curent = *head;
    ListNode *before;
    while (curent && count < position)
    {
        count++;
        before = curent;
        curent = curent->next;
    }
    ListNode *temp = curent;
    before->next = curent->next;
    delete temp;
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
// recursive approach for reversing a linked list
ListNode *reverse_list(ListNode *head)
{
    if (!head || !head->next)
        return head;
    ListNode *curent = head;
    ListNode *secondNode = curent->next;
    ListNode *rest = reverse_list(secondNode);
    secondNode->next = curent;
    curent->next = NULL;
    return rest;
} //time complexity O(N) space complexity O(N) for recursive overhead
// using stack
ListNode *reverse_list_using_stack(ListNode *head)
{
    stack<ListNode *> stack;
    ListNode *temp = head;
    while (temp->next)
    {
        stack.push(temp);
        temp = temp->next;
    }
    head = temp;
    while (!stack.empty())
    {
        temp->next = stack.top();
        temp = temp->next;
        stack.pop();
    }
    temp->next = NULL;
    return head;
} //time complexity O(N) and space complexity O(N)

//iterative method
ListNode *reverse_list_iterative(ListNode *head)
{
    ListNode *temp, *prev = NULL;
    temp = head->next;
    while (head)
    {
        temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    return prev;
}
int main()
{
    ListNode *head = new ListNode(10);
    ListNode **temp = &head;
    insert_at_beginning(temp, 11);
    insert_at_beginning(temp, 12);
    insert_at_beginning(temp, 13);
    insert_at_beginning(temp, 14);
    insert_at_beginning(temp, 15);
    insert_at_beginning(temp, 16);
    insert_at_beginning(temp, 16);
    // as temp stores the address of the head we can write temp as &head
    insert(&head, 100, 6);
    print_list(head);
    ListNode *rest = reverse_list_using_stack(head);
    print_list(rest);
    return 0;
}