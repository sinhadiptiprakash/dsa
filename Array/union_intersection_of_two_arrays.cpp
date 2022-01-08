#include <bits/stdc++.h>
using namespace std;

//below the union and intersection function uses two pointer approach
void union_of_two_sorted_array(int a[], int n, int b[], int m)
{
    //last is for storing the last printed element to avoid duplicates in the result
    int i = 0, j = 0, last = -1;
    //while loop runs length of the min(m,n)
    while (i < n && j < m)
    {
        //if both a[i] and b[j] are same
        if (a[i] == b[j])
        {
            //if a[i] or b[j] is not printed yet we print one of them and increase both i,j
            if (a[i] != last)
            {
                cout << a[i] << ' ';
                //update last
                last = a[i];
            }
            //else we ignore them by increasing i,j
            i++, j++;
        }
        //a[i] less than b[j]
        else if (a[i] < b[j])
        {
            //if a[i] is not printed yet we print it and update last and increase only i
            if (a[i] != last)
            {
                cout << a[i] << ' ';
                last = a[i];
            }
            //else we ignore it
            i++;
        }
        else if (a[i] > b[j])
        {
            //if b[j] is not printed yet we print it and update last and increase j only
            if (b[j] != last)
            {
                cout << b[j] << ' ';
                last = b[j];
            }
            //otherwise we ignore it
            j++;
        }
    }
    //if some of the elements are not processed yet from one of the array we print all of them
    while (i < n)
    {
        cout << a[i++] << ' ';
    }
    while (j < m)
    {
        cout << b[j++] << ' ';
    }
} //time complexity O(N)

void intersection_of_two_sorted_array(int a[], int n, int b[], int m)
{
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (a[i] < b[j])
            i++;
        else if (b[j] < a[i])
            j++;
        else /* if arr1[i] == arr2[j] */
        {
            printf("%d ", b[j++]);
            i++;
        }
    }
} //time complexity O(N)

int main()
{
    int a[] = {2, 3, 4, 5, 6, 1, 2};
    int b[] = {2, 3, 8, 9, 0, 3, 4};
    int n = sizeof(a) / sizeof(int);
    int m = sizeof(b) / sizeof(int);
    sort(a, a + n);
    sort(b, b + m);
    union_of_two_sorted_array(a, n, b, m);

    return 0;
}