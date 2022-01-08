#include <bits/stdc++.h>
using namespace std;
// this problem is an extension of the sliding window maximum/minimum problem
// instead of using one deque we will be using two dequeue for min and max for storing the indexes of min and max
// like in the sliding window maximum problem in case of dq_min we maintain increasing order i.e. index of smallest at front of the dq_min
// and in case of dq_max we maintain a decreasing order
int sum_of_max_and_min_in_window(vector<int> nums, int k)
{
    int n = nums.size();
    // dq_min dq_max will store the indexes not values
    deque<int> dq_max, dq_min;
    int sum = 0;
    int min, max;
    for (int i = 0; i < n; i++)
    {
        // to maintain the decreasing order in dq_max
        while (!dq_max.empty() && nums[i] > nums[dq_max.back()])
            dq_max.pop_back();
        // to maintain the increasing order in dq_min
        while (!dq_min.empty() && nums[i] < nums[dq_min.back()])
            dq_min.pop_back();
        // push index i at the back of both dqs
        dq_max.push_back(i);
        dq_min.push_back(i);
        // now the index of min at any instance of time will be at the front of the deque_min
        min = nums[dq_min.front()];
        // now the index of max at any instance of time will be at the front of the deque_max
        max = nums[dq_max.front()];
        // now if we have shifting a window
        if (i >= k - 1)
            sum += min + max;
        // now if the front is equal to the start of this window we should remove it from front because we are shifting our window
        if (i - k + 1 == dq_max.front())
            dq_max.pop_front();
        //similarly if the front is equal to the start of this window we remove dq_min front
        if (i - k + 1 == dq_min.front())
            dq_min.pop_front();
    }
    return sum;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << sum_of_max_and_min_in_window(nums, k) << endl;
    return 0;
}