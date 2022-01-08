#include <bits/stdc++.h>
using namespace std;
class KQueue
{
    int n, k;
    int *array;
    int *front;
    int *rear;
    int *next;
    int free;
public:
    KQueue(int n1, int k1);
    void EnQueue(int data, int kth);
    int DeQueue(int kth);
    bool isFull() { return free == -1; }
    bool is_empty(int kth) { return (front[kth] == -1); }
};
KQueue::KQueue(int n1, int k1)
{
    n = n1;
    k = k1;
    array = new int[n];
    next = new int[n];
    front = new int[k];
    rear = new int[k];
    // Initialize all queues as empty
    for (int i = 0; i < k; i++)
        front[i] = -1;

    // Initialize all spaces as free
    free = 0;
    for (int i = 0; i < n - 1; i++)
        next[i] = i + 1;
    next[n - 1] = -1; // -1 is used to indicate end of free list
}
void KQueue::EnQueue(int data, int kth)
{
    if (isFull())
    {
        cout << "OverFlow" << endl;
        return;
    }
    int i = free;
    free = next[i];
    if (is_empty(kth))
        front[kth] = i;
    else
        next[rear[kth]] = i;
    next[i] = -1;
    rear[kth] = i;
    array[i] = data;
}
int KQueue::DeQueue(int kth)
{
    if (is_empty(kth))
    {
        cout << "Underflow" << endl;
        return INT_MAX;
    }
    int i = front[kth];
    front[kth] = next[i];
    next[i] = free;
    free = i;
    return array[i];
}
int main()
{
    int k = 3, n = 10;
    KQueue ks(n, k);

    // Let us put some items in queue number 2
    ks.EnQueue(15, 2);
    ks.EnQueue(45, 2);

    // Let us put some items in queue number 1
    ks.EnQueue(17, 1);
    ks.EnQueue(49, 1);
    ks.EnQueue(39, 1);

    // Let us put some items in queue number 0
    ks.EnQueue(11, 0);
    ks.EnQueue(9, 0);
    ks.EnQueue(7, 0);

    cout << "Dequeued element from queue 2 is " << ks.DeQueue(2) << endl;
    cout << "Dequeued element from queue 1 is " << ks.DeQueue(1) << endl;
    cout << "Dequeued element from queue 0 is " << ks.DeQueue(0) << endl;
    return 0;
}