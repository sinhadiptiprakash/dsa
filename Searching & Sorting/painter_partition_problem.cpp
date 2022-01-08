#include <bits/stdc++.h>
using namespace std;
//This problem is similar to the book allocation problem but in this file it will be solved using recursion and dp
/*
A brute force solution is to consider all possible set of contiguous partitions and calculate the maximum sum partition in each case 
and return the minimum of all these cases. 
*/
//below is the recursive implementation
int get_sum(int a[], int from, int to)
{
    int sum = 0;
    for (int i = from; i <= to; i++)
        sum += a[i];
    return sum;
}
int partition(int a[], int n, int k)
{
    if (k == 1)
        return get_sum(a, 0, n - 1);
    if (n == 1)
        return a[0];
    int res = INT_MAX;
    //we take ith to n-1 elements as a last partition and call recursively with k-1 painters and i elements
    for (int i = 1; i <= n; i++)
    {
        res = min(res, max(partition(a, i, k - 1), get_sum(a, i, n - 1)));
    }
    return res;
} //time complexity O(2^n)
//as the recursive calls have overlapping subproblems we can use dp to optimize the solution
int partition_bottom_up(int a[], int n, int k)
{
    int dp[k + 1][n + 1] = {0};

    // base cases
    // k=1
    for (int i = 1; i <= n; i++)
        dp[1][i] = get_sum(a, 0, i - 1);

    // n=1
    for (int i = 1; i <= k; i++)
        dp[i][1] = a[0];

    // 2 to k partitions
    for (int i = 2; i <= k; i++)
    { // 2 to n boards
        for (int j = 2; j <= n; j++)
        {

            // track minimum
            int best = INT_MAX;

            // i-1 th separator before position arr[p=1..j]
            for (int p = 1; p <= j; p++)
                best = min(best, max(dp[i - 1][p],
                                     get_sum(a, p, j - 1)));

            dp[i][j] = best;
        }
    }

    // required
    return dp[k][n];
} //time complexity O(k*N^3),space complexity O(N^2)
//we can further optimize it by using precomputing the sum for computing the sum in O(1) but that will require O(N) extra space
int partition_bottom_up_optimal(int a[], int n, int k)
{
    int dp[k + 1][n + 1] = {0};
    // precomputation of sum is one optimization
    int sum[n + 1] = {0};
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i - 1];

    // base cases
    // k=1
    // here we using precomputation of sum to handle the base case
    for (int i = 1; i <= n; i++)
        dp[1][i] = sum[i];

    // n=1
    for (int i = 1; i <= k; i++)
        dp[i][1] = a[0];

    // 2 to k partitions
    for (int i = 2; i <= k; i++)
    { // 2 to n boards
        for (int j = 2; j <= n; j++)
        {

            // track minimum
            int best = INT_MAX;

            // i-1 th separator before position arr[p=1..j]
            for (int p = 1; p <= j; p++)
                best = min(best, max(dp[i - 1][p],
                                     get_sum(a, p, j - 1)));

            dp[i][j] = best;
        }
    }

    // required
    return dp[k][n];
} //time complexity O(k*N^2) space complexity O(N^2 + N)

// using binary search like Book Allocation
bool isPossible(int a[], int n, int k, long long cost)
{
    long long sum = 0, alloted = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum + a[i] > cost)
        {
            sum = a[i];
            alloted++;
        }
        else if (a[i] > cost)
            return false;
        else
            sum += a[i];
    }
    return alloted < k;
}
long long minTime(int arr[], int n, int k)
{
    long long low = *max_element(arr, arr + n), high = 0, mid;
    for (int i = 0; i < n; i++)
        high += arr[i];
    long long ans = 0LL;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (isPossible(arr, n, k, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}
int main()
{
    int arr[] = {10, 20, 60, 50, 30, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    cout << partition(arr, n, k) << endl;
    return 0;
}