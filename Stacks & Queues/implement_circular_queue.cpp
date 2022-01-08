#include <bits/stdc++.h>
using namespace std;
class MyCircularQueue
{
private:
    int *nums;
    int capacity;
    int size;
    int front;
    int rear;

public:
    MyCircularQueue(int k)
    {
        nums = (int *)malloc(sizeof(int) * k);
        capacity = k;
        size = 0;
        front = 0;
        rear = -1;
    }

    bool enQueue(int value)
    {
        if (size == capacity)
            return false;
        rear = (rear + 1) % capacity;
        nums[rear] = value;
        size++;
        return true;
    }

    int deQueue()
    {
        if (size == 0)
            return INT_MAX;
        int data = nums[front];
        front = (front + 1) % capacity;
        size--;
        return data;
    }

    int Front()
    {
        return size == 0 ? -1 : nums[front];
    }

    int Rear()
    {
        return size == 0 ? -1 : nums[rear];
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == capacity;
    }
};
int main()
{
    MyCircularQueue q(5);
    for (int i = 0; i < 5; i++)
    {
        q.enQueue(i * 10);
    }
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    for (int i = 0; i < 5; i++)
        q.enQueue(i * 20);
    while (!q.isEmpty())
    {
        cout << q.deQueue() << endl;
    }
    return 0;
}