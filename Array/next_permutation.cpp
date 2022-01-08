// problem link https://leetcode.com/problems/next-permutation/solution/
#include <bits/stdc++.h>
using namespace std;
//the approach is simple
//step1. scan the array from riht to left and find the first decreasing element suppose this element is at index i
//step2. scan the array from right to i and find the first element greater than array[i] let this index is j
//step3. swap element at i and j
//step4. reverse the array from i+1 to end of the array

//below is the implementation of above algorithm
void next_permutation(vector<int> &nums)
{
    int n = nums.size();
    int i = n - 2;
    //finding the first element from the right side of the array that is greater than it just right elemetn
    while (i >= 0 && nums[i] >= nums[i + 1])
    {
        i--;
    }
    //finding the first element greater than the ith element from the right side
    if (i >= 0)
    {
        int j = n - 1;
        while (nums[j] <= nums[i])
            j--;
        swap(nums[i], nums[j]);
    }
    //reverse the whole array starting from i+1
    reverse(nums.begin() + i + 1, nums.end());
}
int main()
{
    vector<int> nums = {6,1,3,2,3,1,0};
    next_permutation(nums);
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << ' ';
    cout << endl;
    return 0;
}