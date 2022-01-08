#include <bits/stdc++.h>
using namespace std;
vector<long long> next_greater_element(vector<long long> nums)
{
    stack<long long> st;
    int n = nums.size();
    vector<long long> next_greaters(n, -1);
    for (int i = 0; i < n; i++)
    {

        while (!st.empty() && nums[i] > nums[st.top()])
        {
            next_greaters[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }
return next_greaters;
}
//below is the leet code problem on nextGreter element in which circularly next greater should be calculated problem link:
vector<int> next_greater_element_ii(vector<int> &nums)
{
    int n = nums.size();
    vector<int> res(n);
    stack<int> stack;
    for (int i = 2 * n - 1; i >= 0; --i)
    {
        while (!stack.empty() && nums[stack.top()] <= nums[i % n])
        {
            stack.pop();
        }
        res[i % n] = stack.empty() ? -1 : nums[stack.top()];
        stack.push(i % n);
    }
    return res;
}
int main()
{
    vector<long long> nums = {1, 2, 3, 4, 3};
    vector<int> nums2 = {1, 2, 3, 4, 3};
    auto res = next_greater_element_ii(nums2);
    for (int i : res)
        cout << i << ' ';
    cout << endl;
    return 0;
}