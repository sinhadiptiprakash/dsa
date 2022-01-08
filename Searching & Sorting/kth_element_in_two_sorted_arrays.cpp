#include <bits/stdc++.h>
using namespace std;
//below is the approach using meerging two sorted arrays
int kth_in_sorted_arrays(int arr1[], int arr2[], int n, int m, int k)
{
    int cnt = 0;
    int pointer1 = 0, pointer2 = 0;
    while (pointer1 < n && pointer2 < m)
    {
        //if the count is k we should return the min element at pointer1 and pointer2 as min element increases the cnt
        cnt++;
        if (cnt == k)
            return min(arr1[pointer1], arr2[pointer2]);
        if (arr1[pointer1] <= arr2[pointer2])
            pointer1++;
        else
            pointer2++;
    }
    while (pointer1 < n)
    {
        cnt++;
        if (cnt == k)
            return arr1[pointer1];
        pointer1++;
    }
    while (pointer2 < m)
    {
        cnt++;
        if (cnt == k)
            return arr2[pointer2];
        pointer2++;
    }
    return -1;
} //time complexity O(k) space O(1)

//this logic is similar to the median of two sorted array using binary search, watch take_u_forward
int kth_in_two_sorted_arrays_efficient(int arr1[], int arr2[], int n, int m, int k)
{
    //as we are doing binary search and the our low,high, and cut1 which is the middle is in the first array
    //so to reduce the search space of the binary search algo we should always choose first array as the search space
    if (n > m)
    {
        return kth_in_two_sorted_arrays_efficient(arr2, arr1, m, n, k);
    }
    //edge cases:
    //if the k is greater than m then we cant choose element less than k-m elements from arr1
    //similarly if k is greater then n we cant choose more than n elements from arr1
    int low = max(0, k - m), high = min(k, n);

    while (low <= high)
    {
        //cut1 is mid in binary_search
        //we are taking cut1 elements from the first array
        int cut1 = (low + high) >> 1;
        //since we have taken cut1 elements from arr1 we should now take k-cut1 elements from arr2
        int cut2 = k - cut1;
        //some other edge cases same as solution for the problem median of two sorted arrays
        int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];
        int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
        int r1 = cut1 == n ? INT_MAX : arr1[cut1];
        int r2 = cut2 == m ? INT_MAX : arr2[cut2];

        //we have k elements all are smaller than the right half of the arr1 and arr2
        if (l1 <= r2 && l2 <= r1)
        {
            return max(l1, l2);
        }
        //we should choose more elements from the second array
        else if (l1 > r2)
        {
            high = cut1 - 1;
        }
        //we should choose more elements from the first array
        else
        {
            low = cut1 + 1;
        }
    }
    return 1;
} //time complexity O(log(min(n,m))) space complexity O(1)

int main()
{
    int arr1[] = {1, 10, 10, 25, 40, 54, 79};
    int arr2[] = {15, 24, 27, 32, 33, 39, 48, 68, 82, 88, 90};
    int n = sizeof(arr1) / sizeof(int);
    int m = sizeof(arr2) / sizeof(int);

    cout << kth_in_two_sorted_arrays_efficient(arr1, arr2, n, m, 15) << endl;
    return 0;
}