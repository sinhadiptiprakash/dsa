#include <bits/stdc++.h>
using namespace std;
//using linear search
int magic_index_linear_search(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == i)
            return i;
    }
    return -1;
}
//using binary search as the array is sorted we should utilize this property
int magic_index_binary_search(int a[], int n)
{
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (a[mid] == mid)
            return mid;
        else if (a[mid] < mid)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int main()
{
    int a[] = {-10, -1, 0, 3, 10, 11, 30, 50, 100};
    int b[] = {1,2,3,4,4,6,8};
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);
    cout << magic_index_binary_search(b, m) << endl;
    return 0;
}