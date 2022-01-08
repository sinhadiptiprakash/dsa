#include <bits/stdc++.h>
using namespace std;
#define MAX 100
class Stack
{
    int top;

public:
    Stack()
    {
        top = -1;
    }
    int array[MAX];
    bool push(int data);
    int pop();
    int peek();
    bool isEmpty();
    int size();
};
bool Stack::isEmpty()
{
    return top == -1;
}
int Stack::size()
{
    return top + 1;
}
int Stack::peek()
{
    if (isEmpty())
    {
        cout << "Stack is empty" << endl;
        return 0;
    }
    return array[top];
}
bool Stack::push(int d)
{
    if (size() == MAX)
    {
        cout << "Stack overflow" << endl;
        return false;
    }
    array[++top] = d;
    return true;
}
int Stack::pop()
{
    if (isEmpty())
    {
        cout << "Stack underflow" << endl;
        return 0;
    }
    return array[top--];
}
int main()
{
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout << stack.peek() << endl;
    while (!stack.isEmpty())
    {
        cout << stack.pop() << endl;
    }
    cout << stack.pop();
    return 0;
}