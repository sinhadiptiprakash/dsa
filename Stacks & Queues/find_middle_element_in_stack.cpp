#include <bits/stdc++.h>
using namespace std;
struct Stack
{
    struct Node
    {
        int data;
        Node *prev, *next;
        Node(int d) : data(d), prev(NULL), next(NULL) {}
    };
    Node *middle, *top;
    int size;
    Stack()
    {
        middle = NULL;
        top = NULL;
        size = 0;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    void push(int d)
    {
        size++;
        if (!top)
        {
            top = new Node(d);
            middle = top;
        }
        else
        {
            Node *temp = new Node(d);
            top->prev = temp;
            temp->next = top;
            top = temp;
            if (size % 2 == 0)
            {
                middle = middle->prev;
            }
        }
    }
    int pop()
    {
        if (isEmpty())
            return INT_MIN;
        int d = top->data;
        Node *temp = top;
        top = top->next;
        size--;
        temp->next = NULL;
        if (size % 2 == 1)
            middle = middle->next;
        delete (temp);
        return d;
    }
    int getMiddle()
    {
        if (!middle)
            return INT_MAX;
        return middle->data;
    }
    int deleteMiddle()
    {
        if (isEmpty())
            return INT_MIN;
        int item = middle->data;
        Node *temp = middle;
        size--;
        if (size == 1)
        {
            top = top->next;
            middle = top;
        }
        else if (size > 0)
        {
            middle->prev->next = middle->next;
            middle->next->prev = middle->prev;
            if (size % 2 == 1)
                middle = middle->next;
            else
                middle = middle->prev;
        }
        delete (temp);
        return item;
    }
};
int main()
{
    int a[] = {1, 2, 3, 4, 5};
    Stack stack;
    for (int i = 0; i < 5; i++)
    {
        stack.push(a[i]);
    }
    while (!stack.isEmpty())
    {
        cout << stack.deleteMiddle() << endl;
    }
    return 0;
}