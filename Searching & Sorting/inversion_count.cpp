#include <bits/stdc++.h>
using namespace std;
//brute force approach is to traverse the whole array in nested loop and for each element in the array count the inversion
//but that would be O(N^2)
//below is the merge sort approach
int merge(int a[], int left, int mid, int right, int temp[])
{
    int inversion_count = 0;
    int i = left, j = mid;
    int temp_index = left;
    while (i <= mid - 1 && j <= right)
    {
        if (a[i] <= a[j])
        {
            temp[temp_index++] = a[i++];
        }
        else
        {
            inversion_count += (mid - i);
            temp[temp_index++] = a[j++];
        }
    }
    while (i <= mid - 1)
    {
        temp[temp_index++] = a[i++];
    }
    while (j <= right)
    {
        temp[temp_index++] = a[j++];
    }
    //copying back the sorted temp array[i,j] to the the original array
    for (int i = left; i <= right; i++)
    {
        a[i] = temp[i];
    }
    return inversion_count;
}
int count_inversion(int a[], int left, int right, int temp[])
{
    int mid, inversions = 0;
    if (left < right)
    {
        mid = left + (right - left) / 2;
        inversions += count_inversion(a, left, mid, temp);
        inversions += count_inversion(a, mid + 1, right, temp);
        inversions += merge(a, left, mid + 1, right, temp);
    }
    return inversions;
}
int inversion_count_using_merge_sort(int a[], int n)
{
    int *temp = new int[n];
    int count = count_inversion(a, 0, n - 1, temp);
    delete (temp);
    return count;
}
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << inversion_count_using_merge_sort(a, n) << endl;
    delete (a);
    return 0;
}