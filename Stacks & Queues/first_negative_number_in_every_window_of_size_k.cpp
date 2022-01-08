#include <bits/stdc++.h>
using namespace std;
vector<int> first_negatives(vector<int> &nums, int k)
{
    int n = nums.size();
    //take a queue of int to store the indexes of negatives only
    queue<int> q;
    //for storing the first_negatives for all subarrays of size k
    vector<int> result;
    //first of all we will Enqueue all the negative elements of nums into the queue
    for (int i = 0; i < k; i++)
    {
        // if nums[i] is negative Enqueue its index into the queue
        if (nums[i] < 0)
            q.push(i);
    }
    //if the queue contains some indexes of negatives
    if (!q.empty())
    {
        if (nums[q.front()] == nums[0])
        {
            result.push_back(nums[q.front()]);
            q.pop();
        }
        else
            result.push_back(nums[q.front()]);
    }
    // else if the queue doesnt contain any negative elements in it
    // that means this subarray does'nt contain any negatives
    else
        result.push_back(0);
    // now we start from the next subarray of size k,
    // here start is the starting and end is ending of the curent subarray
    // as we have already handled the first subarray of size k which start from 0 to k-1,
    // now we start from 1 to k
    int start = 1, end = k;
    // while have'nt consider all subarrays of size K
    while (end < n)
    {
        // if the number at end is negative Enqueue its index into the queue
        if (nums[end] < 0)
            q.push(end);
        // if the q is empty that means this curent subarray does'nt have any negative
        // so we push 0 for this subarray in result
        if (q.empty())
            result.push_back(0);
        // else if the q is not empty
        else
        {
            // we first push the negativefront negative of the queue to the result for this curent subarray
            result.push_back(nums[q.front()]);
            // now if the the index at front of the q is equal to start,
            //then we should remove it from the queue as we are moving to the next subarray
            if (start == q.front())
                q.pop();
        }
        //moving to the next subarray
        start++, end++;
    }
    return result;
}
int main()
{
    //taking size of the input array and K as input
    int n, k;
    cin >> n >> k;
    //initializing the input array as a vector of int of size N
    vector<int> nums(n);
    // taking elements of the input array
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    //getting the solution in the result vector
    auto result = first_negatives(nums, k);
    //printing the result
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << ' ';
    }
    cout << endl;
    return 0;
}