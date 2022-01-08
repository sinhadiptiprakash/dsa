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
// using head recursion
void add_one(ListNode *head, int &carry)
{
    if (!head)
        return;
    add_one(head->next, carry);
    int sum = head->val + carry;
    head->val = sum % 10;
    carry = sum / 10;
} //time complexity O(N) space complexity O(N) for recursive overhead
//using stack
void add_one_using_stack(ListNode *head)
{
    if (!head)
        return;
    stack<ListNode *> stack;
    while (head)
    {
        stack.push(head);
        head = head->next;
    }
    int carry = 1;
    while (not stack.empty())
    {
        int sum = stack.top()->val + carry;
        stack.top()->val = sum % 10;
        carry = sum / 10;
        stack.pop();
    }
} //time complexity O(N) space complexity O(N)

// below method does'nt require any extra space
// in this method we first reverse the link list and then from left side we will add 1
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
ListNode *add_one_efficient(ListNode *head)
{
    // first of all reverse the link list
    head = reverse(head);
    //now add 1 by traversing the link list from left to right

    int carry = 1, sum;
    ListNode *curent = head, *temp;
    while (curent)
    {
        sum = curent->val + carry;
        curent->val = sum % 10;
        carry = sum / 10;
        temp = curent;
        curent = curent->next;
    }
    //if a carry is still there add it to the end of the link list with a new node
    if (carry)
        temp->next = new ListNode(carry);
    // as we have reversed the list now we have to again reverse the list to retain it
    return reverse(head);
}
int main()
{
    ListNode *head = new ListNode(9);
    ListNode **temp = &head;
    insert_at_beginning(temp, 2);
    insert_at_beginning(temp, 3);
    insert_at_beginning(temp, 4);
    insert_at_beginning(temp, 0);
    insert_at_beginning(temp, 5);
    insert_at_beginning(temp, 6);
    insert_at_beginning(temp, 6);
    print_list(head);
    int carry = 1;
    ListNode *res = add_one_efficient(head);
    print_list(res);
    return 0;
}