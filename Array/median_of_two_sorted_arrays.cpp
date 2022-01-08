#include <bits/stdc++.h>
using namespace std;
//using extra space of O(N+M) and merging the two sorted arrays and then find the median
// we will be using two pointers for merging the arrays
double median_of_two_sorted_arrays(int a[], int n, int b[], int m)
{
    int temp[n + m];
    int index = 0;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a[i] <= b[j])
            temp[index++] = a[i++];
        else
            temp[index++] = b[j++];
    }
    while (i < n)
    {
        temp[index++] = a[i++];
    }
    while (j < m)
    {
        temp[index++] = b[j++];
    }
    int mid = (n + m) / 2;
    if ((n + m) % 2 == 0)
        return (temp[mid] + temp[mid - 1]) / 2;
    else
        return temp[mid];
} //time complexity O(n+m) space complexity O(n+m)
//below is an better algorithm
/*
Algorithm: 

1.Given two arrays are sorted. So they can be merged in O(m+n) time. 
    Create a variable count to have a count of elements in the output array.
2. If the value of (m+n) is odd then there is only one median else the median 
    is the average of elements at index (m+n)/2 and ((m+n)/2 – 1).
3.To merge the both arrays, keep two indices i and j initially assigned to 0. 
    Compare the ith index of 1st array and jth index of second, increase the index of the smallest element and increase the count.
4.Check if the count reached (m+n) / 2 if (m+n) is odd and store the element, 
    if even store the average of (m+n)/2 th and (m+n)/2 -1 th element and print it.=
*/
double median_of_two_sorted_arrays2(int ar1[], int n, int ar2[], int m)
{
    int i = 0; /* Current index of input array ar1[] */
    int j = 0; /* Current index of input array ar2[] */
    int count;
    int m1 = -1, m2 = -1;
    // Since there are (n+m) elements,
    // There are following two cases
    // if n+m is odd then the middle
    //index is median i.e. (m+n)/2
    if ((m + n) % 2 == 1)
    {
        for (count = 0; count <= (n + m) / 2; count++)
        {
            if (i != n && j != m)
            {
                m1 = (ar1[i] > ar2[j]) ? ar2[j++] : ar1[i++];
            }
            else if (i < n)
            {
                m1 = ar1[i++];
            }
            // for case when j<m,
            else
            {
                m1 = ar2[j++];
            }
        }
        return m1;
    }

    // median will be average of elements
    // at index ((m+n)/2 - 1) and (m+n)/2
    // in the array obtained after merging ar1 and ar2
    else
    {
        for (count = 0; count <= (n + m) / 2; count++)
        {
            m2 = m1;
            if (i != n && j != m)
            {
                m1 = (ar1[i] > ar2[j]) ? ar2[j++] : ar1[i++];
            }
            else if (i < n)
            {
                m1 = ar1[i++];
            }
            // for case when j<m,
            else
            {
                m1 = ar2[j++];
            }
        }
        return (m1 + m2) / 2;
    }
} //time complexity O(n+m) and space complexity O(1)
//below is the efficent algorithm using D&C and binary search
//for understanding the below code watch the video of take_u_forward's video
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    // we always select small array as the nums1
    if (nums2.size() < nums1.size())
        return findMedianSortedArrays(nums2, nums1);
    // getting the sizes of the arrays
    int n1 = nums1.size();
    int n2 = nums2.size();
    // low and high are for the indexing needed for binary_search like operation
    int low = 0, high = n1;

    while (low <= high)
    {
        //we cut the nums1 at cut1
        int cut1 = (low + high) >> 1;
        // we cut the nums2 at cut2
        int cut2 = (n1 + n2 + 1) / 2 - cut1;

        // left1 is the rightMost element of left array of nums1 after cutting nums1 at cut1
        // left2 is the rightMost element of left array of nums2 after cutting nums2 at cut2

        //if we are cutting the nums1 at 0 i.e. we don't consider no elements of nums1
        //we should make left1 equal to INT_MIN for the correct operation VVI point
        //same for left2
        int left1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
        int left2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];

        // right1 is the leftMost element of right array of nums1 after cutting nums1 at cut1
        // right2 is the leftMost element of right array of nums2 after cutting nums2 at cut2

        //if we are cutting the nums1 at n1 i.e. we don't consider all elements of nums1
        //we should make right1 equal to INT_MAX for the correct operation VVI point
        //same for left2
        int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
        int right2 = cut2 == n2 ? INT_MAX : nums2[cut2];

        // we compare in cross i.e. diagonally
        if (left1 <= right2 && left2 <= right1)
        {                           //i.e. we have reached the condition where we have n/2 smaller elements in the left side
            if ((n1 + n2) % 2 == 0) //if the total size is even then we have two medians
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            else //else the median is the maximum of the leftmost elements
                return max(left1, left2);
        }
        else if (left1 > right2)
        { //we have to consider more elemets from the nums2 array
            high = cut1 - 1;
        }
        else
        { //we have to consider more elements from the nums1 array
            low = cut1 + 1;
        }
    }
    return 0.0;
}
int main()
{
    int ar1[] = {1, 12, 15, 26, 38};
    int ar2[] = {2, 13, 17, 30, 45};
    int n1 = sizeof(ar1) / sizeof(ar1[0]);
    int n2 = sizeof(ar2) / sizeof(ar2[0]);
    cout << median_of_two_sorted_arrays(ar1, n1, ar2, n2) << endl;
    return 0;
}