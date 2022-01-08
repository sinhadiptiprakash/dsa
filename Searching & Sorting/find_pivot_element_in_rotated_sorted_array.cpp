#include <bits/stdc++.h>
using namespace std;
//we can use a modified binary seach
int find_min(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    if (nums[0] < nums[n - 1])
        return nums[0]; //means there is no rotation in the array
    int lo = 0, hi = n - 1, mid;
    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;
        //if the mid element is greater than its next element then mid+1 element is the smallest
        //This point would be the point of change. From higher to lower value.
        //terminating condition we got the min
        if (nums[mid] > nums[mid + 1])
            return nums[mid + 1];
        // if the mid element is lesser than its previous element then mid element is the smallest
        if (nums[mid] < nums[mid - 1])
            return nums[mid];
        // if the mid elements value is greater than the 0th element this means
        // the least value is still somewhere to the right as we are still dealing with elements
        // greater than nums[0]
        if (nums[mid] > nums[0])
            lo = mid + 1;
        //if nums[0] is greater than the mid value then this means the smallest value is somewhere to the left
        else
            hi = mid - 1;
    }
    return -1;
}
int main()
{
    vector<int> nums = {6, 7, 0, 1, 2, 3,4};
    cout << find_min(nums) << endl;
    return 0;
}