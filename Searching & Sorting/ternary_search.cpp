#include <bits/stdc++.h>
using namespace std;
//condition is like binary search the array is to be sorted
int ternary_search(int a[], int n, int target)
{
    int low = 0, high = n - 1, mid1, mid2;
    while (low <= high)
    {
        //dividing the array into 3 parts: part1[0...mid1], part2[mid1+1....mid2],part3[mid2+1...n]
        mid1 = low + (high - low) / 3;
        mid2 = high - (high - low) / 3;
        //if we get the target at mid1 return it
        if (a[mid1] == target)
            return mid1;
        //if we get the target at mid2 return it
        if (a[mid2] == target)
            return mid2;
        // if the target is less than a[mid1] that means the target lies in the left side of the mid1
        if (a[mid1] > target)
            high = mid1 - 1;
        // if the target is greater than a[mid2] that means the target lies in the right side of the mid2
        else if (a[mid2] < target)
            low = mid2 + 1;
        // else the target lies between mid1 and mid2
        else
        {
            low = mid1 + 1;
            high = mid2 - 1;
        }
    }
    return -1;
} //time complexity O(log3(n)) space complexity O(1)
int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(a) / sizeof(int);
    cout << ternary_search(a, n, 0) << endl;
    return 0;
}