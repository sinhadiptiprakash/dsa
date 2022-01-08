#include <bits/stdc++.h>
using namespace std;
/*
We have to find max elements in every K size sliding window in this problem. So, to get the max element
in the current K size window we can use deque to store the potential max elements in decreasing order
where the max element is always in the front. For every element we pop elements from the back of deque
as long as back element is less than the current element cause we want to store the potential max elmeents
in the deque only and then we push the current element. After end of every K size window we push the front
element of deque in the result vector. Also we will remove the front element of the deque if the element is
outside the next K size sliding window. Here in the solution we stored the index of the element rather than
actual value.
*/
vector<int> sliding_window_maximums(vector<int> &nums, int k)
{
    int n = nums.size();
    // if size of nums is 1 or k is 1 the result will be nums itself
    if (n == 1 || k == 1)
        return nums;
    // deque will store the indexes not the values in a decreasing order
    //i.e. largest at any moment will be at front of the dequeue
    deque<int> dq;
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        // while the dq is not empty and the value at the index stored at the back of the dq is less than the curent value i.e. nums[i]
        // we keep removing those smaller elements from the back of the deque
        // as we always need largest at the front of the deque at any moment
        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();
        // now push the curent element's index at the back because in above loop we have removed all the elements smaller than the curent element
        // so as the order is now maintained so we can push the curent element at the back of the dequeue
        dq.push_back(i);
        // now if we have completed a window of size k then we should push the value at index stored at the front of the dequeue
        // because here we are interested in gettiing max everytime in every window
        if (i >= k - 1)
            res.push_back(nums[dq.front()]);
        // now if the index at the front of the dequeue is the starting of the curent window of size k
        // remove the front from the deque
        if (i - k + 1 == dq.front())
            dq.pop_front();
    }
    return res;
}
int main()
{
    int n, w;
    cin >> n >> w;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    auto res = sliding_window_maximums(a, w);
    for (int i : res)
    {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}