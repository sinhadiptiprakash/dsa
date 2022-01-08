#include <bits/stdc++.h>
using namespace std;
//for better understanding all the approaches refer https://leetcode.com/problems/find-peak-element/solution/
//using linear search
int findPeakElement(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] > nums[i + 1])
            return i;
    }
    return n - 1;
} // TC O(N) SC O(1)
int findPeakElement(vector<int> &nums)
{
    int low = 0, high = nums.size() - 1;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] > nums[mid + 1])
        {
            high = mid;
        }
        else
            low = mid + 1;
    }
    return low;
} // TC O(log(N)) and SC O(1)
int main()
{
    return 0;
}