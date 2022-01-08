#include <bits/stdc++.h>
using namespace std;
//brute force approach
bool triplet_with_given_sum(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == x)
                {
                    // printing the triplet
                    cout << arr[i] << ' ' << arr[j] << ' ' << arr[k] << endl;
                    return true;
                }
            }
        }
    }
    return false;
} //time complexity O(N*N*N)
//method:2
// Algorithm :
// Sort the given array.
// Loop over the array and fix the first element of the possible triplet, arr[i].
// Then fix two pointers, one at i + 1 and the other at n – 1. And look at the sum,
// If the sum is smaller than the required sum, increment the first pointer.
// Else, If the sum is bigger, Decrease the end pointer to reduce the sum.
// Else, if the sum of elements at two-pointer is equal to given sum then print the triplet and break.
bool find_triplet_with_given_sum_efficient(int a[], int n, int sum)
{
    sort(a, a + n);
    //choosing array elements one by one and by two pointer approach find the other two elements
    int left, right;
    for (int i = 0; i < n - 2; i++)
    {
        //we search other two elements in the range i+1....n
        left = i + 1, right = n - 1;
        // we find the triplet
        while (left < right)
        {
            if (a[left] + a[right] == sum - a[i])
            {
                //printing the triplets
                cout << a[i] << ' ' << a[left] << ' ' << a[right] << endl;
                return true;
            }
            else if (a[left] + a[right] < sum - a[i])
                left++;
            else if (a[left] + a[right] > sum - a[i])
                right--;
        }
    }
    //if we reach here then i.e. we got no triplet
    return false;
} // time complexity O(N*N), space complexity O(1)
//method 3 same as above but to find the other two of the triplet we use hashing instead of two-pointers
// Algorithm:
// 1.Traverse the array from start to end. (loop counter i)
// 2.Create a HashMap or set to store unique pairs.
// 3.Run another loop from i+1 to end of the array. (loop counter j)
// 4.If there is an element in the set which is equal to x- arr[i] – arr[j], then print the triplet (arr[i], arr[j], x-arr[i]-arr[j]) and break
// 5.Insert the jth element in the set.
bool triplet_with_given_sum_hashing(int a[], int n, int sum)
{
    // Fix the first element as A[i]
    for (int i = 0; i < n - 2; i++)
    {
        // Find pair in subarray A[i+1..n-1]
        // with sum equal to sum - A[i]
        unordered_set<int> s;
        int curr_sum = sum - a[i];
        for (int j = i + 1; j < n; j++)
        {
            if (s.find(curr_sum - a[j]) != s.end())
            {
                //printing the triplet
                cout << a[i] << ' ' << a[j] << ' ' << curr_sum - a[j] << endl;
                return true;
            }
            s.insert(a[j]);
        }
    }
    // If we reach here, then no triplet was found
    return false;
} //time complexity O(N*N) space complexity O(N)
int main()
{
    int arr[] = {1, 2, 4, 3, 6};
    int n = sizeof(arr) / sizeof(int);
    cout << triplet_with_given_sum_hashing(arr, n, 10) << endl;
    return 0;
}