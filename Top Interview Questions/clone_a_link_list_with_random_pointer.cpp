#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int val;
    Node *next;
    Node *random;
    Node(int d)
    {
        val = d;
        next = NULL;
        random = NULL;
    }
};
void push(Node **head, int d)
{
    Node *new_node = new Node(d);
    new_node->next = *head;
    *head = new_node;
}
Node *clone_list_efficient(Node *head)
{
    Node *curent = head;
    Node *next = head;
    while (curent != NULL)
    {
        next = curent->next;
        Node *copy = new Node(curent->val);
        curent->next = copy;
        copy->next = next;
        curent = next;
    }
    curent = head;
    while (curent != NULL)
    {
        if (curent->random != NULL)
        {
            curent->next->random = curent->random->next;
        }
        curent = curent->next->next;
    }
    curent = head;
    Node *newHead = new Node(0);
    Node *jump = newHead;
    while (curent != NULL)
    {
        next = curent->next->next;
        jump->next = curent->next;
        curent->next = next;
        jump = jump->next;
        curent = curent->next;
    }
    return newHead->next;
} //time complexity O(N) space complexity O(1)
int main()
{
    return 0;
}