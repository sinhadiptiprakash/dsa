#include <bits/stdc++.h>
using namespace std;
/*
1. Make an array of all possible heights with the tower number, 
    i.e. if height of any tower is h then we will insert h+k in the array 
    and h-k(we will insert h-k in the array only if h-k ≥ 0). 
2. Sort the array.
3. Find the index upto which height of every tower is included from the starting. 
    Initialise the answer to the difference between height at this index and starting index.
4. Then with the help of two pointer technique increment the left pointer which was initially at 0 
    such that one of the tower is not included.
5. Similarly increment right pointer to make all towers included and update the answer. 
    Do this until end of the array.
*/
int minimize_the_heights(int arr[], int n, int k)
{
    //sort the array
    sort(arr, arr + n);
    // initialize the ans as the difference between highest and lowest element in the sorted array
    int ans = arr[n - 1] - arr[0];
    // from the second index i.e. the index 1 find the postion of index upto which heights of every tower is included
    int index = 1;
    // if the height at curent index is negative the index should be at the right side, so increase index
    while (arr[index] - k < 0)
        index++;
    for (; index < n; index++)
    {
        int mn = min(arr[0] + k, arr[index] - k);
        int mx = max(arr[n - 1] - k, arr[index - 1] + k);
        ans = min(mx - mn, ans);
    }
    return ans;
} //time complexity O(Nlog(N))

int main()
{
    int n, k;
    cin >> n >> k;
    int *a;
    a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << minimize_the_heights(a, n, k) << endl;
    return 0;
}