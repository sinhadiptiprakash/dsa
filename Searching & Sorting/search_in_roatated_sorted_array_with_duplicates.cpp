#include <bits/stdc++.h>
using namespace std;
// this problem is similar to the problem of searching in a rotated sorted array with all distinct elements
//but here the array may contains duplicates

//below function returns one of the indexes of the target as the array contains duplicates
int search(vector<int> &nums, int target)
{
    // getting the point from the start upto which the previous element is <= the next
    // since the array is rotated, at some point the array will be divided into two sorted array
    // and we actually find out that point in the below loop
    int i = 0;
    for (i = 1; i < nums.size(); i++)
    {
        if (nums[i - 1] > nums[i])
            break;
    }
    // now we are deciding the search space i.e where to apply binary search
    int start, end, mid;
    // if the target greater or equal to the first element that means the target lies in the left sorted array
    // i.e. left to the dividing point so the search space would be from start to i-1
    if (target >= nums[0])
    {
        start = 0;
        end = i - 1;
    }
    // else if the target smaller than the first element that means the target lies in the right sorted array
    // so our search space would be from i to end
    else
    {
        start = i;
        end = nums.size() - 1;
    }
    // now do simple binary search within the decided search space
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
} // time complexity in best case O(log(n)) in worst case O(n) because of the duplicates space O(1)
int main()
{
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;
    cout << search(nums, target) << endl;
}