#include <bits/stdc++.h>
using namespace std;
// it is Maximize Score After N Operations in leetcode
/*
You are given nums, an array of positive integers of size 2 * n. You must perform n operations on this array.
In the ith operation (1-indexed), you will:

Choose two elements, x and y.
Receive a score of i * gcd(x, y).
Remove x and y from nums.
Return the maximum score you can receive after performing n operations.

The function gcd(x, y) is the greatest common divisor of x and y.
*/
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int maxScore(vector<int> &nums)
{
    priority_queue<pair<int,pair<int,int>>> maxHeap;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int maxGcd = -1;
        for (int j = i + 1; j < n; j++)
            maxHeap.push({gcd(nums[i], nums[j]),{nums[i],nums[j]}});
    }
    int operation = n / 2;
    int sum = 0;
    unordered_set<int> visited;
    while (!maxHeap.empty() && operation)
    {
        auto temp = maxHeap.top();
        maxHeap.pop();
        int g = temp.first;
        if (visited.count(temp.second.first) < 1 && visited.count(temp.second.second) < 1)
        {
            sum += (operation * g);
            visited.insert(temp.second.first);
            visited.insert(temp.second.second);
            operation--;
        }
    }
    return sum;
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << maxScore(nums) << endl;
    return 0;
}