#include <bits/stdc++.h>
using namespace std;

long long int maximize_sum(long long int arr[], int n, int k)
{
    sort(arr, arr + n);
    int i = 0;
    while (k > 0)
    {
        if (i == n)
            i = n - 1;

        if (arr[i] == 0)
            k = 0;

        else
        {
            arr[i] = (-1) * arr[i];
            k--;
            if (arr[i + 1] < 0 || arr[i] > arr[i + 1])
                i++;
        }
    }
    long long int sum = 0;
    for (int j = 0; j < n; j++)
        sum += arr[j];
    return sum;
}
int main()
{
    long long int a[] = {5, -2, 5, -4, 5, -12, 5, 5, 5, 20};
    long long int b[] = {1, 2, 3, 4, 5};
    int n = sizeof(b) / sizeof(b[0]);
    int k = 5;
    cout << maximize_sum(b, n, k) << endl;
    return 0;
}