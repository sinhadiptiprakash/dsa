#include <bits/stdc++.h>
using namespace std;
int missing_number_linear_search(int a[], int n)
{
    //first of all find out the common difference , we are dividing by n because in the sequence there are actually n+1 numbers as 1 is missing
    int common_dif = (a[n - 1] - a[0]) / n;
    //now traverse the array linearly
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i + 1] - a[i] != common_dif)
            return a[i] + common_dif;
    }
    return -1;
} //time complexity O(N) space complexity O(1)

/*
We can solve this problem in O(Logn) time using Binary Search. The idea is to go to the middle element. 
Check if the difference between middle and next to middle is equal to diff or not, 
if not then the missing element lies between mid and mid+1. 
If the middle element is equal to n/2th term in Arithmetic Series (Let n be the number of elements in input array), 
then missing element lies in right half. Else element lies in left half.
Following is implementation of above idea. 
*/
int missing_number_binary_search(int a[], int n)
{
    //first find out the common diff
    int common_dif = (a[n - 1] - a[0]) / n;
    //now apply binary search
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        //the element just after the mid element is missing so we should return a[mid]+commmon_dif
        if (a[mid + 1] - a[mid] != common_dif)
        {
            return a[mid] + common_dif;
        }
        //the element just before mid is missing
        else if (mid > 0 && a[mid] - a[mid - 1] != common_dif)
        {
            return a[mid - 1] + common_dif;
        }
        // If the elements till mid follow AP, then recur for right half
        else if (a[mid] == a[0] + mid * common_dif)
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return -1;
}
int main()
{
    int a[] = {1, -3, -7, -11, -19};
    int n = sizeof(a) / sizeof(int);
    cout << missing_number_binary_search(a, n) << endl;
    return 0;
}