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
long long multiply_2_lists(Node *l1, Node *l2)
{
    const int mod = 1e9 + 7;
    long long num1 = 0, num2 = 0;
    Node *curent = l1;
    int prev = 0;
    while (curent)
    {
        num1 = prev * 10 + curent->data;
        prev = num1;
        curent = curent->next;
    }
    curent = l2;
    prev = 0;
    while (curent)
    {
        num2 = prev * 10 + curent->data;
        prev = num2;
        curent = curent->next;
    }
    return (num1 % mod * num2 % mod) % mod;
}

int main()
{

    return 0;
}