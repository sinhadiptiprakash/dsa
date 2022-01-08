#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define speedio                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
const int mod = 1e9 + 7;
//sorts the given array with only 0 1 2 elements without using any sorting algo
//by counting the occurences of 0,1,2 time complexity: O(n)
void sorting_0_1_2(int a[], int n)
{
    //we will first count the occurences of zero one and 2 after that we put them accordingly in the array
    int zero = 0, one = 0, two = 0;
    //counting
    for (int i = 0; i < n; i++)
    {
        switch (a[i])
        {
        case 0:
            zero++;
            break;
        case 1:
            one++;
            break;
        case 2:
            two++;
            break;
        }
    }
    //filling the array
    int index = 0;
    //filling with 0
    while (zero--)
    {
        a[index++] = 0;
    }
    //filling with 1
    while (one--)
    {
        a[index++] = 1;
    }
    //filling with 2
    while (two--)
    {
        a[index++] = 2;
    }
}
//sorting on the go
// Approach:The problem is similar to the Segregate 0s and 1s in an array, and both of these problems are variation of famous Dutch national flag problem.
// The problem was posed with three colours, here `0′, `1′ and `2′. The array is divided into four sections:
// a[1..Lo-1] zeroes (red)
// a[Lo..Mid-1] ones (white)
// a[Mid..Hi] unknown
// a[Hi+1..N] twos (blue)
// If the ith element is 0 then swap the element to the low range, thus shrinking the unknown range.
// Similarly, if the element is 1 then keep it as it is but shrink the unknown range.
// If the element is 2 then swap it with an element in high range.
void sort012(int a[], int arr_size)
{
    int lo = 0;
    int hi = arr_size - 1;
    int mid = 0;

    // Iterate till all the elements are sorted
    while (mid <= hi)
    {
        switch (a[mid])
        {

        // If the element is 0
        case 0:
            swap(a[lo++], a[mid++]);
            break;

        // If the element is 1 .
        case 1:
            mid++;
            break;

        // If the element is 2
        case 2:
            swap(a[mid], a[hi--]);
            break;
        }
    }
}

void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
int main()
{
    int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int n = sizeof(arr) / sizeof(int);
    sort012(arr, n);
    print(arr, n);
    return 0;
}