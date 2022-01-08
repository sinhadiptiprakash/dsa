#include <bits/stdc++.h>
using namespace std;
// function for checking if we can select K elements with a minimum difference of dif from the arr of N elements
// actually this function will be used inside the binary search fucntion below
bool isPossibleToSelect(int arr[], int N, int dif, int K)
{
    // at first we always select the first element in the sorted array
    int count = 1;
    // prev is the previously selected element
    // initially it is the 0 th index as we have already selected the first element
    int prev = arr[0];
    // now we will be checking wheather we can select all the other K-1 elements from the arr with minimu difference of dif
    for (int i = 1; i < N; i++)
    {
        // if the curent element is at least dif difference apart from the previously selected element
        // we select the curent element and increase the count
        if (arr[i] >= (prev + dif))
        {
            count++;
            // if we have selected all the K elements we return true
            // i.e. we can select all the K elements with a min difference of dif return true
            if (count == K)
                return true;
            // now the prev will be the curent element for the next element
            prev = arr[i];
        }
    }
    // if we can not select all the K elements with a min difference of dif return false
    return false;
}
//below binary search function optimally generate a dif between 1 and arr[N-1] as the min difference between the elements
// and checks if we can select K elements with dif as the minimum difference
// if we can select K elements with dif as the minimum difference, we try to maximize dif
// by shifting our search space from dif+1 to Right
// else we decrease dif and check i.e. we shift the search space from left to dif-1
int binarySearch(int arr[], int left, int right, int K, int N)
{
    // as we can select all the elements with a minimum difference of 1, so the ans is initialized as 1
    int ans = 1;
    while (left <= right)
    {
        int dif = left + (right - left) / 2;
        // checking if we can select all k elements with a minimum differemce of dif
        if (isPossibleToSelect(arr, N, dif, K))
        {
            // if we can select all the K elements with dif as the minimum difference
            // and if dif is greater than previous ans we update ans
            ans = max(ans, dif);
            // we further check if we can select all K elements with a minimum difference greater than dif
            // i.e. trying to maximize dif
            left = dif + 1;
        }
        // else if we can not select K elements with a minimum difference of dif
        //  we should decrease our search space
        else
            right = dif - 1;
    }
    return ans;
}
int main()
{
    int N, K;
    N = 7, K = 4;
    int arr[] = {1, 4, 9, 0, 2, 13, 3};
    // as we have discussed the arr should be in a sorted order
    sort(arr, arr + N);
    int right = arr[N - 1];
    cout << "The largest minimum difference of the " << K << " selected elements is " << endl;
    cout << binarySearch(arr, 0, right, K, N) << "\n";
    return 0;
}