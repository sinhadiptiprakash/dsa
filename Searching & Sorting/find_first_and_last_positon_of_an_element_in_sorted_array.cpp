#include <bits/stdc++.h>
using namespace std;
int binary_search(int a[], int n, int target)
{
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (a[mid] == target)
            return mid;
        else if (a[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int first_occurence(int a[], int n, int target)
{
    int low = 0, high = n - 1, res = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] == target)
        {
            res = mid;
            high = mid - 1;
        }
        else if (a[mid] > target)
        {
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return res;
}

int last_occurence(int a[], int n, int target)
{
    int low = 0, high = n - 1, res = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] == target)
        {
            res = mid;
            //below is the difference in code from the above code
            low = mid + 1;
        }
        else if (a[mid] > target)
        {
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return res;
}

// now we can combine last and fist occurence code in a single function to avoid code rewritting
int find_occurence(int a[], int n, int target, bool first_occurence)
{
    int low = 0, high = n - 1, res = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] == target)
        {
            res = mid;
            // if we are required to find first occurence
            if (first_occurence)
                high = mid - 1;
            // if we are required to find last occurence
            else
                low = mid + 1;
        }
        else if (a[mid] > target)
        {
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return res;
}
int main()
{
    int a[] = {-3, -1, 0, 0, 0, 0, 4, 4, 5, 5, 7};
    int n = sizeof(a) / sizeof(int);
    sort(a, a + n);
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << endl;
    cout << find_occurence(a, n, 0, 0) << endl;
    return 0;
}