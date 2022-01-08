#include <bits/stdc++.h>
using namespace std;
class KthLargest
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;

public:
    KthLargest(int _k, vector<int> &nums)
    {
        k = _k;
        for (int i = 0; i < nums.size(); i++)
        {
            if (pq.size() < _k)
                pq.push(nums[i]);
            else if (nums[i] > pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
            // cout<<pq.top()<<" ";
        }
    }

    int add(int val)
    {
        if (pq.size() < k)
            pq.push(val);
        else if (val > pq.top())
        {
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

int main()
{
    return 0;
}