//this problem is the same as the finding the next permutation
// problem link https://leetcode.com/problems/next-permutation/solution/
#include <bits/stdc++.h>
using namespace std;
//the approach is simple
//step1. scan the array from riht to left and find the first decreasing element suppose this element is at index i
//step2. scan the array from right to i and find the first element greater than array[i] let this index is j
//step3. swap element at i and j
//step4. reverse the array from i+1 to end of the array
//below function is for reversing the array from the fromPos to end of the array
void reverse(int nums[], int n, int fromPos)
{
    int i = fromPos, j = n - 1;
    while (i < j)
    {
        swap(nums[i], nums[j]);
        i++;
        j--;
    }
}
//below is the implementation of above algorithm
void next_permutation(int nums[], int n)
{
    int i = n - 2;
    //finding the first element fro(min cost so far for wrapping words from j to end)m the right side of the array
    while (i >= 0 && nums[i + 1] <= nums[i])
    {
        i--;
    }
    // finding the first element greater than the ith element from the right side
    if (i >= 0)
    {
        int j = n - 1;
        while (j >= 0 && nums[j] <= nums[i])
        {
            j--;
        }
        //swap the ith and jth elements
        swap(nums[i], nums[j]);
    }
    //reverse the whole array starting from i+1
    reverse(nums, n, i + 1);
}
int main()
{
    int nums[] = {1, 2, 3, 4};
    int n = sizeof(nums) / sizeof(int);
    next_permutation(nums, n);
    for (int i = 0; i < n; i++)
        cout << nums[i] << ' ';
    cout << endl;
    return 0;
}