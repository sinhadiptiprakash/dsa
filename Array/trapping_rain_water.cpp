#include <bits/stdc++.h>
using namespace std;
//watch the video trapping the rain water of take_u_forward channel
/*
Basic Insight: 
An element of the array can store water if there are higher bars on left and right
The amount of water to be stored in every element can be found out 
by finding the heights of bars on the left and right sides. 
The idea is to compute the amount of water that can be stored in every element of the array. 

Algorithm: 
1. Traverse the array from start to end.
2. For every element, traverse the array from start to that index and find the maximum height (a) and traverse the array from the current index to end and find the maximum height (b).
3. The amount of water that will be stored in this column is min(a,b) – array[i], add this value to total amount of water stored
4. Print the total amount of water stored.
*/
//below is the above basic brute force O(N*N) implementation
int trap_rain_water_bf(int arr[], int n)
{
    // To store the maximum water that can be stored
    int res = 0;
    // For every element of the array
    for (int i = 1; i < n - 1; i++)
    {
        // Find the maximum element on its left
        int left = arr[i];
        for (int j = 0; j < i; j++)
            left = max(left, arr[j]);
        // Find the maximum element on its right
        int right = arr[i];
        for (int j = i + 1; j < n; j++)
            right = max(right, arr[j]);
        // Update the maximum water
        res = res + (min(left, right) - arr[i]);
    }
    return res;
}
//To make the above approach efficient one must pre-compute the highest bar on the left and right of every bar in O(N)
/*
Algorithm: 
1. Create two array left and right of size n. create a variable max_ = INT_MIN.
2. Run one loop from start to end. In each iteration update max_ as max_ = max(max_, arr[i]) 
    and also assign left[i] = max_
3. Update max_ = INT_MIN.
4. Run another loop from end to start. In each iteration update max_ as max_ = max(max_, arr[i]) 
    and also assign right[i] = max_
5. Traverse the array from start to end.
6. The amount of water that will be stored in this column is 
    min(left[i],right[i]) – array[i],(where a = left[i] and b = right[i]) add this value to total amount of water stored
Print the total amount of water stored.
*/
//time complexity is O(N) space complexity is O(N)
int trap_rain_water2(int arr[], int n)
{
    // left[i] contains height of tallest bar to the
    // left of i'th bar including itself
    int left[n];
    // Right [i] contains height of tallest bar to
    // the right of ith bar including itself
    int right[n];
    // Initialize result
    int water = 0;
    // Fill left array
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
        left[i] = max(left[i - 1], arr[i]);
    // Fill right array
    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        right[i] = max(right[i + 1], arr[i]);
    // Calculate the accumulated water element by element
    // consider the amount of water on i'th bar, the
    // amount of water accumulated on this particular
    // bar will be equal to min(left[i], right[i]) - arr[i] .
    for (int i = 0; i < n; i++)
        water += min(left[i], right[i]) - arr[i];
    return water;
}
//below is the efficient approach using two-pointers and maintaining left_max, right_max named variables on-the-go
/*
Approach:
    start from the two extreme ends and maintain two max variables left_max and right_max 
    if the leftmost element is greater than the left_max then we update the left_max 
    otherwise we calculate water trapped by this very element surrounded by the left max
    and similerly for the right_max and rightmost pointer
time complexity is O(N) and space complexity is O(1) */
int trap_rain_water3(int arr[], int n)
{
    // initialize output
    int result = 0;
    // maximum element on left and right
    int left_max = 0, right_max = 0;
    // indices to traverse the array
    int low = 0, high = n - 1;
    while (low <= high)
    {
        if (arr[low] < arr[high])
        {
            if (arr[low] > left_max)
                // update max in left
                left_max = arr[low];
            else
                // water on curr element = max - curr
                result += left_max - arr[low];
            low++;
        }
        else
        {
            if (arr[high] > right_max)
                // update right maximum
                right_max = arr[high];
            else
                result += right_max - arr[high];
            high--;
        }
    }
    return result;
}
/*
Method 4 (Two Pointer Approach)

Approach:
 At every index, The amount of rain water stored is the difference between current index height and minimum of left max height and right max height

Algorithm :
    1. Take two pointers l and r . Initialise l to the starting index 0 and r to the last index n-1
    2. Since l is the first element , left_max would be 0 , and right max for r would be 0
    3. While l <= r , iterate the array . We have two possible conditions
        Condition1 : left_max <= right max
            Consider Element at index l
            Since we have traversed all elements tot the left of l , left_max is known 
            For right max of l , We can say that right max would  always be >= current r_max here
            So min(left_max,right_max) would always equal to left_max in this case
            Increment l
        Condition2 : left_max >  right max
            Consider Element at index r
            Since we have traversed all elements tot the right of r , right_max is known
            For left max of l , We can say that left max would  always be >= current l_max here
            So min(left_max,right_max) would always equal to right_max in this case
            Decrement r
*/
//below is the implementation of above two-pointer approach
int trap_rain_water4(int arr[], int n)
{
    // indices to traverse the array
    int left = 0;
    int right = n - 1;
    // To store Left max and right max
    // for two pointers left and right
    int l_max = 0;
    int r_max = 0;
    // To store the total amount
    // of rain water trapped
    int result = 0;
    while (left <= right)
    {
        // We need check for minimum of left
        // and right max for each element
        if (r_max <= l_max)
        {
            // Add the difference between
            // current value and right max at index r
            result += max(0, r_max - arr[right]);
            // Update right max
            r_max = max(r_max, arr[right]);
            // Update right pointer
            right -= 1;
        }
        else
        {
            // Add the difference between
            // current value and left max at index l
            result += max(0, l_max - arr[left]);
            // Update left max
            l_max = max(l_max, arr[left]);
            // Update left pointer
            left += 1;
        }
    }
    return result;
}
int main()
{
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int a[] = {2, 4, 1, 0, 5, 3, 2, 7, 5, 6};
    int n = sizeof(arr) / sizeof(int);
    int m = sizeof(a) / sizeof(int);
    cout << trap_rain_water4(a, m) << endl;
    return 0;
}