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
//as the link list is sorted we can use two pointer approach
vector<pair<int, int>> pairs_with_given_sum(DLL *head, int sum)
{
    DLL *left = head, *right = head;
    while (right->next)
    {
        right = right->next;
    }
    vector<pair<int, int>> result;
    while (left != right)
    {
        int temp = left->val + right->val;
        if (temp == sum)
        {
            result.push_back({left->val, right->val});
            left = left->next;
            right = right->prev;
        }
        else if (temp < sum)
            left = left->next;
        else
            right = right->prev;
    }
    return result;
}
int main()
{
    DLL *head = new DLL(10);
    DLL *last = head;
    DLL **temp = &head;
    insert_at_beginning(temp, 9);
    insert_at_beginning(temp, 5);
    insert_at_beginning(temp, 4);
    insert_at_beginning(temp, 3);
    insert_at_beginning(temp, 2);
    insert_at_beginning(temp, 2);
    insert_at_beginning(temp, 1);
    insert_at_beginning(temp, 1);
    auto result = pairs_with_given_sum(head, 5);
    for (auto i : result)
        cout << i.first << ' ' << i.second << endl;
    return 0;
}