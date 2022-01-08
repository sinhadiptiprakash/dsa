#include <bits/stdc++.h>
using namespace std;
// using minHeap
int findKthLargest(vector<int> &nums, int k)
{
    int n = nums.size();
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < k; i++)
        minHeap.push(nums[i]);
    for (int i = k; i < n; i++)
    {
        if (minHeap.top() < nums[i])
        {
            minHeap.pop();
            minHeap.push(nums[i]);
        }
    }
    return minHeap.top();
}
// using Quick Select Algorithm used for QuickSort
// partition function is like the partition function in quicksort algo
// here partition function rearranges the array around the nums[high] as pivot and
// returns the index of the first element which just smaller than the pivot i.e. nums[high]
int partition(vector<int> &nums, int low, int high)
{
    int pivot = nums[high];
    int lastSmaller = low - 1, firstEqualGreater = low;
    while (firstEqualGreater < high)
    {
        if (nums[firstEqualGreater] >= pivot)
        {
            lastSmaller++;
            swap(nums[lastSmaller], nums[firstEqualGreater]);
        }
        firstEqualGreater++;
    }
    swap(nums[lastSmaller + 1], nums[high]);
    return lastSmaller + 1;
}
int findKthLargest(vector<int> &nums, int k)
{
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int pivot = partition(nums, low, high);
        if (pivot == k - 1)
            return nums[pivot];
        else if (pivot < k - 1)
            low = pivot + 1;
        else
            high = pivot - 1;
    }
    return -1;
} // TC Average O(N) worst case O(N^2) space complexity O(1)
int main()
{
    return 0;
}