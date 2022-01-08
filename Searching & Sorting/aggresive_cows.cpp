#include <bits/stdc++.h>
using namespace std;
#define lli long long int
/*
this problem is a very good example of binary search , the approach is as follows
intuition: since we have to return the largest minimum distance between cows,
we can have smallest distance as 1 and largest distance as a[n-1] in sorted array
so we select by binary search the mid of 1 and a[n-1]  in sorted array and check if we can place the cows at a minimum distance of mid
    if so then we try to check by increasing mid
if we are not able to place the cows at a minimum distance of mid, we should decrease mid
this continues in binary seach 
time complexity O(N*log(N)) as inside binary search algo we are running the is_possible_to_place_all_cows function which checks wheather
we can place all the cows at a min distace of mid in O(N ) time 
*/
int is_possible_to_place_all_cows(lli a[], int n, int dif, int c)
{
    //at first we place the first cow at 0th position
    int count = 1;
    // prev is the previously placed cow initially it is the 0 th index as we have already placed a cow there
    lli prev = a[0];
    //now we will be checking wheather we can place all the other cows at a min distance of dif
    for (int i = 1; i < n; i++)
    {
        // if the curent cow is at least dif distance apart from the prev cow we place the curent cow and increase the count
        if (a[i] >= (prev + dif))
        {
            count++;
            // if we have placed all the n cows we return true i.e. we can place all cows at a min distance of dif
            if (count == c)
                return 1;
            // now the prev will be the curent cow for the next cow
            prev = a[i];
        }
    }
    // if we cant place all the cows we should return false
    return 0;
}
//below binary search function optimally generate a number between 1 and n as the min dis between the cows
// and checks if at least this dis we can place all the cows or not
// if we can place all the cows at this minimum distance we again check by increasing mid
// else we decrease mid and check
int binary_search(lli a[], lli l, lli r, int c, int n)
{
    // as we can place all the cows at 1 distance so the ans is initialized as 1
    int ans = 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        // checking if we can place all cows at a min distance of mid
        if (is_possible_to_place_all_cows(a, n, mid, c))
        {
            // if we can place all the cows at this min distance and if mid is greater than previous ans we update ans
            ans = max(ans, mid);
            //we further check if we can place all the cows at a min distance greater than mid
            l = mid + 1;
        }
        //else if we cant place all the cows at a min distance of mid we should decrease our search space
        else
            r = mid - 1;
    }
    return ans;
}
int main()
{
    int t, n;
    lli c;
    cin >> t;
    while (t-- > 0)
    {
        cin >> n >> c;
        lli a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        if (c >= n)
            cout << n;
        else
        {
            // as an eligibility criteria of binary search we should have a sorted array
            sort(a, a + n);
            lli r = a[n - 1];
            cout << binary_search(a, 0, r, c, n) << "\n";
        }
    }
    return 0;
}