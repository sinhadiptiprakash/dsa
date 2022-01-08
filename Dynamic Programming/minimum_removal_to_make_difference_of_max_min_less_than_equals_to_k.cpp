#include <bits/stdc++.h>
using namespace std;
// Approach: first sort the given array then we will have to remove either the leftmost or rightmost element
// and then again check the diffrence between max and min, wheather dif<=k
// so in every decision there will be two choices either remove the leftMost or rightMost element
// recursive solution
int minimumRemoval(int a[], int i, int j, int k)
{
    if (i >= j)
        return 0;
    if (a[j] - a[i] <= k)
        return 0;
    return 1 + min(minimumRemoval(a, i + 1, j, k), minimumRemoval(a, i, j - 1, k));
}
//it can possible to do top down dp, that has time complexiy O(N^2) space complexity O(N^2)
// To sort the array and return the answer
int minRemovals(int arr[], int n, int k)
{
    // sort the array
    sort(arr, arr + n);
    int dp[n];

    // fill all stated with -1 when only one element
    for (int i = 0; i < n; i++)
        dp[i] = -1;

    // as dp[0] = 0 (base case) so min no of elements to be removed are n-1 elements
    int ans = n - 1;
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        dp[i] = i;
        int j = dp[i - 1];
        while (j != i && arr[i] - arr[j] > k)
        {
            j++;
        }
        dp[i] = min(dp[i], j);
        ans = min(ans, (n - (i - j + 1)));
    }
    return ans;
}
int findInd(int key, int i,
            int n, int k, int arr[])
{
    int start, end, mid, ind = -1;

    // Initialising start to i + 1
    start = i + 1;

    // Initialising end to n - 1
    end = n - 1;

    // Binary search implementation
    // to find the rightmost element
    // that satisfy the condition
    while (start < end)
    {
        mid = start + (end - start) / 2;

        // Check if the condition satisfies
        if (arr[mid] - key <= k)
        {

            // Store the position
            ind = mid;

            // Make start = mid + 1
            start = mid + 1;
        }
        else
        {
            // Make end = mid
            end = mid;
        }
    }

    // Return the rightmost position
    return ind;
}

// Function to calculate
// minimum number of elements
// to be removed
int removals(int arr[], int n, int k)
{
    int i, j, ans = n - 1;

    // Sort the given array
    sort(arr, arr + n);

    // Iterate from 0 to n-1
    for (i = 0; i < n; i++)
    {

        // Find j such that
        // arr[j] - arr[i] <= k
        j = findInd(arr[i], i, n, k, arr);

        // If there exist such j
        // that satisfies the condition
        if (j != -1)
        {
            // Number of elements
            // to be removed for this
            // particular case is
            // (j - i + 1)
            ans = min(ans, n - (j - i + 1));
        }
    }

    // Return answer
    return ans;
} // time complexity O(n*log(n)) space complexity O(1)
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    cout << removals(a, n,k) << endl;
    return 0;
}