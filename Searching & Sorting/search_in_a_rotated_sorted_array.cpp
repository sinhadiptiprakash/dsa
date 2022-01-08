#include <bits/stdc++.h>
using namespace std;
// the simple and brute force approach is to use a linear search to search the element
//time complexity for this approach is O(N) space complexity O(1)
//we can do better by using binary search
int search_in_rotated_sorted_array(int nums[], int n, int target)
{
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        // if we get the target we return it
        if (nums[mid] == target)
            return mid;
        // if middle element is greater than the target then there will be 2 options we can go right as well as left as array is rotated
        else if (nums[mid] > target)
        {
            //now if the mid element is greater than the first element and first element is greater than the target
            //it means that target lies in the right side of the mid
            if (nums[mid] >= nums[start] && nums[start] > target)
                start = mid + 1;
            //else we go left
            else
                end = mid - 1;
        }
        //similarly if the middle element is less than target then we can go right as well as left
        else
        {
            // if the last element is the greater of equal to the middle element and last element is less than target
            //it means that target element lies in left side of the mid
            if (nums[end] >= nums[mid] && nums[end] < target)
                end = mid - 1;
            // else we go right
            else
                start = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int nums[] = {4, 5, 6, 7, 0, 1, 2};
    int n = sizeof(nums) / sizeof(int);
    cout << search_in_rotated_sorted_array(nums, n, 0) << endl;
    return 0;
}