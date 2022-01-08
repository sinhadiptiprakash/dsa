#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> original;
    Solution(vector<int> &nums)
    {
        int n = nums.size();
        original.resize(n);
        for (int i = 0; i < n; i++)
            original[i] = nums[i];
        srand(time(0));
    }

    vector<int> reset()
    {
        return original;
    }

    vector<int> shuffle()
    {
        vector<int> shuffled = original;
        int n = original.size();
        while (n)
        {
            int index = rand() % n;
            swap(shuffled[index], shuffled[n - 1]);
            n--;
        }
        return shuffled;
    }
};
int main()
{
    return 0;
}