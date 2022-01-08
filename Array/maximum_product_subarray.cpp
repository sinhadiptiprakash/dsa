#include <bits/stdc++.h>
using namespace std;
long long max(const long long &a, const long long &b)
{
    if (a >= b)
        return a;
    return b;
}
long long min(const long long &a, const long long &b)
{
    if (a <= b)
        return a;
    return b;
}
// using kadane's algorithm
long long maximum_product_subarray(int a[], int n)
{
    long long global_max, local_max, local_min, tmp;
    global_max = local_max = local_min = a[0];
    for (int i = 1; i < n; i++)
    {
        tmp = local_max;
        local_max = max(max(local_max * a[i], a[i]), local_min * a[i]);
        local_min = min(min(local_min * a[i], a[i]), tmp * a[i]);
        global_max = max(global_max, local_max);
    }
    return global_max;
}
int main()
{
    int a[] = {6, -3, -10, 0, 2};
    int c[] = {2, 3, 4, 5, -1, 0};
    int b[] = {-2, 0, -1};
    int n = sizeof(a) / sizeof(int);
    cout << maximum_product_subarray(c, 6) << endl;
    return 0;
}