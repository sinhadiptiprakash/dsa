#include <bits/stdc++.h>
using namespace std;
struct DLL
{
    int val;
    DLL *next;
    DLL *prev;
    DLL(int x) : val(x), next(NULL), prev(NULL) {}
};

void insert_at_beginning(DLL **head, int data)
{
    DLL *temp = new DLL(data);
    temp->next = *head;
    (*head)->prev = temp;
    *head = temp;
}

void print_list(DLL *head)
{
    while (head)
    {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << endl;
}
DLL *reverse_list(DLL *head)
{
    DLL *next, *previous, *temp, *curent = head;
    while (curent)
    {
        previous = curent;
        next = curent->next;
        temp = curent->prev;
        curent->prev = curent->next;
        curent->next = temp;
        curent = next;
    }
    return previous;
}
int main()
{
    DLL *head = new DLL(0);
    DLL *last = head;
    DLL **temp = &head;
    insert_at_beginning(temp, 3);
    insert_at_beginning(temp, 0);
    insert_at_beginning(temp, 4);
    insert_at_beginning(temp, 10);
    insert_at_beginning(temp, 2);
    insert_at_beginning(temp, 6);
    insert_at_beginning(temp, 1);
    insert_at_beginning(temp, 1);
    print_list(head);
    DLL *res = reverse_list(head);
    print_list(res);
    return 0;
}