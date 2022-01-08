#include <bits/stdc++.h>
using namespace std;
class Queue
{
    stack<int> stack1;
    stack<int> stack2;
    void enqueue(int x)
    {
        stack1.push(x);
    }
    int dequeue(int x)
    {
        while (stack1.size() != 1)
        {

            stack2.push(stack1.top());

            stack1.pop(); //pop until size of stack one becomes 1;
        }

        int result = stack1.top();

        stack1.pop();

        while (!stack2.empty()) //add stack 2 elements to stack 1;
        {
            stack1.push(stack2.top());

            stack2.pop();
        }
        return result;
    }
    int peek()
    {
        //same as pop( ) function but here we dont need to pop the element;
        while (stack1.size() != 1)
        {

            stack2.push(stack1.top());

            stack1.pop();
        }
        int result = stack1.top();
        while (!stack2.empty())
        {

            stack1.push(stack2.top());

            stack2.pop();
        }
        return result;
    }
    bool empty()
    {
        return stack1.empty();
    }
    int size()
    {
        return stack1.size();
    }
};
int main()
{
    return 0;
}