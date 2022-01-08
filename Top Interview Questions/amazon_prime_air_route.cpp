// Given an array of integers sorted in ascending order, find two numbers that add up to a given target.Return the indices of the two numbers in ascending order.You can assume elements in the array are unique and there is only one solution.Do this in O(n) time and with constant auxiliary space.
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int i = 0, j = numbers.size() - 1;
        while (i < j)
        {
            int sum = numbers[i] + numbers[j];
            if (sum == target)
                return {i + 1, j + 1};
            else if (sum < target)
                i++;
            else
                j--;
        }
        return {-1, -1};
    }
};
int main()
{
    return 0;
}