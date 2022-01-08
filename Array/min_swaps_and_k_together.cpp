#include <bits/stdc++.h>
using namespace std;
/*
A simple solution is to first count all elements less than or equals to k(say ‘good’). 
Now traverse for every sub-array and swap those elements whose value is greater than k. 
Time complexity of this approach is O(N*N)

A simple approach is to use two pointer technique and sliding window.

1. Find count of all elements which are less than or equals to ‘k’. Let’s say the count is ‘cnt’
2. Using two pointer technique for window of length ‘cnt’, each time keep track of how many elements in this range are greater than ‘k’. 
    Let’s say the total count is ‘bad’.
3. Repeat step 2, for every window of length ‘cnt’ and take minimum of count ‘bad’ among them. 
    This will be the final answer.
*/
//below is the implementation of above approach
int min_swaps(int *arr, int n, int k)
{
    // Find count of elements which are less than equals to k
    int good = 0;
    for (int i = 0; i < n; ++i)
        if (arr[i] <= k)
            ++good;

    // Find unwanted elements in current window of size 'count'
    int bad = 0;
    for (int i = 0; i < good; ++i)
        if (arr[i] > k)
            ++bad;

    // Initialize answer with 'bad' value of current window
    int ans = bad;
    for (int i = 0, j = good; j < n; ++i, ++j)
    {

        // Decrement count of previous window
        if (arr[i] > k)
            --bad;

        // Increment count of current window
        if (arr[j] > k)
            ++bad;

        // Update ans if count of 'bad' is less in current window
        ans = min(ans, bad);
    }
    return ans;
}
int main()
{
    int arr[] = {2, 7, 9, 5, 4, 3, 8, 7, 4};
    int arr2[] = {20, 12, 17};
    int n = sizeof(arr2) / sizeof(int);
    int k = 6;
    cout << min_swaps(arr2, n, k) << endl;
    return 0;
}