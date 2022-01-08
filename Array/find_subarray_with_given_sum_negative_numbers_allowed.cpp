#include <bits/stdc++.h>
using namespace std;
/*
Algorithm:
1. create a Hashmap (hm) to store key value pair, i.e, key = prefix sum and value = its index 
    and a variable to store the current sum (sum = 0) and the sum of subarray as s
2. Traverse through the array from start to end.
3.For every element update the sum, i.e sum = sum + array[i]
4. If sum is equal to s then print that the subarray with given sum is from 0 to i
5. If there is any key in the HashMap which is equal to sum – s 
    then print that the subarray with given sum is from hm[sum – s] to i
6. Put the sum and index in the hashmap as key-value pair.
*/
// below is the implementation of above approach below function returns left and right index of the subarray
pair<int, int> subarray_with_given_sum_with_negatives(int arr[], int n, int sum)
{
    unordered_map<int, int> prefix_sum;
    int cur_sum = 0;
    for (int i = 0; i < n; i++)
    {
        cur_sum += arr[i];
        // if the cur_sum is equal to the sum then we got a subarray with given sum
        if (cur_sum == sum)
            return {0, i};
        // if cur_sum-sum is already in the hash_map that means there is a subarray with given sum
        if (prefix_sum.find(cur_sum - sum) != prefix_sum.end())
            return {prefix_sum[cur_sum - sum] + 1, i};
        //storing the cur_sum in prefix_sum with key as cur_sum and value as cur index
        prefix_sum[cur_sum] = i;
    }
    //did'nt find any subarrays with given sum
    return {-1, -1};
} //time complexity O(N) space complexity is O(N)

/*
an approach without using any extra space is discussed.
The idea is to modify the array to contain only positive elements: 

Find the smallest negative element in the array 
and increment every value in the array by the absolute value of the smallest negative element found.
We may notice that after doing the above modification, the sum of every subarray will also increase by: 
    (number of elements in the subarray) * (absolute value of min element)
After, doing the above modification in the input array, 
the task reduces to find if there is any subarray in the given array of only positive numbers with the new target sum. 
This can be done using the sliding window technique in O(N) time and constant space. 
Every time while adding elements to the window, increment the target sum by the absolute value of the minimum element 
and similarily while removing elements from the current window, 
decrement the target sum by the absolute value of the minimum element so that for every subarray of length say K, 
the updated target sum will be: 
    targetSum = sum + K*abs(minimum element)
Below is the approach for the same: 
    Initialize a variable curr_sum as the first element.
    The variable curr_sum indicates the sum of the current subarray.
    Start from the second element and add all elements one by one to the curr_sum, and keep incrementing target sum by abs(minimum element).
    If curr_sum becomes equal to the target sum, then print the solution.
    If curr_sum exceeds the sum, then remove trailing elements while curr_sum is greater than the sum and keep decrementing target sum by abs(minimum element).
Below is the implementation of the above approach: 
*/
pair<int, int> subarray_with_given_sum_with_negatives2(int arr[], int n, int sum)
{
    int minEle = INT_MAX;
    // Find minimum element in the array
    for (int i = 0; i < n; i++)
        minEle = min(arr[i], minEle);
    // Initialize curr_sum as value of first element
    // and starting point as 0
    int curr_sum = arr[0] + abs(minEle), start = 0, i;
    // Starting window length will be 1,
    // For generating new target sum,
    // add abs(minEle) to sum only 1 time
    int targetSum = sum;
    // Add elements one by one to curr_sum
    // and if the curr_sum exceeds the
    // updated sum, then remove starting element
    for (i = 1; i <= n; i++)
    {
        // If curr_sum exceeds the sum,
        // then remove the starting elements
        while (curr_sum - (i - start) * abs(minEle) > targetSum && start < i)
        {
            curr_sum = curr_sum - arr[start] - abs(minEle);
            start++;
        }
        // If curr_sum becomes equal to sum, then return true
        if (curr_sum - (i - start) * abs(minEle) == targetSum)
        {
            return {start, i - 1};
        }
        // Add this element to curr_sum
        if (i < n)
        {
            curr_sum = curr_sum + arr[i] + abs(minEle);
        }
    }
    //nothing found
    return {-1, -1};
}
int main()
{
    int arr[] = {1, 4, 20, -3, 3, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 30;
    pair<int, int> res = subarray_with_given_sum_with_negatives2(arr, n, sum);
    cout << res.first << ' ' << res.second << endl;
    return 0;
}