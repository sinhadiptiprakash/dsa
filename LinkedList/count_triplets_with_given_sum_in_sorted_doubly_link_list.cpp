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
int count_triplets(DLL *head, int sum)
{
    DLL *i, *j, *k;
    int count = 0;
    for (i = head; i->next->next; i = i->next)
    {
        for (j = i->next; j->next; j = j->next)
        {
            for (k = j->next; k; k = k->next)
            {
                if (i->val + j->val + k->val == sum)
                    count++;
            }
        }
    }
    return count;
} //time complexity O(N^3) space O(1)
//using hashing
int count_triplets_hashing(DLL *head, int sum)
{
    unordered_map<int, DLL *> map;
    for (auto i = head; i; i = i->next)
        map[i->val] = i;
    int count = 0;
    for (auto i = head; i->next; i = i->next)
    {
        for (auto j = i->next; j; j = j->next)
        {
            auto inspect = sum - (i->val + j->val);
            if (map.find(inspect) != map.end() && map[inspect] != i && map[inspect] != j)
            {
                count++;
            }
        }
    }
    // required count of triplets
    // division by 3 as each triplet is counted 3 times
    return (count / 3);
} //time complexity O(N^2) space complexity O(N)
//using two pointers
int count_triplets_efficient(DLL *head, int sum)
{
    DLL *right, *left, *last = head;
    //for getting the last node of the list
    while (last->next)
        last = last->next;
    int count = 0;
    for (auto index = head; index->next->next; index = index->next)
    {
        left = index->next;
        right = last;
        // The loop terminates when either of two pointers
        while (left != right && right->next != left)
        {
            int curent_sum = index->val + left->val + right->val;
            if (curent_sum == sum)
            {
                left = left->next;
                right = right->prev;
                count++;
            }
            else if (curent_sum < sum)
                left = left->next;
            else
                right = right->prev;
        }
    }
    return count;
} //time complexity O(N^2) space complexity O(1)
int main()
{
    DLL *head = new DLL(9);
    DLL *last = head;
    DLL **temp = &head;
    insert_at_beginning(temp, 8);
    insert_at_beginning(temp, 6);
    insert_at_beginning(temp, 5);
    insert_at_beginning(temp, 4);
    insert_at_beginning(temp, 2);
    insert_at_beginning(temp, 1);
    cout << count_triplets_efficient(head, 17) << endl;
    return 0;
}