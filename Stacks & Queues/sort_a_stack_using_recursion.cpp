#include <bits/stdc++.h>
using namespace std;
void insert_in_sorted_stack(stack<int> &stack, int element)
{
    //base case
    if (stack.empty() || stack.top() < element)
    {
        stack.push(element);
        return;
    }
    int top_element = stack.top();
    stack.pop();
    insert_in_sorted_stack(stack, element);
    stack.push(top_element);
}
void sort_stack(stack<int> &stack)
{
    if (!stack.empty())
    {
        int top_element = stack.top();
        stack.pop();
        sort_stack(stack);
        insert_in_sorted_stack(stack, top_element);
    }
}
int main()
{
    stack<int> stack;
    stack.push(5);
    stack.push(15);
    stack.push(0);
    stack.push(9);
    stack.push(2);
    stack.push(1);

    sort_stack(stack);
    while (!stack.empty())
    {
        cout << stack.top() << endl;
        stack.pop();
    }
}