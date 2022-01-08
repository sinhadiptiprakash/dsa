#include <bits/stdc++.h>
using namespace std;
//below is the approach for merging two sorted arrays simply by merge-sort technique using extra space
void merge_two_sorted_arrays_with_extra_space(int a[], int n, int b[], int m)
{
    vector<int> merged_array(n + m);
    int i = 0, j = 0, index = 0;
    while (i < n && j < m)
    {
        if (a[i] <= b[j])
        {
            merged_array[index++] = a[i];
            i++;
        }
        else
        {
            merged_array[index++] = b[j];
            j++;
        }
    }
    while (i < n)
    {
        merged_array[index++] = a[i];
        i++;
    }
    while (j < m)
    {
        merged_array[index++] = b[j];
        j++;
    }
    //putting the sorted elements back to the arrays one by one
    i = 0;
    for (i; i < n; i++)
    {
        a[i] = merged_array[i];
    }
    for (; i < n + m; i++)
    {
        b[i - n] = merged_array[i];
    }
} //time complexity O(n+m) space complexity O(n+m)

//below is the approach of merging two sorted arrays without using extra space using insertion sort approach
// Function to in-place merge two sorted arrays X[] and Y[]
// invariant: `X[]` and `Y[]` are sorted at any point
//for better understand visit https://www.techiedelight.com/inplace-merge-two-sorted-arrays/
void merge_two_sorted_arrays_without_extra_space(int X[], int Y[], int m, int n)
{
    // Consider each element `X[i]` of array `X` and ignore the element if it is
    // already in the correct order; otherwise, swap it with the next smaller
    // element, which happens to be the first element of `Y`.
    for (int i = 0; i < m; i++)
    {
        // compare the current element of `X[]` with the first element of `Y[]`
        if (X[i] > Y[0])
        {
            swap(X[i], Y[0]);
            int first = Y[0];

            // move `Y[0]` to its correct position to maintain the sorted
            // order of `Y[]`. Note: `Y[1…n-1]` is already sorted
            int k;
            for (k = 1; k < n && Y[k] < first; k++)
            {
                Y[k - 1] = Y[k];
            }
            Y[k - 1] = first;
        }
    }
} //time complexity is O(m*n) and space complexity is O(1)

//below is the efficient algorithm using GAP method that has time complexity of O(NlogN) and space complexity of O(1)
// Function to find next gap.
// each time we divide the gap and take the ceil of the result until it is 1
// initially the gap would be ceil(n+m/2)
int nextGap(int gap)
{
    if (gap <= 1)
        return 0;
    return (gap / 2) + (gap % 2);
}
void merge_two_sorted_arrays_without_extra_space_efficient(int a[], int b[], int n, int m)
{
    int i, j, gap = n + m;
    //until the gap is 0 we always compare two gap distanced element and if first is greater then we swap them
    //obviously until the two pointers are within the array index
    //i.e. if one pointer is at i then the another pointer would be i+gap
    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap))
    { //this runs in O(long(n+m))
        // comparing elements in the first array.
        // while the second pointer i.e. the pointer at i+gap is within the range of n
        for (i = 0; i + gap < n; i++)
            if (a[i] > a[i + gap])
                swap(a[i], a[i + gap]);

        // comparing elements in both arrays.
        // while the second poiner i.e. pointer at i+gap is within the range of n to m but the first pointer is within the range n
        for (j = gap > n ? gap - n : 0; i < n && j < m; i++, j++)
            if (a[i] > b[j])
                swap(a[i], b[j]);
        //while the first pointer is out of n and the second pointer is within m
        if (j < m)
        {
            // comparing elements in the second array.
            for (j = 0; j + gap < m; j++)
                if (b[j] > b[j + gap])
                    swap(b[j], b[j + gap]);
        }
    }
} // for better understanding visit https://www.geeksforgeeks.org/efficiently-merging-two-sorted-arrays-with-o1-extra-space/
int main()
{
    int a[] = {1, 3, 5, 7};
    int b[] = {0, 2, 6, 8, 9};
    int n = sizeof(a) / sizeof(int);
    int m = sizeof(b) / sizeof(int);
    sort(a, a + n);
    sort(b, b + m);
    merge_two_sorted_arrays_without_extra_space_efficient(a, b, n, m);
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << endl;
    for (int i = 0; i < m; i++)
        cout << b[i] << ' ';
    cout << endl;
    return 0;
}