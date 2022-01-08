#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int> &nums, int k)
{

    int n = nums.size();
    if (k > n)
        k = k % n;

    reverse(nums.begin(), nums.begin() + n - k);
    reverse(nums.begin() + n - k, nums.end());
    reverse(nums.begin(), nums.end());
} //O(N) O(1)
int main()
{
    return 0;
}