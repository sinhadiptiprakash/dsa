#include <bits/stdc++.h>
using namespace std;
class Stack
{
    queue<int> main, auxiliary;

public:
    Stack() {}
    bool is_empty()
    {
        //if both the queues are empty then the stack is empty
        return (main.empty() && auxiliary.empty());
    }
    int stack_size()
    {
        // as always one of the queue is empty we should return the size of the queue which is not empty
        return max(main.size(), auxiliary.size());
    }
    void push_data(int data)
    {
        //if the main queue is empty we first push the data into the empty queue
        //after that we pop all the elements from the other stack and one by one push the popped elements into the main stack
        if (main.empty())
        {
            main.push(data);
            while (!auxiliary.empty())
            {
                main.push(auxiliary.front());
                auxiliary.pop();
            }
        }
        //similar intuition
        else
        {
            auxiliary.push(data);
            while (!main.empty())
            {
                auxiliary.push(main.front());
                main.pop();
            }
        }
    }
    int pop_data()
    {
        //stack underflow
        if (is_empty())
            return -1;
        int elem;
        //we pop the data at front from the queue that is not empty
        if (main.size() > auxiliary.size())
        {
            elem = main.front();
            main.pop();
        }
        else
        {
            elem = auxiliary.front();
            auxiliary.pop();
        }
        return elem;
    }
    int peek()
    {
        //we return the front element of the queue that is not empty
        if (main.size() > auxiliary.size())
            return main.front();
        return auxiliary.front();
    }
};
int main()
{
    Stack stack;
    for (int i = 0; i < 5; i++)
    {
        stack.push_data(i);
    }
    cout << stack.peek() << endl;
    while (!stack.is_empty())
    {
        cout << stack.pop_data() << endl;
    }
    return 0;
}