#include <bits/stdc++.h>
using namespace std;
//using binary seach
int findMin(int a[], int n)
{
    if (a[0] < a[n - 1])
        return a[0]; //means there is no rotation in the array
    int lo = 0, hi = n - 1, mid;
    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;
        // if the mid element is greater than its next element then mid+1 element is the smallest
        // This point would be the point of change. From higher to lower value.
        // terminating condition we got the min
        if (a[mid] > a[mid + 1])
            return a[mid + 1];
        // if the mid element is lesser than its previous element then mid element is the smallest
        if (a[mid] < a[mid - 1])
            return a[mid];
        // if the mid elements value is greater than the 0th element this means
        // the least value is still somewhere to the right as we are still dealing with elements
        // greater than nums[0]
        if (a[mid] > a[0])
            lo = mid + 1;
        // if nums[0] is greater than the mid value then this means the smallest value is somewhere to the left
        else
            hi = mid - 1;
    }
    return -1;
}
int main()
{
    return 0;
}