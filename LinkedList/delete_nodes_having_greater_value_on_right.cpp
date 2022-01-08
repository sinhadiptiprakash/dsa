#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};
void push(Node **head, int d)
{
    Node *new_node = new Node(d);
    new_node->next = *head;
    *head = new_node;
}
void print(Node *head)
{
    while (head)
    {
        cout << head->data << ' ';
        head = head->next;
    }
    cout << endl;
}
//brute force approach for every node check if there is a node with greater data than it on the right side delete it

/*
Method 2 (Use Reverse) 
Thanks to Paras for providing the below algorithm. 
1. Reverse the list. 
2. Traverse the reversed list. Keep max till now. If the next node is less than max, 
    then delete the next node, otherwise max = next node. 
3. Reverse the list again to retain the original order. 
Time Complexity: O(n)
*/
void reverse_list(Node **head)
{
    Node *curent = *head, *before = NULL, *next;
    while (curent)
    {
        next = curent->next;
        curent->next = before;
        before = curent;
        curent = next;
    }
    *head = before;
}
//below is the function for deleting a given node
void delete_given(Node **node)
{
    Node *temp = (*node)->next;
    (*node)->data = temp->data;
    (*node)->next = temp->next;
}
Node *delete_nodes_greater_value_on_right(Node *head)
{
    reverse_list(&head);
    Node *maxnode = head;
    Node *curent = head;
    Node *new_head = curent, *retain = head;
    while (curent && curent->next)
    {
        if (curent->next->data < maxnode->data)
        {
            Node *temp = curent->next;
            curent->next = temp->next;
            //free(temp);
        }

        /* If current is greater than max,
            then update max and move current */
        else
        {
            curent = curent->next;
            maxnode = curent;
        }
    }
    reverse_list(&new_head);
    return new_head;
}
//method 3 most efficient
Node *delete_lesser(Node *head)
{
    if (head == NULL && head->next == NULL)
        return head;
    Node *temp = head;
    Node *pre = NULL;
    while (temp && temp->next)
    {
        if (temp->data < temp->next->data)
        {
            pre = temp->next;
            temp->data = pre->data;
            temp->next = pre->next;
            temp = head;
        }
        else
            temp = temp->next;
    }
    return head;
} //time complexity O(N) space complexity O(1)
int main()
{
    Node *head = new Node(3);
    push(&head, 2);
    push(&head, 6);
    push(&head, 5);
    push(&head, 11);
    push(&head, 10);
    push(&head, 15);
    push(&head, 12);
    print(head);
    Node *res = delete_lesser(head);
    print(res);
    return 0;
}