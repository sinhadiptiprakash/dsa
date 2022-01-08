#include <bits/stdc++.h>
using namespace std;
//these versions of solution handles only the case when all the array elements are positive
/*
Algorithm:  
    1.Traverse the array from start to end.
    2.From every index start another loop from i to the end of array to get all subarray starting from i, keep a varibale sum to calculate the sum.
    3.For every index in inner loop update sum = sum + array[j]
    4.If the sum is equal to the given sum then print the subarray.
*/
/* Returns true if the there is a subarray
of arr[] with sum equal to 'sum' otherwise
returns false. Also, prints the result */
int subArray_with_given_sum(int arr[], int n, int sum)
{
    int curr_sum, i, j;
    // Pick a starting point
    for (i = 0; i < n; i++)
    {
        curr_sum = arr[i];
        // try all subarrays starting with 'i'
        for (j = i + 1; j <= n; j++)
        {
            if (curr_sum == sum)
            {
                cout << "Sum found between indexes "
                     << i << " and " << j - 1;
                return 1;
            }
            if (curr_sum > sum || j == n)
                break;
            curr_sum = curr_sum + arr[j];
        }
    }
    cout << "No subarray found";
    return 0;
} //time complexity O(N*N) space complexity O(1)
/*
Efficient Approach:
 There is an idea if all the elements of the array are positive. 
If a subarray has sum greater than the given sum then there is no possibility 
that adding elements to the current subarray the sum will be x (given sum). 
Idea is to use a similar approach to a sliding window. 
Start with an empty subarray, add elements to the subarray until the sum is less than x. 
If the sum is greater than x, remove elements from the start of the current subarray.

Algorithm:  
    1.Create three variables, l=0, sum = 0
    2.Traverse the array from start to end.
    3.Update the variable sum by adding current element, sum = sum + array[i]
    4.If the sum is greater than the given sum, update the variable sum as sum = sum – array[l],
         and update l as, l++.
    5.If the sum is equal to given sum, print the subarray and break the loop.
*/
/* Returns true if the there is a subarray of
arr[] with a sum equal to 'sum' otherwise
returns false. Also, prints the result */
int subArray_with_given_sum2(int arr[], int n, int sum)
{
    /* Initialize curr_sum as value of
    first element and starting point as 0 */
    int curr_sum = arr[0], start = 0, i;
    /* Add elements one by one to curr_sum and
    if the curr_sum exceeds the sum,
    then remove starting element */
    for (i = 1; i <= n; i++)
    {
        // If curr_sum exceeds the sum,
        // then remove the starting elements
        while (curr_sum > sum && start < i - 1)
        {
            curr_sum = curr_sum - arr[start];
            start++;
        }
        // If curr_sum becomes equal to sum,
        // then return true
        if (curr_sum == sum)
        {
            cout << "Sum found between indexes "
                 << start << " and " << i - 1;
            return 1;
        }
        // Add this element to curr_sum
        if (i < n)
            curr_sum = curr_sum + arr[i];
    }
    // If we reach here, then no subarray
    cout << "No subarray found";
    return 0;
} //time complexity O(N) and space complexity O(1)
int main()
{
    int arr[] = {15, 2, 4, 8, 9, 5, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 23;
    subArray_with_given_sum2(arr, n, sum);
    return 0;
}