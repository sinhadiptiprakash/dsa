#include <bits/stdc++.h>
using namespace std;
/*
A simple solution is to use two nested loops.
The outer loop picks a starting element, 
the inner loop considers all elements (on right side of current start) as ending element. 
Whenever sum of elements between current start and end becomes more than the given number, 
update the result if current length is smaller than the smallest length so far. 
Following is the implementation of simple approach. 
*/
int smallestSubWithSum(int arr[], int n, int x)
{
    //  Initialize length of smallest subarray as n+1
    int min_len = n + 1;

    // Pick every element as starting point
    for (int start = 0; start < n; start++)
    {
        // Initialize sum starting with current start
        int curr_sum = arr[start];

        // If first element itself is greater
        if (curr_sum > x)
            return 1;

        // Try different ending points for curremt start
        for (int end = start + 1; end < n; end++)
        {
            // add last element to current sum
            curr_sum += arr[end];

            // If sum becomes more than x and length of
            // this subarray is smaller than current smallest
            // length, update the smallest length (or result)
            if (curr_sum > x && (end - start + 1) < min_len)
                min_len = (end - start + 1);
        }
    }
    return min_len;
} //time complexity O(N*N)
// Returns length of smallest subarray with sum greater than
// x. If there is no subarray with given sum, then returns
// n+1
int smallestSubWithSum(int arr[], int n, int x)
{
    // Initialize current sum and minimum length
    int curr_sum = 0, min_len = n + 1;

    // Initialize starting and ending indexes
    int start = 0, end = 0;
    while (end < n)
    {
        // Keep adding array elements while current sum
        // is smaller than or equal to x
        while (curr_sum <= x && end < n)
            curr_sum += arr[end++];

        // If current sum becomes greater than x.
        while (curr_sum > x && start < n)
        {
            // Update minimum length if needed
            if (end - start < min_len)
                min_len = end - start;

            // remove starting elements
            curr_sum -= arr[start++];
        }
    }
    return min_len;
}
int main()
{

    return 0;
}